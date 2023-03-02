/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:08:02 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/02 20:29:24 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

# ifndef OPEN_MAX
#  define OPEN_MAX 512
# endif

typedef struct s_pipex_info
{
	int		stat;
	int		cmd_cnt;
	int		pipe_cnt;
	int		io_file[2];
	bool	heredoc;
	char	**env;
	char	**cmd;
	char	*fullpath;
}	t_info;

enum e_err
{
	ERR_PATH = 1,
	ERR_ENV,
	ERR_CMD,
}	t_err;

/* get_info_bonus.c */
void	get_files(int argc, char **argv, t_info *info);
void	get_paths(t_info *info);
void	get_pipes(int argc, t_info *info);
void	get_cmd(char *cmd, t_info *info);

/* parse_cmd_bonus.c */
void	parse_cmd(char *cmds, t_info *info);

/* exec_cmd_bonus.c */
void	exec_cmds(char **argv, t_info *info);
void	close_io_fd(int fd[2]);

/* connect_pipes_bonus.c */
void	set_pipe(int pp[2], t_info *info);
void	connect_io_pipe(int i, int pp[OPEN_MAX / 2][2], t_info *info);
void	connect_io_file(int i, t_info *info);

/* error_exit_bonus.c */
void	error_exit(int sig, char *str, t_info *info);
void	set_error_exit(int e);

/* pipex-helper_bonus.c */
char	*ft_readline(char *prompt);
bool	is_quotation_mark(char ch);
void	free_alloc_memory(t_info *info);

#endif
