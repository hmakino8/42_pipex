/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:51:37 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/03 01:47:33 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*concat;
	size_t	len;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (str1 == NULL)
		return (ft_strdup(str2));
	if (str2 == NULL)
		return (ft_strdup(str1));
	concat = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (concat == NULL)
		return (NULL);
	len = ft_strlen(str1);
	ft_memcpy(concat, str1, len);
	ft_strlcpy(&concat[len], str2, ft_strlen(str2) + 1);
	return (concat);
}
