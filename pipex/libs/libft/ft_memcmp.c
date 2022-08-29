/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:46:47 by hiroaki           #+#    #+#             */
/*   Updated: 2022/06/20 03:40:48 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*us1;
	unsigned const char	*us2;

	us1 = (unsigned const char *)s1;
	us2 = (unsigned const char *)s2;
	while (n--)
	{
		if (*us1 - *us2)
			return (*us1 - *us2);
		us1++;
		us2++;
	}
	return (0);
}

//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//	char  s1[] = "42tokyo-A-hmakino";
//	char  s2[] = "42tokyo-C-hmakino";
//	char  s3[] = "";
//
//	printf("***********************************\n");
//	printf("memcmp    : %d\n", memcmp(s1, s2, sizeof(s1)));
//	printf("ft_memcmp : %d\n", ft_memcmp(s1, s2, sizeof(s1)));
//	printf("-----------------------------------\n");
//	printf("memcmp    : %d\n", memcmp(s2, s2, sizeof(s1)));
//	printf("ft_memcmp : %d\n", ft_memcmp(s2, s2, sizeof(s1)));
//	printf("-----------------------------------\n");
//	printf("memcmp    : %d\n", memcmp(s2, s1, 8));
//	printf("ft_memcmp : %d\n", ft_memcmp(s2, s1, 8));
//	printf("-----------------------------------\n");
//	printf("memcmp    : %d\n", memcmp(s3, s3, sizeof(s1)));
//	printf("ft_memcmp : %d\n", ft_memcmp(s3, s3, sizeof(s1)));
//	printf("***********************************\n");
//
//	return 0;
//}
