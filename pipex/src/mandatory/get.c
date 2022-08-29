/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:26:41 by hmakino           #+#    #+#             */
/*   Updated: 2022/07/03 01:59:36 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	get_heredoc(char *limiter, t_pipex *px)
{
	int		cmp;
	char	*gnl;

	px->h_fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (px->h_fd < 0)
		return (exit_fail(ERR_HEREDOC, NULL, px));
	cmp = 1;
	while (cmp)
	{
		ft_dprintf(1, "%s", "heredoc> ");
		gnl = get_next_line(0);
		if (!gnl)
			break ;
		cmp = ft_strcmp_gnl(limiter, gnl);
		if (cmp)
			ft_dprintf(px->h_fd, "%s", gnl);
		free(gnl);
	}
	close(px->h_fd);
}

void	get_files(int ac, char **av, t_pipex *px)
{
	if (px->flag_h == FLAGGED_HEREDOC)
	{
		get_heredoc(av[2], px);
		px->i_fd = open(".heredoc", O_RDONLY);
		if (px->i_fd < 0)
			return (exit_fail(ERR_HEREDOC, NULL, px));
		px->o_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0000644);
		if (px->o_fd < 0)
			return (exit_fail(ERR_HEREDOC, NULL, px));
		return ;
	}
	px->i_fd = open(av[1], O_RDONLY);
	if (px->i_fd < 0)
		return (exit_fail(0, av[1], px));
	px->o_fd = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (px->o_fd < 0)
		return (exit_fail(0, av[ac - 1], px));
}

void	get_paths(char **envp, t_pipex *px)
{
	while (1)
	{
		if (!*envp)
			return (exit_fail(ERR_PATH, NULL, px));
		if (!ft_strncmp("PATH", *envp, 4))
			break ;
		envp++;
	}
	px->dev_envp = ft_split(*envp + 5, ':');
	if (!px->dev_envp)
		return (exit_fail(0, NULL, px));
}

void	get_pipes(int ac, t_pipex *px)
{
	int	i;

	if (px->flag_h == FLAGGED_HEREDOC)
		px->cmd_cnt = ac - 4;
	else
		px->cmd_cnt = ac - 3;
	px->pipe_cnt = 2 * (px->cmd_cnt - 1);
	px->pipe = malloc(sizeof(int) * px->pipe_cnt);
	if (!px->pipe)
		return (exit_fail(0, NULL, px));
	i = 0;
	while (i < px->cmd_cnt - 1)
	{
		if (pipe(px->pipe + 2 * i++) < 0)
			return (exit_fail(0, "pipe", px));
	}
}

void	get_cmd(char *cmd, t_pipex *px)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	while (px->dev_envp[++i])
	{
		if (!ft_strchr(cmd, '/'))
		{
			tmp = ft_strjoin(px->dev_envp[i], "/");
			if (!tmp)
				exit_fail(0, NULL, px);
		}
		px->fullpath_cmd = ft_strjoin(tmp, cmd);
		free(tmp);
		tmp = NULL;
		if (!px->fullpath_cmd)
			exit_fail(0, NULL, px);
		if (access(px->fullpath_cmd, 0) == 0)
			return ;
		free(px->fullpath_cmd);
		px->fullpath_cmd = NULL;
	}
}
