/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:19:26 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/09 00:26:10 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_info(int argc, char *argv[], t_info *info);
static void	check_arg(int argc);
static void	put_usage(void);
static void	wait_child(t_info *info);

int	main(int argc, char *argv[])
{
	t_info	info;

	check_arg(argc);
	init_info(argc, argv, &info);
	get_io_file(&info);
	exec_pipes(&info);
	wait_child(&info);
	free_double_ptr(info.env);
	return (info.stat);
}

static void	check_arg(int argc)
{
	if (argc == 5)
		return ;
	put_usage();
	exit(EXIT_FAILURE);
}

static void	init_info(int argc, char *argv[], t_info *info)
{
	info->agc = argc;
	info->agv = argv;
	info->stat = 0;
	info->cmd_cnt = argc - 3;
	info->pipe_cnt = info->cmd_cnt - 1;
	info->env = NULL;
	info->cmd[1] = NULL;
	info->cmd[2] = NULL;
}

static void	put_usage(void)
{
	int	fd;

	fd = STDOUT_FILENO;
	ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", fd);
	ft_putendl_fd("This is equivalent in bash to:", fd);
	ft_putendl_fd("< file1 cmd1 | cmd2 > file2", fd);
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
