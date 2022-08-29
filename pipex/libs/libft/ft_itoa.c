/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 09:01:40 by hiroaki           #+#    #+#             */
/*   Updated: 2022/06/21 19:29:11 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digit_cnt(long ln)
{
	size_t	digit;

	digit = 1;
	while (10 <= ln)
	{
		ln /= 10;
		digit++;
	}
	return (digit);
}

static char	*putnum_in_array(long ln, char *ret, size_t len, size_t isneg)
{
	while (isneg < len--)
	{
		ret[len] = (char)(ln % 10 + '0');
		ln /= 10;
	}
	if (isneg)
		ret[0] = '-';
	return (ret);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	isneg;
	long	ln;
	char	*ret;

	ln = (long)n;
	isneg = (ln < 0);
	if (isneg)
		ln *= -1;
	len = digit_cnt(ln) + isneg;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	return (putnum_in_array(ln, ret, len, isneg));
}

//#include <stdio.h>
//
//int main(void)
//{
//	printf("INT_MAX : %s\n", ft_itoa(INT_MAX));
//	printf("INT_MIN : %s\n", ft_itoa(INT_MIN));
//	printf("0       : %s\n", ft_itoa(0));
//	return (0);
// }
