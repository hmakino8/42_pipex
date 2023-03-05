/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:53:13 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/02 01:38:06 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

ssize_t	ft_putchar(char ch)
{
	return (ft_putchar_fd(ch, STDOUT_FILENO));
}

ssize_t	ft_putchar_fd(char ch, int fd)
{
	return (write(fd, &ch, sizeof(char)));
}
