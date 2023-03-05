/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:36:46 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/08 19:16:27 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*conv_to_width(const char *fmt, int *width, int *len)
{
	while (ft_isdigit(*fmt))
	{
		*width = *width * 10 + (*fmt++ - '0');
		(*len)++;
	}
	return (fmt);
}

static const char	*conv_to_prec(const char *fmt, size_t *prec, int *len)
{
	while (ft_isdigit(*fmt))
	{
		*prec = *prec * 10 + (*fmt++ - '0');
		(*len)++;
	}
	return (fmt);
}

const char	*parse_flag(const char *fmt, t_info *info)
{
	while (ft_strchr("-+ ", *fmt))
	{
		if (*fmt == '-')
			info->flag_align = 1;
		if (*fmt == '+')
			info->flag_plus = 1;
		if (*fmt == ' ' && !info->flag_plus)
			info->flag_space = 1;
		else
			info->flag_space = 0;
		fmt++;
	}
	if (*fmt == '#' || info->spec == 'p')
	{
		info->flag_sharp = 1;
		fmt++;
	}
	if (*fmt == '0')
	{
		info->flag_zero = 1;
		fmt++;
	}
	return (fmt);
}

const char	*parse_width_prec(va_list ap, const char *fmt, t_info *info)
{
	if (*fmt == '*')
	{
		info->width = va_arg(ap, int);
		fmt++;
	}
	fmt = conv_to_width(fmt, &info->width, &info->digit_width);
	if (*fmt == '.')
	{
		fmt++;
		info->has_prec = 1;
		if (*fmt == '*')
		{
			info->prec = va_arg(ap, int);
			fmt++;
		}
		fmt = conv_to_prec(fmt, &info->prec, &info->digit_prec);
		if (info->digit_prec == 0)
			info->digit_prec++;
	}
	return (fmt);
}

const char	*parse_spec(const char *fmt, t_info *info)
{
	if (!ft_strchr("%csidupxX", *fmt))
		return (fmt);
	info->spec = *fmt;
	if (ft_strchr("%cs", *fmt))
		info->spec_cs++;
	else if (ft_strchr("pxX", *fmt))
		info->base = 16;
	return (fmt);
}
