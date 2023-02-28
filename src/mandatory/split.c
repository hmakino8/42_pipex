/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:02:30 by hiroaki           #+#    #+#             */
/*   Updated: 2023/03/01 02:41:00 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	element_count(char *cmds)
{
	size_t	cnt;
	char	q_mark;

	cnt = 1;
	while (*cmds)
	{
		if (is_quotation_mark(*cmds))
		{
			q_mark = *cmds++;
			while (*cmds && *cmds != q_mark)
				cmds++;
			cmds += (*cmds != '\0');
		}
		else if (*cmds && !ft_isspace(*cmds))
		{
			while (*cmds && !ft_isspace(*cmds) && \
				!is_quotation_mark(*cmds))
				cmds++;
		}
		if (ft_isspace(*cmds))
			cnt++;
		while (*cmds && ft_isspace(*cmds))
			cmds++;
	}
	return (cnt);
}

static char	*elem_join_case_quotation(char *cmds, t_info *info)
{
	size_t	len;
	char	*tmp;
	char	q_mark;

	len = 0;
	q_mark = *cmds++;
	while (cmds[len] && cmds[len] != q_mark)
		len++;
	tmp = ft_substr(cmds, 0, len);
	info->cmd[info->idx] = ft_strjoin(info->cmd[info->idx], tmp);
	free(tmp);
	if (errno == ENOMEM)
		error_exit(0, "malloc", info);
	return (&cmds[len + 1]);
}

static char	*elem_join_case_other(char *cmds, t_info *info)
{
	size_t	len;
	char	*tmp;

	len = 0;
	while (cmds[len] && !ft_isspace(cmds[len]) && \
		!is_quotation_mark(cmds[len]))
		len++;
	tmp = ft_substr(cmds, 0, len);
	info->cmd[info->idx] = ft_strjoin(info->cmd[info->idx], tmp);
	free(tmp);
	if (errno == ENOMEM)
		error_exit(0, "malloc", info);
	return (&cmds[len]);
}

static void	element_copy(char *cmds, size_t cnt, t_info *info)
{
	info->idx = 0;
	while (*cmds && info->idx < cnt)
	{
		if (ft_isspace(*cmds))
		{
			info->idx++;
			while (*cmds && ft_isspace(*cmds))
				cmds++;
		}
		while (*cmds && !ft_isspace(*cmds))
		{
			if (is_quotation_mark(*cmds))
				cmds = elem_join_case_quotation(cmds, info);
			else if (*cmds && !ft_isspace(*cmds))
				cmds = elem_join_case_other(cmds, info);
		}
	}
}

void	split_cmds(char *cmds, t_info *info)
{
	size_t	cnt;
	size_t	i;

	if (cmds == NULL)
		return ;
	cnt = element_count(cmds);
	info->cmd = malloc(sizeof(char *) * (cnt + 1));
	if (errno == ENOMEM)
		error_exit(0, "malloc", info);
	i = 0;
	while (i < cnt)
	{
		info->cmd[i] = NULL;
		i++;
	}
	return (element_copy(cmds, cnt, info));
}
