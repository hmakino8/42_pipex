/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:48:09 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/06 04:06:36 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <unistd.h>
# include "ft_string.h"
# include "get_next_line.h"

ssize_t	ft_putchar(char ch);
ssize_t	ft_putchar_fd(char ch, int fd);
ssize_t	ft_putstr(char *str);
ssize_t	ft_putstr_fd(char *str, int fd);
ssize_t	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int c, int fd);

#endif
