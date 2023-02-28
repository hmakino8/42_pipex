/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:32:17 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/28 22:52:22 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	is_quotation_mark(char c)
{
	return (c == '\'' || c == '"');
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
