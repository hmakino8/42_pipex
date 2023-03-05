/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:47:36 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/03 01:46:36 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memset(void *vptr, int ch, size_t len)
{
	size_t			i;
	unsigned char	*ustr;
	unsigned char	uch;

	ustr = (unsigned char *)vptr;
	uch = (unsigned char)ch;
	i = 0;
	while (i < len)
	{
		ustr[i] = uch;
		i++;
	}
	return (vptr);
}
