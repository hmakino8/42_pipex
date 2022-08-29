/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:08:02 by hmakino           #+#    #+#             */
/*   Updated: 2022/07/03 02:28:00 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <signal.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <sys/types.h>

# include "../../libs/libft/libft.h"
# include "../../libs/gnl/get_next_line.h"
# include "../../libs/ft_dprintf/ft_dprintf.h"

typedef struct s_pipex
{
	int		i_fd;
	int		o_fd;
	int		h_fd;
	int		flag_h;
	int		cmd_cnt;
	int		pipe_cnt;
	int		*pipe;
	size_t	idx;
	size_t	locate;
	char	*fullpath_cmd;
	char	**dev_envp;
	char	**cmd;
}	t_pipex;

enum
{
	ERR_ARG = 1,
	ERR_CMD,
	ERR_PIPE,
	ERR_PATH,
	ERR_HEREDOC,
	FLAGGED_HEREDOC,
};

/*
 * pipex.c
 */
void	close_pipes(t_pipex *px);
/*
 * get.c
 */
void	get_files(int ac, char **av, t_pipex *px);
void	get_paths(char **envp, t_pipex *px);
void	get_pipes(int ac, t_pipex *px);
void	get_cmd(char *cmd, t_pipex *px);
/*
 * split.c
 */
void	split_cmds(char *cmds, t_pipex *px);
/*
 * exec.c
 */
void	exec_pipes(char **av, char **envp, t_pipex *px);
/*
 * free.c
 */
void	free_alloc_memory(t_pipex *px);
/*
 * error.c
 */
void	exit_fail(int err_num, char *err, t_pipex *px);
/*
 * utils.c
 */
int		is_quotation_mark(char c);
int		ft_strcmp_gnl(const char *lmt, const char *gnl);

#endif
