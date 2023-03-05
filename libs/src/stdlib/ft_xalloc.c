/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xalloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:45:05 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/03 04:09:46 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

void	*ft_error_handler(char *funcname, int e)
{
	errno = e;
	perror(funcname);
	exit(EXIT_FAILURE);
	return (0);
}

void	*ft_xcalloc(size_t count, size_t size)
{
	void	*vptr;

	vptr = ft_calloc(count, size);
	if (vptr == NULL)
		ft_error_handler("ft_xcalloc", errno);
	return (vptr);
}

void	*ft_xmalloc(size_t size)
{
	void	*vptr;

	vptr = malloc(size);
	if (vptr == NULL)
		ft_error_handler("ft_xmalloc", errno);
	return (vptr);
}

void	*ft_xrealloc(void *src, size_t size)
{
	void	*dst;

	if (src == NULL)
		return (ft_xmalloc(size));
	dst = ft_realloc(src, size);
	if (dst == NULL)
		ft_error_handler("ft_xmalloc", errno);
	return (dst);
}
