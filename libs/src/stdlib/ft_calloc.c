/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:45:05 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/03 01:59:37 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*vptr;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	total = count * size;
	if (total == 0)
		total = 1;
	vptr = malloc(total);
	if (vptr == NULL)
		return (NULL);
	ft_bzero(vptr, total);
	return (vptr);
}
