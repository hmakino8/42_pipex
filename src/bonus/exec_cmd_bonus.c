/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:29:23 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/06 22:04:35 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	get_cmd(char *cmd_arg, char **environ, t_info *info);
static void	exec_cmd(int i, int pipe_fd[2][2], t_info *info);
static void	switch_pipe_fd(int pipe_fd[2][2]);
static void	set_pipe(int pipe_fd[2][2]);

void	exec_pipes(t_info *info)
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
			exec_cmd(i, pipe_fd, info);
		free(info->cmd[0]);
		if (i > 0)
			close_io_fd(pipe_fd[PREV]);
		switch_pipe_fd(pipe_fd);
		i++;
	}
}

static void	exec_cmd(int i, int pipe_fd[2][2], t_info *info)
{
	extern char	**environ;

	connect_io_pipe(i, info->pipe_cnt, pipe_fd);
	connect_io_file(i, info->pipe_cnt, info);
	get_cmd(info->agv[2 + info->heredoc + i], environ, info);
	if (execve(info->cmd[0], info->cmd, environ) == -1)
		perror("execve");
	exit(EXIT_FAILURE);
}

static void	get_cmd(char *cmd_arg, char **environ, t_info *info)
{
	char	*tmp;

	tmp = ft_strchr(cmd_arg, ' ');
	if (tmp == NULL)
		info->cmd[0] = cmd_arg;
	else
	{
		cmd_arg[tmp - cmd_arg] = '\0';
		info->cmd[0] = cmd_arg;
		info->cmd[1] = tmp + 1;
	}
	get_env(environ, info);
	tmp = info->cmd[0];
	get_cmd_path(info);
	if (info->cmd[0] == NULL)
		error_exit(ERR_CMD, tmp);
	info->cmd[1] = ft_strtrim(info->cmd[1], "\'");
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
