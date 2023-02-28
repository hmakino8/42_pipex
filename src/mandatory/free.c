/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:28:16 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/01 02:34:07 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_double_ptr(char **d_ptr)
{
	int	i;

	i = 0;
	while (d_ptr[i])
	{
		free(d_ptr[i]);
		i++;
	}
	free(d_ptr);
}

void	free_alloc_memory(t_info *info)
{
	if (info == NULL)
		return ;
	free(info->pipe);
	free(info->fullpath);
	if (info->env)
		free_double_ptr(info->env);
	if (info->cmd)
		free_double_ptr(info->cmd);
}
