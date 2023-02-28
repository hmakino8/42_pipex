/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:48:35 by hiroaki           #+#    #+#             */
/*   Updated: 2022/06/21 19:23:06 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

//#include <stdio.h>
//#include <ctype.h>
//
//int main(void)
//{
//	printf("********************************\n");
//	printf("toupper    'a' : %c\n", toupper('A'));
//	printf("ft_toupper 'a' : %c\n", ft_toupper('A'));
//	printf("--------------------------------\n");
//	printf("toupper    '*' : %c\n", toupper('*'));
//	printf("ft_toupper '*' : %c\n", ft_toupper('*'));
//	printf("********************************\n");
//	return (0);
//}
