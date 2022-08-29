/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:53:13 by hiroaki           #+#    #+#             */
/*   Updated: 2022/03/09 16:57:44 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

// #include <stdio.h>
// #include <string.h>
// #include <fcntl.h>

// int main(void)
// {
//     const char* filename = "42tokyo.txt";

//     int fd = open(filename, O_WRONLY);
//     if (fd == -1) {
//         perror("open");
//         exit(EXIT_FAILURE);
//     }

//     ft_putchar_fd('!', fd);

//     close(fd);
//     exit(EXIT_SUCCESS);
// }
