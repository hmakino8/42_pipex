/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:12:25 by hiroaki           #+#    #+#             */
/*   Updated: 2022/06/20 04:26:23 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*s)
		(*f)(i++, s++);
}

//#include <stdio.h>
//
//void  f(unsigned int i, char *c)
//{
//	*c += i;
//}
//
//int main()
//{
//	char str1[] = "hdjik/,";
//	ft_striteri(str1, f);
//	printf("%s\n", str1);
//}
