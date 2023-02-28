/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:36:33 by hiroaki           #+#    #+#             */
/*   Updated: 2023/03/01 04:09:02 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_exit(int sig, char *str, t_info *info)
{
	int	fd;

	fd = STDERR_FILENO;
	ft_putstr_fd("pipex: ", fd);
	if (sig == ERR_PATH)
		ft_putendl_fd("invalid path", fd);
	else if (sig == ERR_ENV)
		ft_putendl_fd("invalid environment variable", fd);
	else if (sig == ERR_CMD)
	{
		ft_putstr_fd(str, fd);
		ft_putendl_fd(": command not found", fd);
	}
	else
		perror(str);
	free_alloc_memory(info);
	exit(EXIT_FAILURE);
}

void	set_error_exit(int e)
{
	if (errno == 0)
		errno = e;
	error_exit(0, NULL, NULL);
}
