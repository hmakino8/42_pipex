/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:26:41 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/06 01:42:43 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	get_files(int argc, char **argv, t_info *info);
static void	get_path(t_info *info);

void	get_info(int argc, char *argv[], t_info *info)
{
	info->stat = 0;
	info->fullpath = NULL;
	info->env = NULL;
	info->cmd = NULL;
	info->cmd_cnt = argc - 3;
	info->pipe_cnt = info->cmd_cnt - 1;
	get_files(argc, argv, info);
	get_path(info);
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

static void	get_files(int argc, char **argv, t_info *info)
{
	char	*infile;
	char	*outfile;

	infile = argv[1];
	outfile = argv[argc - 1];
	info->io_file[0] = open(infile, O_RDONLY);
	if (info->io_file[0] < 0)
	{
		if (errno == ENOENT)
			error_exit(0, infile, info);
		error_exit(0, "open", info);
	}
	info->io_file[1] = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (info->io_file[1] < 0)
		error_exit(0, "open", info);
}

static void	get_path(t_info *info)
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
