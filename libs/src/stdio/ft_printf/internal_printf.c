/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:24:44 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/08 19:00:21 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_info(t_info *info)
{
	info->width = 0;
	info->prec = 0;
	info->spec = 0;
	info->spec_cs = 0;
	info->base = 10;
	info->sign = 0;
	info->digit_width = 0;
	info->digit_prec = 0;
	info->flag_zero = 0;
	info->flag_align = 0;
	info->flag_plus = 0;
	info->flag_space = 0;
	info->flag_sharp = 0;
	info->has_prec = 0;
	info->len = 0;
}

static int	creat_buf_fd(int *fd)
{
	int			e;
	struct stat	st;

	e = errno;
	stat(BUF, &st);
	if (errno != ENOENT)
	{
		errno = EEXIST;
		return (-1);
	}
	errno = e;
	*fd = open(BUF, O_CREAT | O_RDWR, 0644);
	if (*fd < 0)
		return (-1);
	return (0);
}

ssize_t	internal_printf(int *fd, const char *fmt, va_list ap)
{
	size_t	bufsize;
	t_info	info;

	if (creat_buf_fd(fd) < 0)
		return (EOF);
	bufsize = 0;
	while (*fmt)
	{
		init_info(&info);
		if (*fmt != '%')
			bufsize += ft_putchar_fd(*fmt, *fd);
		else if (*fmt)
		{
			fmt++;
			fmt = parse_flag(fmt, &info);
			fmt = parse_width_prec(ap, fmt, &info);
			fmt = parse_spec(fmt, &info);
			bufsize += buf_to_fd(ap, *fd, bufsize, &info);
			if (is_overflow(bufsize) || errno == ENOMEM)
				return (EOF);
		}
		fmt++;
	}
	close(*fd);
	return (bufsize);
}
