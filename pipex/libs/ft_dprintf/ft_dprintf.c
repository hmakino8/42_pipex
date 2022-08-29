/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakino <hmakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:24:44 by hmakino           #+#    #+#             */
/*   Updated: 2022/06/12 21:16:27 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	initialize_info(t_info *i)
{
	i->width = 0;
	i->prec = 0;
	i->spec = 0;
	i->spec_cs = 0;
	i->base = 10;
	i->sign = 0;
	i->digit_width = 0;
	i->digit_prec = 0;
	i->flag_zero = 0;
	i->flag_align = 0;
	i->flag_plus = 0;
	i->flag_space = 0;
	i->flag_sharp = 0;
	i->has_prec = 0;
	i->len = 0;
	i->ch = 0;
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	t_info	i;

	i.fd = fd;
	i.check_overflow = 0;
	while (i.check_overflow < 2)
	{
		i.idx = 0;
		i.total_output = 0;
		i.overflow = 0;
		initialize_info(&i);
		va_start(ap, format);
		scrape_hub(ap, format, &i);
		va_end(ap);
		if (i.overflow || (size_t)INT_MAX < i.total_output)
			return (-1);
		i.check_overflow++;
	}
	return ((int)i.total_output);
}
