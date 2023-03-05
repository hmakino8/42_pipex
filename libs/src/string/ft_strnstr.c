/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 06:12:56 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/07 16:38:57 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * SEGMENTATION FAULT
 * case1: str1 = NULL(except when n is 0)
 * case2: str2
*/

#include "ft_string.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t		len1;
	size_t		len2;

	if (str1 == NULL && n == 0)
		return (NULL);
	if (str2[0] == '\0' || n == 0)
		return ((char *)str1);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	while (*str1 != '\0' && len1 >= len2 && len2 <= n)
	{
		if (*str1 == *str2)
		{
			if (ft_memcmp((char *)str1, str2, len2) == 0)
				return ((char *)str1);
		}
		n--;
		len1--;
		str1++;
	}
	return (NULL);
}
