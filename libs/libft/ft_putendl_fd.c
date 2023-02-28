/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:57:21 by hiroaki           #+#    #+#             */
/*   Updated: 2022/03/09 17:40:24 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

//#include <stdio.h>
//#include <string.h>
//#include <fcntl.h>
//
//int main(void)
//{
//	char* filename = "42tokyo.txt";
//
//	int fd = open(filename, O_WRONLY);
//	if (fd == -1) {
//		perror("open");
//		exit(EXIT_FAILURE);
//	}
//
//	ft_putendl_fd(0, fd);
//
//	close(fd);
//	exit(EXIT_SUCCESS);
//}
