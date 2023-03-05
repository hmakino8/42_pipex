/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:44:45 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/07 16:53:31 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

static char	*parse_base(char *str, int *base)
{
	if (str == NULL)
		return (NULL);
	if (*base == 0 || *base == 16)
	{
		if (ft_strncmp(str, "0X", 2) == 0 || ft_strncmp(str, "0x", 2) == 0)
		{
			*base = 16;
			return (str + 2);
		}
		else if (*base == 0)
		{
			if (str[0] == '0')
			{
				*base = 8;
				return (str + 1);
			}
		}
		if (*base == 0)
			*base = 10;
	}
	else if (*base < 0 || *base == 1 || *base > 36)
		errno = EINVAL;
	return (str);
}

static int	conv_decimal_digit(char *str, char **endptr, int base)
{
	int		i;

	i = 0;
	while (i < base)
	{
		if (BASE[i] == ft_toupper(str[0]))
			return (i);
		i++;
	}
	errno = EINVAL;
	if (endptr != NULL)
		*endptr = str;
	return (-1);
}

static unsigned long	check_overflow(unsigned long num, int sign)
{
	if ((sign > 0 && num > LONG_MAX) || \
		(sign < 0 && num > (LONG_MAX + 1UL)))
		errno = ERANGE;
	return (num);
}

static long	convert_num(char *str, char **endptr, int base, int sign)
{
	int				d;
	size_t			i;
	unsigned long	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		d = conv_decimal_digit(&str[i], endptr, base);
		if (d < 0)
			return ((long)num * sign);
		num = check_overflow(num * base + d, sign);
		if (errno == ERANGE)
		{
			if (sign > 0)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		i++;
	}
	return ((long)num * sign);
}

long	ft_strtol(const char *str_val, char **endptr, int base)
{
	size_t	i;
	int		sign;
	char	*str;

	errno = 0;
	str = (char *)str_val;
	if (endptr != NULL)
		*endptr = "\0";
	str = parse_base(str, &base);
	if (errno == EINVAL || str[0] == '\0')
	{
		*endptr = str;
		return (0);
	}
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (convert_num(&str[i], endptr, base, sign));
}
