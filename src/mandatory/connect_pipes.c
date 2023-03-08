/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:43:01 by hiroaki           #+#    #+#             */
/*   Updated: 2023/03/09 06:26:16 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	set_stdin(int fd[2]);
static void	set_stdout(int fd[2]);

void	connect_io_pipe(int i, int pipe_cnt, int pipe_fd[2][2])
{
	if (i == 0)
		set_stdout(pipe_fd[CUR]);
	else if (i == pipe_cnt)
		set_stdin(pipe_fd[PREV]);
	else
	{
		set_stdin(pipe_fd[PREV]);
		set_stdout(pipe_fd[CUR]);
	}
}

void	connect_io_file(int i, int pipe_cnt, t_info *info)
{
	char	*infile;
	char	*outfile;
	char	*limiter;

	infile = info->agv[1];
	outfile = info->agv[info->agc -1];
	limiter = info->agv[2];
	if (i == 0)
	{
		if (info->heredoc)
			get_io_file(limiter, &info->io_file[IN], true, true);
		else
			get_io_file(infile, &info->io_file[IN], true, false);
		set_stdin(info->io_file);
	}
	if (i == pipe_cnt)
	{
		get_io_file(outfile, &info->io_file[OUT], false, false);
		set_stdout(info->io_file);
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
