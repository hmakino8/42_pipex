/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:08:02 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/06 03:44:06 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <stdbool.h>
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
	char	*cmd[3];
}	t_info;

enum e_err
{
	ERR_PATH = 1,
	ERR_ENV,
	ERR_CMD,
}	t_err;

/* get_info.c */
void	get_info(int argc, char *argv[], t_info *info);
void	get_env(char **env, t_info *info);
void	get_cmd(char *cmd_arg, t_info *info);
void	get_cmd_path(t_info *info);

/* exec_cmd.c */
void	exec_pipes(char **argv, t_info *info);

/* connect_pipes.c */
void	connect_io_pipe(int i, int pipe_fd[2][2], t_info *info);
void	connect_io_file(int i, t_info *info);
void	close_io_fd(int fd[2]);

/* pipex-helper.c */
char	*ft_readline(char *prompt);
void	free_double_ptr(char **d_ptr);
void	error_exit(int sig, char *str);

#endif
