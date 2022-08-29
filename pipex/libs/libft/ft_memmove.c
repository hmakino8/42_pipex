/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:47:30 by hiroaki           #+#    #+#             */
/*   Updated: 2022/06/21 19:26:21 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cdst;
	const char	*csrc;

	if (!src && !dst)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	cdst = (char *)dst;
	csrc = (const char *)src;
	while (len--)
		*(cdst + len) = *(csrc + len);
	return (dst);
}

//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//	char	sResult[] = {67, 68, 67, 68, 69, 0, 45};
//	char	sResult2[] = {67, 67, 68, 68, 69, 0, 45};
//	char	sResult3[] = {67, 68, 67, 68, 69, 0, 45};
//	char	sResult4[] = {67, 67, 68, 68, 69, 0, 45};
//	char	array[] = "Hello 42! XXXXX hmakino!";
//	char	array2[] = "Hello 42! XXXXX hmakino!";
//
//	printf("***********************************\n");
//	memmove(sResult + 1, sResult, 2);
//	ft_memmove(sResult3 + 1, sResult3, 2);
//	printf("memmove    : %s\n", sResult);
//	printf("ft_memmove : %s\n", sResult3);
//	memmove(array + 10, array, 5);
//	ft_memmove(array2 + 10, array2, 5);
//	printf("memmove    : %s\n", array);
//	printf("ft_memmove : %s\n", array2);
//	printf("***********************************\n");
//	return 0;
//}
