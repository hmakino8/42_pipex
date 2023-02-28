/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:26:41 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/01 03:22:23 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_files(int argc, char **argv, t_info *info)
{
	char	*infile;
	char	*outfile;

	infile = argv[1];
	outfile = argv[argc - 1];
	info->fd[IN] = open(infile, O_RDONLY);
	if (info->fd[IN] < 0)
		error_exit(0, "open", info);
	info->fd[OUT] = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (info->fd[OUT] < 0)
		error_exit(0, "open", info);
}

void	get_paths(t_info *info)
{
	extern char	**environ;
	char		**env;

	env = environ;
	if (env == NULL)
		error_exit(ERR_ENV, NULL, info);
	while (1)
	{
		if (*env == NULL)
			error_exit(ERR_PATH, NULL, info);
		if (!ft_strncmp("PATH=", *env, 5))
			break ;
		env++;
	}
	info->env = ft_split(*env + 5, ':');
	if (errno == ENOMEM)
		error_exit(0, "malloc", info);
}

void	get_pipes(int argc, t_info *info)
{
	int	i;

	info->cmd_cnt = argc - 3;
	info->pipe_cnt = 2 * (info->cmd_cnt - 1);
	info->pipe = malloc(sizeof(int) * info->pipe_cnt);
	if (errno == ENOMEM)
		return (error_exit(0, "malloc", info));
	i = 0;
	while (i < info->cmd_cnt - 1)
	{
		if (pipe(info->pipe + 2 * i) < 0)
			return (error_exit(0, "pipe", info));
		i++;
	}
}

void	get_cmd(char *cmd, t_info *info)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (info->env[i])
	{
		if (ft_strchr(cmd, '/') == NULL)
		{
			tmp = ft_strjoin(info->env[i], "/");
			if (errno == ENOMEM)
				error_exit(0, "malloc", info);
		}
		info->fullpath = ft_strjoin(tmp, cmd);
		free(tmp);
		tmp = NULL;
		if (errno == ENOMEM)
			error_exit(0, "malloc", info);
		if (!access(info->fullpath, 0))
			return ;
		free(info->fullpath);
		info->fullpath = NULL;
		i++;
	}
}
