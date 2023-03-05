/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:47:30 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/03 01:46:22 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*str1;
	const char	*str2;

	if (src == NULL && dst == NULL)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	str1 = (char *)dst;
	str2 = (const char *)src;
	while (len--)
		str1[len] = str2[len];
	return (dst);
}
