/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:45:05 by hiroaki           #+#    #+#             */
/*   Updated: 2022/06/21 19:43:52 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	alloc_size;
	void	*ret;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	alloc_size = count * size;
	if (!alloc_size)
		alloc_size = 1;
	ret = malloc(alloc_size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, alloc_size);
	return (ret);
}
