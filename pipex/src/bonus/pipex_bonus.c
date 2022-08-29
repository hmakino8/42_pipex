/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:19:26 by hmakino           #+#    #+#             */
/*   Updated: 2022/07/03 02:43:02 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	check_args(int ac, char **av, t_pipex *px)
{
	if (ac < 5)
		return (exit_fail(ERR_ARG, NULL, px));
	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		if (ac == 5)
			return (exit_fail(ERR_ARG, NULL, px));
		px->flag_h = FLAGGED_HEREDOC;
	}
}

static void	init_pipex(t_pipex *px)
{
	px->idx = 0;
	px->locate = 0;
	px->flag_h = 0;
	px->pipe = NULL;
	px->fullpath_cmd = NULL;
	px->dev_envp = NULL;
	px->cmd = NULL;
}

static void	signal_handler(int unuse)
{
	(void)unuse;
	unlink(".heredoc");
	exit(1);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	px;

	signal(SIGINT, signal_handler);
	init_pipex(&px);
	check_args(ac, av, &px);
	get_files(ac, av, &px);
	get_paths(envp, &px);
	get_pipes(ac, &px);
	exec_pipes(av, envp, &px);
	close_pipes(&px);
	while (px.cmd_cnt--)
		waitpid(-1, NULL, 0);
	free_alloc_memory(&px);
	if (px.flag_h == FLAGGED_HEREDOC)
		unlink(".heredoc");
	return (0);
}
