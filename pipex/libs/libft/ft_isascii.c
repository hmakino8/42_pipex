/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:17:56 by hmakino           #+#    #+#             */
/*   Updated: 2022/06/20 03:07:00 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

//#include <stdio.h>
//#include <ctype.h>
//
//int main(void)
//{
//	printf("***********************************\n");
//	printf("isascii    'NULL': %d\n", isascii(0));
//	printf("ft_isascii 'NULL': %d\n", ft_isascii(0));
//	printf("-----------------------------------\n");
//	printf("isascii     'DEL': %d\n", isascii(127));
//	printf("ft_isascii  'DEL': %d\n", ft_isascii(127));
//	printf("-----------------------------------\n");
//	printf("isascii       '*': %d\n", isascii('*'));
//	printf("ft_isascii    '*': %d\n", ft_isascii('*'));
//	printf("-----------------------------------\n");
//	printf("isascii      '-1': %d\n", isascii(-1));
//	printf("ft_isascii   '-1': %d\n", ft_isascii(-1));
//	printf("***********************************\n");
//
//	return(0);
//}
