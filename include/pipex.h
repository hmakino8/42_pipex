/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:08:02 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/06 01:50:32 by hiroaki          ###   ########.fr       */
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
# define PREV 0
# define CUR 1

typedef struct s_pipex_info
{
	int		stat;
	int		cmd_cnt;
	int		pipe_cnt;
	int		io_file[2];
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

/* get_info.c */
void	get_info(int argc, char *argv[], t_info *info);
void	get_cmd(char *cmd, t_info *info);

/* parse_cmd.c */
void	parse_cmd(char *cmds, t_info *info);

/* exec_cmd.c */
void	exec_cmds(char **argv, t_info *info);

/* connect_pipes.c */
void	connect_io_pipe(int i, int pipe_fd[2][2], t_info *info);
void	connect_io_file(int i, t_info *info);
void	close_io_fd(int fd[2]);

/* error_exit.c */
void	error_exit(int sig, char *str, t_info *info);
void	set_error_exit(int e);

/* pipex-helper.c */
char	*ft_readline(char *prompt);
bool	is_quotation_mark(char ch);
void	free_alloc_memory(t_info *info);

#endif
