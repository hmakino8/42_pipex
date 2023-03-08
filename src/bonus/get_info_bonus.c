/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:56:06 by hiroaki           #+#    #+#             */
/*   Updated: 2023/03/09 05:32:55 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	heredoc_to_fd(char *limiter);

void	get_io_file(char *filename, int *io_file, bool is_in, bool heredoc)
{
	if (is_in)
	{
		if (heredoc)
			*io_file = heredoc_to_fd(filename);
		else
			*io_file = open(filename, O_RDONLY);
	}
	else
		*io_file = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (*io_file < 0)
	{
		if (errno == ENOENT)
			error_exit(ERR_PATH, filename);
		else
			error_exit(0, "open");
	}
}

void	get_env(char **environ, t_info *info)
{
	if (environ == NULL)
		error_exit(ERR_ENV, NULL);
	while (1)
	{
		if (*environ == NULL)
			error_exit(ERR_PATH, info->cmd[0]);
		if (!ft_strncmp("PATH=", *environ, 5))
			break ;
		environ++;
	}
	info->env = ft_split(*environ + 5, ':');
	if (errno == ENOMEM)
		error_exit(0, "malloc");
}

void	get_cmd_path(t_info *info)
{
	char	*tmp;
	char	*cmd_path;

	if (*info->cmd == NULL || **info->cmd == '\0')
		error_exit(ERR_CMD, *info->cmd);
	tmp = NULL;
	cmd_path = NULL;
	while (*info->env)
	{
		if (ft_strchr(*info->cmd, '/') == NULL)
			tmp = ft_strjoin(*info->env, "/");
		cmd_path = ft_strjoin(tmp, *info->cmd);
		if (errno == ENOMEM)
			error_exit(0, "malloc");
		free(tmp);
		if (!access(cmd_path, 0))
			break ;
		free(cmd_path);
		cmd_path = NULL;
		info->env++;
	}
	if (cmd_path == NULL)
		error_exit(ERR_CMD, *info->cmd);
	*info->cmd = cmd_path;
}

static int	heredoc_to_fd(char *limiter)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) < 0)
		error_exit(0, "pipe");
	while (1)
	{
		line = ft_readline("heredoc> ");
		if (line == NULL || !ft_strcmp(line, limiter))
			break ;
		ft_putendl_fd(line, fd[1]);
		free(line);
	}
	free(line);
	close(fd[OUT]);
	return (fd[IN]);
}
