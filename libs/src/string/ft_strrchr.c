/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:37:42 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/03 01:46:57 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	len;
	char	ch1;

	ch1 = (char)ch;
	len = ft_strlen(str);
	if (ch1 == '\0')
		return ((char *)&str[len]);
	while (len--)
	{
		if (str[len] == ch1)
			return ((char *)&str[len]);
	}
	return (NULL);
}
