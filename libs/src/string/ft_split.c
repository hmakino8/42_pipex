/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:30:41 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/07 22:51:04 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static size_t	count_elem(char const *str, char ch)
{
	size_t	n;

	n = 0;
	while (*str != '\0')
	{
		if (*str++ != ch)
		{
			n++;
			while (*str != '\0' && *str != ch)
				str++;
		}
	}
	return (n);
}

static char	**split_str(char const *str, char ch, size_t n)
{
	size_t	i;
	size_t	len;
	char	**dptr;

	dptr = ft_calloc(n + 1, sizeof(char *));
	if (dptr == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0' && i < n)
	{
		len = 0;
		while (*str != '\0' && *str == ch)
			str++;
		while (str[len] != '\0' && str[len] != ch)
			len++;
		if (len > 0)
		{
			dptr[i] = ft_substr(str, 0, len);
			if (dptr[i] == NULL)
				ft_free_dptr((void ***)&dptr, i);
			i++;
		}
		str += len;
	}
	return (dptr);
}

char	**ft_split(char const *str, char ch)
{
	size_t	n;

	if (str == NULL)
		return (NULL);
	n = count_elem(str, ch);
	return (split_str(str, ch, n));
}
