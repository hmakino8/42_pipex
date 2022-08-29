/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakino <hmakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 04:37:34 by hmakino           #+#    #+#             */
/*   Updated: 2022/06/12 21:50:31 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_write_fd(const unsigned char c, t_info *i)
{
	i->total_output++;
	if (!i->check_overflow)
		return (0);
	return (write(i->fd, &c, 1));
}

unsigned long	is_neg(int n, t_info *i)
{
	long long	num;

	num = n;
	if (num < 0)
	{
		num = -num;
		i->sign = '-';
	}
	return ((unsigned long)num);
}

int	ft_atoi_dp(const char *s1, t_info *i)
{
	unsigned int	num;

	num = 0;
	while ('0' <= s1[i->idx] && s1[i->idx] <= '9' && \
			num <= (unsigned int)INT_MAX + 1)
		num = num * 10 + (s1[i->idx++] - '0');
	if ((unsigned int)INT_MAX < num)
	{
		i->overflow = 1;
		num = 0;
	}
	return ((int)num);
}

int	ft_get_digit(unsigned long num, t_info *i)
{
	int	digit;

	if (i->sign != '-' && i->flag_plus)
		i->sign = '+';
	digit = 1;
	while (i->base <= num)
	{
		num /= i->base;
		digit++;
	}
	if ((num && ((i->flag_sharp && i->spec == 'x') || \
			(i->flag_sharp && i->spec == 'X'))) || i->spec == 'p')
		digit += 2;
	return (digit);
}

unsigned char	*ft_itoa_base(unsigned long num, t_info *i)
{
	int				len;
	unsigned char	*str;

	len = ft_get_digit(num, i);
	str = (unsigned char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = num % i->base + '0';
		if ('9' < str[len])
			str[len] = num % i->base - 10 + 'a';
		if ('9' < str[len] && i->spec == 'X')
			str[len] -= ('a' - 'A');
		num /= i->base;
		i->len++;
	}	
	if ((i->flag_sharp && i->spec == 'x') || i->spec == 'p')
		str[1] = 'x';
	if (i->flag_sharp && i->spec == 'X')
		str[1] = 'X';
	if ((size_t)INT_MAX + 1 < i->prec + (0 < i->sign) + i->flag_space)
		i->overflow = 1;
	return (str);
}
