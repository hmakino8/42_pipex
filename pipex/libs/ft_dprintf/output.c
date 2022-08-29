/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakino <hmakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:29:38 by hmakino           #+#    #+#             */
/*   Updated: 2022/06/12 21:30:53 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	output(unsigned char *args, t_info *i)
{
	while (!i->flag_align && !i->flag_zero && 0 < i->width--)
		ft_write_fd(' ', i);
	if (!i->spec_cs && !i->sign && i->flag_space)
		ft_write_fd(' ', i);
	if (!i->spec_cs && i->sign)
		ft_write_fd(i->sign, i);
	while ((i->has_prec < 0 && 0 < (int)i->prec--) || \
		(!i->flag_align && i->flag_zero && 0 < i->width--))
		ft_write_fd('0', i);
	while (0 < i->len--)
		ft_write_fd(*args++, i);
	while (i->flag_align && !i->flag_zero && 0 < i->width--)
		ft_write_fd(' ', i);
	while (i->flag_align && i->flag_zero && 0 < i->width--)
		ft_write_fd('0', i);
}

void	specifier_percent_c(va_list ap, t_info *i)
{
	unsigned char	*args;

	args = malloc(2);
	if (!args)
		return ;
	if (i->spec == 'c')
	{
		i->ch = va_arg(ap, int);
		if (!i->ch)
			args[0] = '\0';
	}
	if (i->spec == '%')
		i->ch = '%';
	if (i->ch)
		args[0] = i->ch;
	args[1] = '\0';
	i->len = 1;
	if (i->width)
		i->width -= (int)i->len;
	output(args, i);
	free(args);
}

void	specifier_s(va_list ap, t_info *i)
{
	unsigned char	*args;

	args = va_arg(ap, unsigned char *);
	if (!args)
		args = (unsigned char *)"(null)";
	while (args && args[i->len] && i->len <= (size_t)INT_MAX + 1 && \
			!(i->has_prec && (!i->digit_prec || !i->prec)))
		i->len++;
	if ((size_t)INT_MAX < i->len)
		i->overflow = 1;
	else
	{
		if (i->prec && i->prec < i->len)
			i->len = i->prec;
		if (i->width)
			i->width -= (int)i->len;
		output(args, i);
	}
}

void	specifier_idupx(va_list ap, t_info *i)
{
	unsigned char	*args;

	if (i->spec == 'i' || i->spec == 'd')
		args = ft_itoa_base(is_neg(va_arg(ap, int), i), i);
	if (i->spec == 'u' || i->spec == 'x' || i->spec == 'X')
		args = ft_itoa_base(va_arg(ap, unsigned int), i);
	if (i->spec == 'p')
		args = ft_itoa_base(va_arg(ap, unsigned long), i);
	if (i->flag_zero && (i->has_prec || i->flag_align))
		i->flag_zero = 0;
	if (*args == '0' && i->has_prec && (!i->digit_prec || !i->prec))
		i->len = 0;
	if (i->width && i->prec && i->len < i->prec)
		i->width -= ((int)i->prec + (0 < i->sign) + i->flag_space);
	else if (i->width)
		i->width -= (i->len + (0 < i->sign) + i->flag_space);
	if (i->len < i->prec)
	{
		i->has_prec = -1;
		i->prec -= i->len;
	}
	if (!i->overflow)
		output(args, i);
	free(args);
}
