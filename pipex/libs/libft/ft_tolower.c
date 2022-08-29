/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:48:29 by hiroaki           #+#    #+#             */
/*   Updated: 2022/06/21 19:21:42 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

//#include <stdio.h>
//#include <ctype.h>
//
//int main(void)
//{
//	printf("********************************\n");
//	printf("tolower    'Z' : %c\n", tolower('Z'));
//	printf("ft_tolower 'Z' : %c\n", ft_tolower('Z'));
//	printf("--------------------------------\n");
//	printf("tolower    '*' : %c\n", tolower('*'));
//	printf("ft_tolower '*' : %c\n", ft_tolower('*'));
//	printf("********************************\n");
//	return (0);
//}
