/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:44:57 by hiroaki           #+#    #+#             */
/*   Updated: 2022/06/20 02:20:29 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//	char	array[] = "XXXHello 42!";
//	char	array2[] = "XXXHello 42!";
//
//	printf("***********************************\n");
//	bzero(array, 3);
//	ft_bzero(array2, 3);
//	printf("bzero    : %s\n", &array[0]);
//	printf("ft_bzero : %s\n", &array2[0]);
//	printf("-----------------------------------\n");
//	printf("bzero    : %s\n", &array[1]);
//	printf("ft_bzero : %s\n", &array2[1]);
//	printf("-----------------------------------\n");
//	printf("bzero    : %s\n", &array[2]);
//	printf("ft_bzero : %s\n", &array2[2]);
//	printf("-----------------------------------\n");
//	printf("bzero    : %s\n", &array[3]);
//	printf("ft_bzero : %s\n", &array2[3]);
//	printf("***********************************\n");
//	return 0;
// }
