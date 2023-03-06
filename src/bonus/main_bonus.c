/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:19:26 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/06 21:49:40 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	init_info(int argc, char *argv[], t_info *info);
static void	check_arg(int argc, char *argv[], t_info *info);
static void	put_usage(bool heredoc);
static void	wait_child(t_info *info);

int	main(int argc, char *argv[])
{
	t_info	info;

	check_arg(argc, argv, &info);
	init_info(argc, argv, &info);
	get_io_file(&info);
	exec_pipes(&info);
	wait_child(&info);
	free_double_ptr(info.env);
	return (info.stat);
}

static void	check_arg(int argc, char *argv[], t_info *info)
{
	info->heredoc = false;
	if (argc > 1)
		info->heredoc = !ft_strcmp(argv[1], "here_doc");
	if (argc <= 5)
	{
		if (argc < 5 || (argc == 5 && info->heredoc))
		{
			put_usage(info->heredoc);
			exit(EXIT_FAILURE);
		}
	}
}

static void	init_info(int argc, char *argv[], t_info *info)
{
	info->agc = argc;
	info->agv = argv;
	info->stat = 0;
	info->cmd_cnt = argc - (3 + info->heredoc);
	info->pipe_cnt = info->cmd_cnt - 1;
	info->env = NULL;
	info->cmd[1] = NULL;
	info->cmd[2] = NULL;
}

static void	put_usage(bool heredoc)
{
	int	fd;

	fd = STDOUT_FILENO;
	if (heredoc)
	{
		ft_putendl_fd("Usage: ./pipex here_doc LIMITER cmd cmd1 file\n", fd);
		ft_putendl_fd("This is equivalent in bash to:", fd);
		ft_putendl_fd("cmd << LIMITER | cmd1 >> file", fd);
		return ;
	}
	ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n", fd);
	ft_putendl_fd("This is equivalent in bash to:", fd);
	ft_putendl_fd("< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2", fd);
}

static void	wait_child(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->cmd_cnt)
	{
		wait(&info->stat);
		if (WIFEXITED(info->stat))
			info->stat = WEXITSTATUS(info->stat);
		i++;
	}
}

//__attribute__((destructor)) static void destructor()
//{
//	system("leaks -q pipex");
//}
