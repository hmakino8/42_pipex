/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:30:25 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/03 01:47:39 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	st;
	size_t	ed;

	if (str == NULL || set == NULL)
		return (NULL);
	st = 0;
	ed = ft_strlen(str) - 1;
	while (str[st] != '\0' && ft_strchr(set, str[st]))
		st++;
	while (st <= ed && ft_strrchr(set, str[ed]))
		ed--;
	return (ft_substr((char *)str, st, ed - st + 1));
}
