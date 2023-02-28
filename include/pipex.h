/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:08:02 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/01 02:41:52 by hiroaki          ###   ########.fr       */
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
# include <errno.h>
# include "libft.h"
# include "get_next_line.h"

# define IN 0
# define OUT 1

typedef struct s_pipex_info
{
	int		cmd_cnt;
	int		pipe_cnt;
	int		*pipe;
	int		fd[2];
	bool	heredoc;
	size_t	idx;
	size_t	locate;
	char	*fullpath;
	char	**env;
	char	**cmd;
}	t_info;

enum e_err
{
	ERR_PATH = 1,
	ERR_ENV,
	ERR_CMD,
}	t_err;

/* pipex.c */
void	close_pipes(t_info *info);
/* get.c */
void	get_files(int argc, char **argv, t_info *info);
void	get_paths(t_info *info);
void	get_pipes(int argc, t_info *info);
void	get_cmd(char *cmd, t_info *info);
/* split.c */
void	split_cmds(char *cmds, t_info *info);
/* exec.c */
int		exec_cmds(char **argv, t_info *info);
/* free.c */
void	free_alloc_memory(t_info *info);
/* error.c */
void	error_exit(int err_num, char *func, t_info *info);
void	set_error_exit(int e);
/* utils.c */
char	*ft_readline(char *prompt);
bool	is_quotation_mark(char c);

#endif
