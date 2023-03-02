/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-helper_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:32:17 by hiroaki           #+#    #+#             */
/*   Updated: 2023/03/02 20:31:39 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	free_double_ptr(char **d_ptr);

bool	is_quotation_mark(char ch)
{
	return (ch == '\'' || ch == '"');
}

char	*ft_readline(char *prompt)
{
	char	*line;
	char	*ret;

	ft_putstr_fd(prompt, STDERR_FILENO);
	line = get_next_line(STDIN_FILENO);
	if (line == NULL)
		return (NULL);
	ret = ft_strtrim(line, "\n");
	free(line);
	return (ret);
}

void	free_alloc_memory(t_info *info)
{
	if (info == NULL)
		return ;
	free(info->fullpath);
	if (info->env)
		free_double_ptr(info->env);
	if (info->cmd)
		free_double_ptr(info->cmd);
}

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
