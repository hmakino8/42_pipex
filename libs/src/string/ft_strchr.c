/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:33:46 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/06 04:25:39 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;
	char	ch1;

	if (str == NULL)
		return (NULL);
	ch1 = (char)ch;
	i = 0;
	while (str[i] != '\0' || (str[i] == '\0' && ch1 == '\0'))
	{
		if (str[i] == ch1)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
