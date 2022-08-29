/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:57:09 by hiroaki           #+#    #+#             */
/*   Updated: 2022/06/20 04:01:24 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

//#include <stdio.h>
//#include <string.h>
//#include <fcntl.h>
//
//int main(void)
//{
//	ft_putstr_fd("ft_putstr is ok\n", 1);
//	return (0);
//}
