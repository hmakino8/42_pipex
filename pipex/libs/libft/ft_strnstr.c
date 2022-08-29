/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakino <hmakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 06:12:56 by hmakino           #+#    #+#             */
/*   Updated: 2022/06/20 09:38:03 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hlen;
	size_t	nlen;
	char	*hs;

	hs = (char *)haystack;
	if (!*needle)
		return (hs);
	hlen = ft_strlen(hs);
	nlen = ft_strlen(needle);
	while (*hs && hlen-- >= nlen && nlen <= len--)
	{
		if (*hs == *needle && !ft_memcmp(hs, needle, nlen))
			return (hs);
		hs++;
	}
	return (NULL);
}

//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//	char array1[] = "42tokyo-hmakino-42tokyo";
//	char array2[] = "";
//	char array3[] = "makino";
//	char array4[] = "makino-hiroaki";
//	char array5[] = "42tokyo-hmakino-42tokyo42tokyo-hmakino-42tokyo";
//	char haystack[30] = "aaabcabcd";
//	char needle[10] = "aabc";
//
//	printf("***********************************\n");
//	printf("strnstr    : %s\n", strnstr(array1, array2, 15));
//	printf("ft_strnstr : %s\n", ft_strnstr(array1, array2, 15));
//	printf("-----------------------------------\n");
//	printf("strnstr    : %s\n", strnstr(array1, array1, 15));
//	printf("ft_strnstr : %s\n", ft_strnstr(array1, array1, 15));
//	printf("-----------------------------------\n");
//	printf("strnstr    : %s\n", strnstr(array1, array3, 15));
//	printf("ft_strnstr : %s\n", ft_strnstr(array1, array3, 15));
//	printf("-----------------------------------\n");
//	printf("strnstr    : %s\n", strnstr(array1, array3, 14));
//	printf("ft_strnstr : %s\n", ft_strnstr(array1, array3, 14));
//	printf("-----------------------------------\n");
//	printf("strnstr    : %s\n", strnstr(array1, array5, 23));
//	printf("ft_strnstr : %s\n", ft_strnstr(array1, array5, 23));
//	printf("-----------------------------------\n");
//	printf("strnstr    : %s\n", strnstr(haystack, needle, -1));
//	printf("ft_strnstr : %s\n", ft_strnstr(haystack, needle, -1));
//	printf("-----------------------------------\n");
//	printf("strnstr    : %s\n", strnstr("1", "a", 1));
//	printf("ft_strnstr : %s\n", ft_strnstr("1", "a", 1));
//	printf("-----------------------------------\n");
//	printf("strnstr    : %s\n", strnstr("22", "b", 2));
//	printf("ft_strnstr : %s\n", ft_strnstr("22", "b", 2));
//	printf("-----------------------------------\n");
//	printf("strnstr    : %s\n", strnstr("", "coucou", -1));
//	printf("ft_strnstr : %s\n", ft_strnstr("", "coucou", -1));
//	printf("-----------------------------------\n");
//	printf("strnstr    : %s\n", strnstr("123456789", "9", 8));
//	printf("ft_strnstr : %s\n", ft_strnstr("123456789", "9", 8));
//	printf("***********************************\n");
//
//	return (0);
//}
