/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakino <hmakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:54:21 by hmakino           #+#    #+#             */
/*   Updated: 2022/06/20 03:59:09 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	if (n < 0)
	{
		un = -n;
		ft_putchar_fd('-', fd);
	}
	else
		un = n;
	if (10 <= un)
		ft_putnbr_fd(un / 10, fd);
	ft_putchar_fd((char)(un % 10 + '0'), fd);
}

//#include <stdio.h>
//#include <string.h>
//#include <fcntl.h>
//#include <limits.h>
//
//int main(void)
//{
//	ft_putnbr_fd(INT_MAX, 1);
//	printf("\n");
//	ft_putnbr_fd(INT_MIN, 1);
//	printf("\n");
//	return (0);
//}
