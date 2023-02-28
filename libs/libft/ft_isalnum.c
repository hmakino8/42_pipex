/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:38:46 by hmakino           #+#    #+#             */
/*   Updated: 2022/03/11 00:15:19 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

//#include <stdio.h>
//#include <ctype.h>
//
//int main(void)
//{
//	printf("***********************************\n");
//	printf("isalnum    'a': %d\n", isalnum('a'));
//	printf("ft_isalnum 'a': %d\n", ft_isalnum('a'));
//	printf("-----------------------------------\n");
//	printf("isalnum    'Z': %d\n", isalnum('Z'));
//	printf("ft_isalnum 'Z': %d\n", ft_isalnum('Z'));
//	printf("-----------------------------------\n");
//	printf("isalnum    '0': %d\n", isalnum('0'));
//	printf("ft_isalnum '0': %d\n", ft_isalnum('0'));
//	printf("-----------------------------------\n");
//	printf("isalnum    '9': %d\n", isalnum('9'));
//	printf("ft_isalnum '9': %d\n", ft_isalnum('9'));
//	printf("-----------------------------------\n");
//	printf("isalnum    '*': %d\n", isalnum('*'));
//	printf("ft_isalnum '*': %d\n", ft_isalnum('*'));
//	printf("***********************************\n");
//
//	return(0);
//}
