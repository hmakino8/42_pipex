/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:46:47 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/03 01:46:09 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_memcmp(const void *vptr1, const void *vptr2, size_t n)
{
	size_t				i;
	int					diff;
	unsigned const char	*us1;
	unsigned const char	*us2;

	us1 = (unsigned const char *)vptr1;
	us2 = (unsigned const char *)vptr2;
	i = 0;
	diff = 0;
	while (i < n)
	{
		diff = us1[i] - us2[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}
