/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:43:01 by hiroaki           #+#    #+#             */
/*   Updated: 2023/03/06 01:50:24 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	set_stdin(int fd[2], t_info *info);
static void	set_stdout(int fd[2], t_info *info);

void	connect_io_pipe(int i, int pipe_fd[2][2], t_info *info)
{
	if (i == 0)
		set_stdout(pipe_fd[CUR], info);
	else if (i == info->pipe_cnt)
		set_stdin(pipe_fd[PREV], info);
	else
	{
		set_stdin(pipe_fd[PREV], info);
		set_stdout(pipe_fd[CUR], info);
	}
}

void	connect_io_file(int i, t_info *info)
{
	if (i == 0)
	{
		dup2(info->io_file[0], STDIN_FILENO);
		close(info->io_file[0]);
	}
	if (i == info->pipe_cnt)
	{
		dup2(info->io_file[1], STDOUT_FILENO);
		close(info->io_file[1]);
	}
}

void	close_io_fd(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}

static void	set_stdin(int fd[2], t_info *info)
{
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error_exit(0, "dup2", info);
	close_io_fd(fd);
}

static void	set_stdout(int fd[2], t_info *info)
{
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		error_exit(0, "dup2", info);
	close_io_fd(fd);
}
