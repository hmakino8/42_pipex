/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:08:02 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/09 06:27:34 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

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
	int		agc;
	bool	heredoc;
	char	**agv;
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
void	get_io_file(char *filename, int *io_file, bool is_in, bool heredoc);
void	get_env(char **env, t_info *info);
void	get_cmd_path(t_info *info);

/* exec_cmd.c */
void	exec_pipes(t_info *info);

/* connect_pipes.c */
void	connect_io_pipe(int i, int pipe_cnt, int pipe_fd[2][2]);
void	connect_io_file(int i, int pipe_cnt, t_info *info);
void	close_io_fd(int fd[2]);

/* pipex-helper.c */
char	*ft_readline(char *prompt);
void	free_double_ptr(char **d_ptr);
void	error_exit(int sig, char *str);

#endif
