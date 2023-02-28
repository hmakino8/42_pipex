/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:29:23 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/01 03:14:22 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_pipes(t_info *info);
static int	wait_for_child(pid_t *pid, int cnt);
static void	duplicate_fd(int i, t_info *info);
static void	child_process(char **argv, int i, t_info *info);

int	exec_cmds(char **argv, t_info *info)
{
	int		i;
	int		stat;
	pid_t	*pid;

	i = 0;
	pid = malloc(sizeof(pid_t) * info->cmd_cnt);
	while (i < info->cmd_cnt)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			error_exit(0, "fork", info);
		if (pid[i] == 0)
		{
			child_process(argv, i, info);
			return (0);
		}
		i++;
	}
	close_pipes(info);
	stat = wait_for_child(pid, info->cmd_cnt);
	free(pid);
	return (stat);
}

static void	close_pipes(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->pipe_cnt)
	{
		close(info->pipe[i]);
		i++;
	}
}

static int	wait_for_child(pid_t *pid, int cnt)
{
	int	i;
	int	stat;

	i = 0;
	while (i < cnt)
	{
		waitpid(pid[i], &stat, 0);
		i++;
	}
	return (stat > 0);
}

static void	duplicate_fd(int i, t_info *info)
{
	int	j;

	j = 2 * i - 2;
	if (i == 0)
	{
		dup2(info->fd[IN], STDIN_FILENO);
		dup2(info->pipe[1], STDOUT_FILENO);
	}
	else if (i == info->cmd_cnt - 1)
	{
		dup2(info->pipe[j], STDIN_FILENO);
		dup2(info->fd[OUT], STDOUT_FILENO);
	}
	else
	{
		dup2(info->pipe[j], STDIN_FILENO);
		dup2(info->pipe[j + 3], STDOUT_FILENO);
	}
}

static void	child_process(char **argv, int i, t_info *info)
{
	extern char	**environ;

	duplicate_fd(i, info);
	close_pipes(info);
	split_cmds(argv[2 + info->heredoc + i], info);
	if (info->cmd == NULL)
		error_exit(ERR_CMD, argv[2 + info->heredoc + i], info);
	get_cmd(info->cmd[0], info);
	if (info->fullpath == NULL)
		error_exit(ERR_CMD, info->cmd[0], info);
	if (execve(info->fullpath, info->cmd, environ) < 0)
		error_exit(0, "execve", info);
}
