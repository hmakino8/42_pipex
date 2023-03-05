/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-buffering.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:29:38 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/08 19:24:48 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	buffering(char *str, int fd, t_info *info)
{
	size_t	len;

	len = 0;
	while (!info->flag_align && !info->flag_zero && 0 < info->width--)
		len += ft_putchar_fd(' ', fd);
	if (!info->spec_cs)
	{
		if (info->sign)
			len += ft_putchar_fd(info->sign, fd);
		else if (info->flag_space)
			len += ft_putchar_fd(' ', fd);
	}
	while ((info->has_prec < 0 && 0 < (int)info->prec--) || \
		(!info->flag_align && info->flag_zero && 0 < info->width--))
		len += ft_putchar_fd('0', fd);
	while (0 < info->len--)
		len += ft_putchar_fd(*str++, fd);
	while (info->flag_align && 0 < info->width--)
	{
		if (info->flag_zero)
			len += ft_putchar_fd('0', fd);
		else
			len += ft_putchar_fd(' ', fd);
	}
	return (len);
}

static char	*spec_pct_c(char *str, va_list ap, t_info *info)
{
	str = ft_calloc(2, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (info->spec == 'c')
		str[0] = va_arg(ap, int);
	else
		str[0] = '%';
	info->len = 1;
	if (info->width > 0)
		info->width -= (int)info->len;
	return (str);
}

static char	*spec_s(char *str, va_list ap, t_info *info)
{
	str = va_arg(ap, char *);
	if (str == NULL)
		str = (char *)"(null)";
	if (!(info->has_prec && (!info->digit_prec || !info->prec)))
		info->len = ft_strlen((char *)str);
	if (info->len <= INT_MAX)
	{
		if (info->prec > 0 && info->prec < info->len)
			info->len = info->prec;
		if (info->width > 0)
			info->width -= (int)info->len;
	}
	return (ft_strdup(str));
}

static char	*spec_i_d_u_p_x(char *str, va_list ap, t_info *info)
{
	if (ft_strchr("id", info->spec))
		str = printf_itoa_base(is_neg(va_arg(ap, int), &info->sign), info);
	if (ft_strchr("uxX", info->spec))
		str = printf_itoa_base(va_arg(ap, unsigned int), info);
	if (info->spec == 'p')
		str = printf_itoa_base(va_arg(ap, unsigned long), info);
	if (info->flag_zero && (info->has_prec || info->flag_align))
		info->flag_zero = 0;
	if (*str == '0' && info->has_prec && (!info->digit_prec || !info->prec))
		info->len = 0;
	if (info->width > 0)
	{
		info->width -= (0 < info->sign) + info->flag_space;
		if (info->prec && info->len < info->prec)
			info->width -= (int)info->prec;
		else
			info->width -= info->len;
	}
	if (info->len < info->prec)
	{
		info->has_prec = -1;
		info->prec -= info->len;
	}
	return (str);
}

size_t	buf_to_fd(va_list ap, int fd, size_t bufsize, t_info *info)
{
	size_t	len;
	char	*str;

	str = NULL;
	if (!ft_strchr("%csidupxX", info->spec))
		return (0);
	if (info->spec == '%' || info->spec == 'c')
		str = spec_pct_c(str, ap, info);
	else if (info->spec == 's')
		str = spec_s(str, ap, info);
	else
		str = spec_i_d_u_p_x(str, ap, info);
	if (str == NULL)
		return (0);
	if (bufsize + info->len > (size_t) INT_MAX)
		len = info->len;
	else
		len = buffering(str, fd, info);
	ft_free((void **)&str);
	return (len);
}
