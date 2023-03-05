/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:48:13 by hiroaki           #+#    #+#             */
/*   Updated: 2023/03/06 05:23:05 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	const unsigned char	*us1;
	const unsigned char	*us2;

	us1 = (const unsigned char *)str1;
	us2 = (const unsigned char *)str2;
	while (1)
	{
		if (!*us1 || !*us2 || *us1 != *us2)
			break ;
		us1++;
		us2++;
	}
	return (*us1 - *us2);
}
