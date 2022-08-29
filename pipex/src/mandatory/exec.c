/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:29:23 by hmakino           #+#    #+#             */
/*   Updated: 2022/06/28 02:31:32 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(t_pipex *px)
{
	int	i;

	i = 0;
	while (i < px->pipe_cnt)
		close(px->pipe[i++]);
}

static void	duplicate_fd(int idx, t_pipex *px)
{
	int	i;

	i = 2 * idx - 2;
	if (idx == 0)
	{
		dup2(px->i_fd, 0);
		dup2(px->pipe[1], 1);
	}
	else if (idx == px->cmd_cnt - 1)
	{
		dup2(px->pipe[i], 0);
		dup2(px->o_fd, 1);
	}
	else
	{
		dup2(px->pipe[i], 0);
		dup2(px->pipe[i + 3], 1);
	}
}

static void	child_process(char **av, char **envp, int i, t_pipex *px)
{
	duplicate_fd(i, px);
	close_pipes(px);
	if (px->flag_h == FLAGGED_HEREDOC)
		split_cmds(av[3 + i], px);
	else
		split_cmds(av[2 + i], px);
	if (!px->cmd)
		exit_fail(0, NULL, px);
	get_cmd(px->cmd[0], px);
	if (!px->fullpath_cmd)
		exit_fail(ERR_CMD, px->cmd[0], px);
	if (execve(px->fullpath_cmd, px->cmd, envp) < 0)
		exit_fail(0, "execve", px);
	exit(EXIT_SUCCESS);
}

void	exec_pipes(char **av, char **envp, t_pipex *px)
{
	int		i;
	pid_t	pid;

	i = -1;
	while (++i < px->cmd_cnt)
	{
		pid = fork();
		if (pid < 0)
			exit_fail(0, "fork", px);
		if (!pid)
			child_process(av, envp, i, px);
	}
}
