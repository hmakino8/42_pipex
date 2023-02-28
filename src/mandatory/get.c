/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:26:41 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/01 02:46:08 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	heredoc_to_fd(char *limiter, t_info *info)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) < 0)
		error_exit(0, "pipe", info);
	while (1)
	{
		line = ft_readline("heredoc> ");
		if (line == NULL || !ft_strcmp(line, limiter))
			break ;
		ft_putendl_fd(line, fd[1]);
		free(line);
	}
	free(line);
	close(fd[1]);
	return (fd[0]);
}

void	get_files(int argc, char **argv, t_info *info)
{
	char	*infile;
	char	*outfile;
	char	*limiter;

	infile = argv[1];
	outfile = argv[argc - 1];
	limiter = argv[2];
	if (info->heredoc)
	{
		info->fd[IN] = heredoc_to_fd(limiter, info);
		info->fd[OUT] = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (info->fd[OUT] < 0)
			error_exit(0, "open", info);
		return ;
	}
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

	info->cmd_cnt = argc - (3 + info->heredoc);
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
