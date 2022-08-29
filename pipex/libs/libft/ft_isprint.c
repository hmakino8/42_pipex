/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:36:10 by hmakino           #+#    #+#             */
/*   Updated: 2022/03/11 00:15:49 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (' ' <= c && c <= '~');
}

// #include <stdio.h>
// #include <ctype.h>
//
// int main(void)
// {
// 	printf("***********************************\n");
// 	printf("isprint    '8': %d\n", isprint('8'));
// 	printf("ft_isprint '8': %d\n", ft_isprint('8'));
// 	printf("-----------------------------------\n");
// 	printf("isprint    'a': %d\n", isprint('a'));
// 	printf("ft_isprint 'a': %d\n", ft_isprint('a'));
// 	printf("-----------------------------------\n");
// 	printf("isprint    '*': %d\n", isprint('*'));
// 	printf("ft_isprint '*': %d\n", ft_isprint('*'));
// 	printf("-----------------------------------\n");
// 	printf("isprint    'NULL': %d\n", isprint('NULL'));
// 	printf("ft_isprint 'NULL': %d\n", ft_isprint('NULL'));
// 	printf("***********************************\n");
//
//   return(0);
// }
