/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:32:17 by hiroaki           #+#    #+#             */
/*   Updated: 2022/07/03 02:27:43 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_quotation_mark(char c)
{
	return (c == '\'' || c == '"');
}

int	ft_strcmp_gnl(const char *lmt, const char *gnl)
{
	const unsigned char	*ulmt;
	const unsigned char	*ugnl;

	ulmt = (const unsigned char *)lmt;
	ugnl = (const unsigned char *)gnl;
	while (1)
	{
		if (!*ulmt && *ugnl == '\n')
			break ;
		if (*ulmt != *ugnl)
			return (*ulmt - *ugnl);
		ulmt++;
		ugnl++;
	}
	return (0);
}
