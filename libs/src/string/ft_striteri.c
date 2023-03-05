/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:12:25 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/03 04:14:01 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (str == NULL || f == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		(*f)(i, &str[i]);
		i++;
	}
}
