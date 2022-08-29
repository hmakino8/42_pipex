/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 23:27:00 by hiroaki           #+#    #+#             */
/*   Updated: 2022/06/20 04:52:58 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	cat;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize <= dlen)
		return (dstsize + slen);
	cat = (dstsize - 1) - dlen;
	if (cat > slen)
		cat = slen;
	ft_strlcpy(&dst[dlen], src, cat + 1);
	return (dlen + slen);
}

//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//	char array1[16] = "42tokyo-";
//	char array2[16] = "42tokyo-";
//
//	printf("***********************************\n");
//	printf("original len = %zu\n", strlcat(array1, "hmakino", 16));
//	printf("ft len = %zu\n", ft_strlcat(array2, "hmakino", 16));
//	printf("strlcat       : %s\n", array1);
//	printf("ft_strlcat    : %s\n", array2);
//	printf("\ncase dst NULL\n");
//	printf("original len = %zu\n", strlcat(NULL, "hmakino", 16));
//	printf("ft len = %zu\n", ft_strlcat(NULL, "hmakino", 16));
//	printf("strlcat       : %s\n", array1);
//	printf("ft_strlcat    : %s\n", array2);
//	printf("\ncase src NULL\n");
//	printf("original len = %zu\n", strlcat(array1, NULL, 16));
//	printf("ft len = %zu\n", ft_strlcat(array2, NULL, 16));
//	printf("strlcat       : %s\n", array1);
//	printf("ft_strlcat    : %s\n", array2);
//	printf("\ncase both NULL\n");
//	printf("original len = %zu\n", strlcat(NULL, NULL, 16));
//	printf("ft len = %zu\n", ft_strlcat(NULL, NULL, 16));
//	printf("strlcat       : %s\n", array1);
//	printf("ft_strlcat    : %s\n", array2);
//	printf("***********************************\n");
//	return (0);
//}
