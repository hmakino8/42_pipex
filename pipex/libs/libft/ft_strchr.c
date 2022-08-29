/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:33:46 by hmakino           #+#    #+#             */
/*   Updated: 2022/06/24 05:55:48 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s || (!*s && !ch))
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//	char	array[] = "Hello 42!";
//
//	printf("***********************************\n");
//	printf("strchr    : %s\n", strchr(array, 'H'));
//	printf("ft_strchr : %s\n", ft_strchr(array, 'H'));
//	printf("-----------------------------------\n");
//	printf("strchr    : %s\n", strchr(array, 'A'));
//	printf("ft_strchr : %s\n", ft_strchr(array, 'A'));
//	printf("-----------------------------------\n");
//	printf("strchr    : %s\n", strchr(array, '\0'));
//	printf("ft_strchr : %s\n", ft_strchr(array, '\0'));
//	printf("***********************************\n");
//	return 0;
//}
