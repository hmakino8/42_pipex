/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:29:23 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/06 03:45:07 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd(char *cmd_arg, t_info *info);
static void	switch_pipe_fd(int pipe_fd[2][2]);
static void	set_pipe(int pipe_fd[2][2]);

void	exec_pipes(char **argv, t_info *info)
{
	int		i;
	int		pipe_fd[2][2];
	pid_t	pid;

	i = 0;
	while (i < info->cmd_cnt)
	{
		if (i != info->pipe_cnt)
			set_pipe(pipe_fd);
		pid = fork();
		if (pid == -1)
			error_exit(0, "fork");
		if (pid == 0)
		{
			connect_io_pipe(i, pipe_fd, info);
			connect_io_file(i, info);
			exec_cmd(argv[2 + i], info);
		}
		free(info->cmd[0]);
		if (i > 0)
			close_io_fd(pipe_fd[PREV]);
		switch_pipe_fd(pipe_fd);
		i++;
	}
}

static void	exec_cmd(char *cmd_arg, t_info *info)
{
	char		*tmp;
	extern char	**environ;

	info->cmd[1] = NULL;
	info->cmd[2] = NULL;
	get_cmd(cmd_arg, info);
	get_env(environ, info);
	tmp = info->cmd[0];
	get_cmd_path(info);
	if (info->cmd[0] == NULL)
		error_exit(ERR_CMD, tmp);
	info->cmd[1] = ft_strtrim(info->cmd[1], "\'");
	if (execve(info->cmd[0], info->cmd, environ) == -1)
		perror("execve");
	exit(EXIT_FAILURE);
}

static void	switch_pipe_fd(int pipe_fd[2][2])
{
	pipe_fd[PREV][IN] = pipe_fd[CUR][IN];
	pipe_fd[PREV][OUT] = pipe_fd[CUR][OUT];
}

static void	set_pipe(int pipe_fd[2][2])
{
	if (pipe(pipe_fd[CUR]) == -1)
		error_exit(0, "pipe");
}
