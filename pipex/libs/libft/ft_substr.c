/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:25:39 by hiroaki           #+#    #+#             */
/*   Updated: 2022/06/21 19:19:33 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	slen;
	unsigned int	dlen;
	char			*ret;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
		return (ft_strdup(""));
	dlen = slen - start;
	if (len < dlen)
		dlen = len;
	ret = (char *)malloc(dlen + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s + start, dlen + 1);
	return (ret);
}

//#include <stdio.h>
//
//int main(void)
//{
//	char *s;
//
//	printf("***********************************\n");
//	printf("%s\n", ft_substr("hmakino-42", 8, 42));
//	printf("***********************************\n");
//	return (0);
//}
