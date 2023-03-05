/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:25:39 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/03 01:47:17 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	unsigned int	str_len;
	unsigned int	sub_len;
	char			*ret;

	if (str == NULL)
		return (NULL);
	str_len = ft_strlen(str);
	if (str_len < start)
		return (ft_strdup(""));
	sub_len = str_len - start;
	if (len < sub_len)
		sub_len = len;
	ret = malloc(sub_len + 1);
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, str + start, sub_len + 1);
	return (ret);
}
