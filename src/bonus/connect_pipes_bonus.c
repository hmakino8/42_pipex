/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_pipes_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:43:01 by hiroaki           #+#    #+#             */
/*   Updated: 2023/03/06 12:31:49 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	set_stdin(int fd[2]);
static void	set_stdout(int fd[2]);

void	connect_io_pipe(int i, int pipe_fd[2][2], t_info *info)
{
	if (i == 0)
		set_stdout(pipe_fd[CUR]);
	else if (i == info->pipe_cnt)
		set_stdin(pipe_fd[PREV]);
	else
	{
		set_stdin(pipe_fd[PREV]);
		set_stdout(pipe_fd[CUR]);
	}
}

void	connect_io_file(int i, t_info *info)
{
	if (i == 0)
	{
		dup2(info->io_file[IN], STDIN_FILENO);
		close(info->io_file[IN]);
	}
	if (i == info->pipe_cnt)
	{
		dup2(info->io_file[OUT], STDOUT_FILENO);
		close(info->io_file[OUT]);
	}
}

void	close_io_fd(int fd[2])
{
	close(fd[IN]);
	close(fd[OUT]);
}

static void	set_stdin(int fd[2])
{
	if (dup2(fd[IN], STDIN_FILENO) == -1)
		error_exit(0, "dup2");
	close_io_fd(fd);
}

static void	set_stdout(int fd[2])
{
	if (dup2(fd[OUT], STDOUT_FILENO) == -1)
		error_exit(0, "dup2");
	close_io_fd(fd);
}
