/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakino <hmakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:36:46 by hmakino           #+#    #+#             */
/*   Updated: 2022/06/12 21:51:21 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void	scrape_flag(const char *s1, t_info *i)
{
	i->idx++;
	while (s1[i->idx] == '-' || s1[i->idx] == '+' || s1[i->idx] == ' ')
	{
		if (s1[i->idx] == '-')
			i->flag_align = 1;
		if (s1[i->idx] == '+')
			i->flag_plus = 1;
		if (s1[i->idx] == ' ' && !i->flag_plus)
			i->flag_space = 1;
		else
			i->flag_space = 0;
		i->idx++;
	}
	if (s1[i->idx] == '#' || i->spec == 'p')
	{
		i->flag_sharp = 1;
		i->idx++;
	}
	if (s1[i->idx] == '0')
	{
		i->flag_zero = 1;
		i->idx++;
	}
}

static void	scrape_width_prec(va_list ap, const char *s1, t_info *i)
{
	if (s1[i->idx] == '*')
	{
		i->width = va_arg(ap, int);
		i->idx++;
	}
	if ('0' <= s1[i->idx] && s1[i->idx] <= '9')
		i->width = ft_atoi_dp(s1, i);
	if (i->width)
		i->digit_width = ft_get_digit(i->width, i);
	if (!i->overflow && s1[i->idx] == '.')
	{
		i->idx++;
		i->has_prec = 1;
		if (s1[i->idx] == '*')
		{
			i->prec = va_arg(ap, int);
			i->idx++;
		}
		if ('0' <= s1[i->idx] && s1[i->idx] <= '9')
			i->prec = (size_t)ft_atoi_dp(s1, i);
		i->digit_prec = ft_get_digit(i->prec, i);
	}
}

static void	scrape_spec(va_list ap, const char *s1, t_info *i)
{
	if (s1[i->idx] == '%' || s1[i->idx] == 'c' || s1[i->idx] == 's' || \
		s1[i->idx] == 'i' || s1[i->idx] == 'd' || s1[i->idx] == 'u' || \
			s1[i->idx] == 'p' || s1[i->idx] == 'x' || s1[i->idx] == 'X')
	{
		i->spec = s1[i->idx];
		if (s1[i->idx] == '%' || s1[i->idx] == 'c' || s1[i->idx] == 's')
		{
			i->spec_cs++;
			if (s1[i->idx] == '%' || s1[i->idx] == 'c')
				specifier_percent_c(ap, i);
			else
				specifier_s(ap, i);
		}
		else
		{
			if (s1[i->idx] == 'p' || s1[i->idx] == 'x' || s1[i->idx] == 'X')
				i->base = 16;
			specifier_idupx(ap, i);
		}
		i->idx++;
	}
}

void	scrape_hub(va_list ap, const char *s1, t_info *i)
{
	while (s1[i->idx])
	{
		if (s1[i->idx] != '%')
			ft_write_fd(s1[i->idx++], i);
		else if (s1[i->idx + 1])
		{
			scrape_flag(s1, i);
			scrape_width_prec(ap, s1, i);
			if (i->overflow)
				return ;
			scrape_spec(ap, s1, i);
			initialize_info(i);
		}
	}
}
