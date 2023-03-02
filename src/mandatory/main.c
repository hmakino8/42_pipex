/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:19:26 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/02 21:14:54 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_arg(int argc);
static void	get_info(int argc, char *argv[], t_info *info);
static void	put_usage(void);

int	main(int argc, char *argv[])
{
	t_info	info;

	check_arg(argc);
	get_info(argc, argv, &info);
	exec_cmds(argv, &info);
	free_alloc_memory(&info);
	return (info.stat);
}

static void	check_arg(int argc)
{
	if (argc == 5)
		return ;
	put_usage();
	exit(EXIT_FAILURE);
}

static void	put_usage(void)
{
	int	fd;

	fd = STDOUT_FILENO;
	ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", fd);
	ft_putendl_fd("This is equivalent in bash to:", fd);
	ft_putendl_fd("< file1 cmd1 | cmd2 > file2", fd);
}

static void	get_info(int argc, char *argv[], t_info *info)
{
	info->stat = 0;
	info->fullpath = NULL;
	info->env = NULL;
	info->cmd = NULL;
	info->cmd_cnt = argc - 3;
	info->pipe_cnt = info->cmd_cnt - 1;
	get_files(argc, argv, info);
	get_paths(info);
}

//__attribute__((destructor)) static void destructor()
//{
//	system("leaks -q pipex");
//}
