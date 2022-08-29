/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:46:41 by hiroaki           #+#    #+#             */
/*   Updated: 2022/06/20 08:43:25 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*us;
	unsigned char		uch;

	us = (const unsigned char *)s;
	uch = (unsigned char)c;
	while (n--)
	{
		if (*us == uch)
			return ((void *)us);
		us++;
	}
	return (NULL);
}

//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//	char	array[] = "Hello 42!";
//
//	printf("***********************************\n");
//	printf("memchr    : %s\n", (char *)memchr(array, '4', 7));
//	printf("ft_memchr : %s\n", (char *)ft_memchr(array,'4', 7));
//	printf("-----------------------------------\n");
//	printf("memchr    : %s\n", (char *)memchr(array, 'o', 5));
//	printf("ft_memchr : %s\n", (char *)ft_memchr(array, 'o', 5));
//	printf("***********************************");
//	return 0;
//}
