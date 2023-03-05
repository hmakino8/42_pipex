/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:37:34 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/08 19:17:12 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	is_overflow(size_t	len)
{
	if (len > (size_t) INT_MAX)
	{
		errno = EOVERFLOW;
		return (true);
	}
	return (false);
}

unsigned long	is_neg(int n, int *sign)
{
	long long	num;

	num = n;
	if (num < 0)
	{
		num = -num;
		*sign = '-';
	}
	return ((unsigned long)num);
}

static int	parse_prefix(unsigned long num, t_info *info)
{
	if (info->spec == 'p')
		return ('x');
	else if (num > 0 && info->flag_sharp)
	{
		if (info->spec == 'x' || info->spec == 'X')
			return (info->spec);
	}
	return (0);
}

static int	get_digit(unsigned long num, int *prefix, t_info *info)
{
	int	digit;

	if (info->sign != '-' && info->flag_plus)
		info->sign = '+';
	digit = 1;
	while (info->base <= num)
	{
		num /= info->base;
		digit++;
	}
	*prefix = parse_prefix(num, info);
	if (*prefix > 0)
		digit += 2;
	return (digit);
}

char	*printf_itoa_base(unsigned long num, t_info *info)
{
	int		len;
	int		prefix;
	char	*str;

	len = get_digit(num, &prefix, info);
	str = calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (len--)
	{
		str[len] = num % info->base + '0';
		if ('9' < str[len])
		{
			str[len] = num % info->base - 10 + 'a';
			if (info->spec == 'X')
				str[len] = ft_toupper(str[len]);
		}
		num /= info->base;
		info->len++;
	}
	if (prefix > 0)
		str[1] = prefix;
	return (str);
}
