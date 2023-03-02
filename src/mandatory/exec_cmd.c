/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:29:23 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/02 21:12:47 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void		close_io_fd(int fd[2]);
static void	exec_pipes(char **argv, int i, t_info *info);

void	exec_cmds(char **argv, t_info *info)
{
	int		i;
	int		pp[OPEN_MAX / 2][2];
	pid_t	pid;

	i = 0;
	while (i < info->cmd_cnt)
	{
		if (i != info->pipe_cnt)
			set_pipe(pp[i], info);
		pid = fork();
		if (pid == -1)
			error_exit(0, "fork", info);
		if (pid == 0)
		{
			connect_io_pipe(i, pp, info);
			connect_io_file(i, info);
			exec_pipes(argv, i, info);
		}
		if (i > 0)
			close_io_fd(pp[i - 1]);
		wait(&info->stat);
		i++;
	}
	info->stat = info->stat >> 8;
}

void	close_io_fd(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
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
