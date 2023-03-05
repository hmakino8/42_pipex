/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:19:26 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/06 03:32:41 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_arg(int argc);
static void	put_usage(void);
static void	wait_child(t_info *info);

int	main(int argc, char *argv[])
{
	t_info	info;

	check_arg(argc);
	get_info(argc, argv, &info);
	exec_pipes(argv, &info);
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
