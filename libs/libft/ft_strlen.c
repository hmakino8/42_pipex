/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:15:26 by hmakino           #+#    #+#             */
/*   Updated: 2022/03/10 23:17:01 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//	char array1[] = "42tokyo-hmakino-42tokyo";
//	char array2[] = "";
//
//	printf("***********************************\n");
//	printf("strlen    : %lu\n", strlen(array1));
//	printf("ft_strlen : %lu\n", ft_strlen(array1));
//	printf("***********************************\n");
//	printf("strlen    : %lu\n", strlen(array2));
//	printf("ft_strlen : %lu\n", ft_strlen(array2));
//	printf("***********************************\n");
//	return (0);
//}
