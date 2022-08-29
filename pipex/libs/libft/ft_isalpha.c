/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:56:24 by hmakino           #+#    #+#             */
/*   Updated: 2022/03/11 00:15:31 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

//#include <stdio.h>
//#include <ctype.h>
//
//int main(void)
//{
//	printf("***********************************\n");
//	printf("isalpha    'a': %d\n", isalpha('a'));
//	printf("ft_isalpha 'a': %d\n", ft_isalpha('a'));
//	printf("-----------------------------------\n");
//	printf("isalpha    'Z': %d\n", isalpha('Z'));
//	printf("ft_isalpha 'Z': %d\n", ft_isalpha('Z'));
//	printf("-----------------------------------\n");
//	printf("isalpha    '0': %d\n", isalpha('0'));
//	printf("ft_isalpha '0': %d\n", ft_isalpha('0'));
//	printf("-----------------------------------\n");
//	printf("isalpha    '*': %d\n", isalpha('*'));
//	printf("ft_isalpha '*': %d\n", ft_isalpha('*'));
//	printf("***********************************\n");
//
//	return(0);
//}
