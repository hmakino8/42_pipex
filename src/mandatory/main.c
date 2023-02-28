/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:19:26 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/01 02:46:25 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_arg(int argc, char *argv[])
{
	if (argc < 5 || (!ft_strcmp(argv[1], "here_doc") && argc == 5))
		set_error_exit(EINVAL);
}

static void	get_info(int argc, char *argv[], t_info *info)
{
	info->idx = 0;
	info->locate = 0;
	info->pipe = NULL;
	info->fullpath = NULL;
	info->env = NULL;
	info->cmd = NULL;
	info->heredoc = !ft_strcmp(argv[1], "here_doc");
	get_files(argc, argv, info);
	get_paths(info);
	get_pipes(argc, info);
}

int	main(int argc, char *argv[])
{
	int		stat;
	t_info	info;

	check_arg(argc, argv);
	get_info(argc, argv, &info);
	stat = exec_cmds(argv, &info);
	free_alloc_memory(&info);
	return (stat);
}

//__attribute__((destructor)) static void destructor()
//{
//	system("leaks -q pipex");
//}
