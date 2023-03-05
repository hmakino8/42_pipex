/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:29:23 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/06 01:49:48 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_pipes(char **argv, int i, t_info *info);
static void	switch_pipe_fd(int pipe_fd[2][2]);
static void	set_pipe(int pipe_fd[2][2], t_info *info);

void	exec_cmds(char **argv, t_info *info)
{
	int		i;
	int		pipe_fd[2][2];
	pid_t	pid;

	i = 0;
	while (i < info->cmd_cnt)
	{
		if (i != info->pipe_cnt)
			set_pipe(pipe_fd, info);
		pid = fork();
		if (pid == -1)
			error_exit(0, "fork", info);
		if (pid == 0)
		{
			connect_io_pipe(i, pipe_fd, info);
			connect_io_file(i, info);
			exec_pipes(argv, i, info);
		}
		if (i > 0)
			close_io_fd(pipe_fd[PREV]);
		switch_pipe_fd(pipe_fd);
		i++;
	}
}

static void	exec_pipes(char **argv, int i, t_info *info)
{
	extern char	**environ;

	parse_cmd(argv[2 + i], info);
	if (info->cmd == NULL)
		error_exit(ERR_CMD, argv[2 + i], info);
	get_cmd(info->cmd[0], info);
	if (info->fullpath == NULL)
		error_exit(ERR_CMD, info->cmd[0], info);
	if (execve(info->fullpath, info->cmd, environ) < 0)
		perror("execve");
	exit(EXIT_FAILURE);
}

static void	switch_pipe_fd(int pipe_fd[2][2])
{
	pipe_fd[PREV][IN] = pipe_fd[CUR][IN];
	pipe_fd[PREV][OUT] = pipe_fd[CUR][OUT];
}

static void	set_pipe(int pipe_fd[2][2], t_info *info)
{
	if (pipe(pipe_fd[CUR]) == -1)
		error_exit(0, "pipe", info);
}
