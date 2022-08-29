/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:26:30 by hmakino           #+#    #+#             */
/*   Updated: 2022/03/11 00:15:41 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

// #include <stdio.h>
// #include <ctype.h>
//
// int main(void)
// {
// 	printf("***********************************\n");
// 	printf("isdigit    '8': %d\n", isdigit('8'));
// 	printf("ft_isdigit '8': %d\n", ft_isdigit('8'));
// 	printf("-----------------------------------\n");
// 	printf("isdigit    'a': %d\n", isdigit('a'));
// 	printf("ft_isdigit 'a': %d\n", ft_isdigit('a'));
// 	printf("-----------------------------------\n");
// 	printf("isdigit    '*': %d\n", isdigit('*'));
// 	printf("ft_isdigit '*': %d\n", ft_isdigit('*'));
// 	printf("-----------------------------------\n");
// 	printf("isdigit    'NULL': %d\n", isdigit('NULL'));
// 	printf("ft_isdigit 'NULL': %d\n", ft_isdigit('NULL'));
// 	printf("***********************************\n");
//
//   return(0);
// }
