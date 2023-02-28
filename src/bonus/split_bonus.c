/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:02:30 by hiroaki           #+#    #+#             */
/*   Updated: 2022/07/03 02:43:32 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
			cmds++;
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

static char	*elem_join_case_quotation(char *cmds, t_pipex *px)
{
	size_t	len;
	char	*tmp;
	char	q_mark;

	len = 0;
	q_mark = *cmds++;
	while (cmds[len] && cmds[len] != q_mark)
		len++;
	tmp = ft_substr(cmds, 0, len);
	if (!tmp)
		exit_fail(0, NULL, px);
	px->cmd[px->idx] = ft_strjoin(px->cmd[px->idx], tmp);
	free(tmp);
	if (!px->cmd[px->idx])
		exit_fail(0, NULL, px);
	return (cmds + len + 1);
}

static char	*elem_join_case_other(char *cmds, t_pipex *px)
{
	size_t	len;
	char	*tmp;

	len = 0;
	while (cmds[len] && !ft_isspace(cmds[len]) && \
		!is_quotation_mark(cmds[len]))
		len++;
	tmp = ft_substr(cmds, 0, len);
	if (!tmp)
		exit_fail(0, NULL, px);
	px->cmd[px->idx] = ft_strjoin(px->cmd[px->idx], tmp);
	free(tmp);
	if (!px->cmd[px->idx])
		exit_fail(0, NULL, px);
	return (cmds + len);
}

static void	element_copy(char *cmds, size_t cnt, t_pipex *px)
{
	px->idx = 0;
	while (*cmds && px->idx < cnt)
	{
		if (ft_isspace(*cmds))
		{
			px->idx++;
			while (*cmds && ft_isspace(*cmds))
				cmds++;
		}
		while (*cmds && !ft_isspace(*cmds))
		{
			if (is_quotation_mark(*cmds))
				cmds = elem_join_case_quotation(cmds, px);
			else if (*cmds && !ft_isspace(*cmds))
				cmds = elem_join_case_other(cmds, px);
		}
	}
}

void	split_cmds(char *cmds, t_pipex *px)
{
	size_t	cnt;

	if (!cmds)
		return ;
	cnt = element_count(cmds);
	px->cmd = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!px->cmd)
		exit_fail(0, NULL, px);
	px->cmd[cnt + 1] = NULL;
	return (element_copy(cmds, cnt, px));
}
