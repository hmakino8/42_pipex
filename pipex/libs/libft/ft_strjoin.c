/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:51:37 by hiroaki           #+#    #+#             */
/*   Updated: 2022/06/20 04:38:15 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;
	size_t	s1_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	sjoin = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!sjoin)
		return (NULL);
	s1_len = ft_strlen(s1);
	ft_memcpy(sjoin, s1, s1_len);
	ft_strlcpy(&sjoin[s1_len], s2, ft_strlen(s2) + 1);
	return (sjoin);
}

//#include <string.h>
//#include <stdio.h>
//
//int main(void)
//{
//	char const s1[] = "42tokyo-";
//	char const s2[] = "hmakino";
//
//	printf("***********************************\n");
//	printf("case s1 NULL: %s\n", ft_strjoin(NULL, s2));
//	printf("case s2 NULL: %s\n", ft_strjoin(s1, NULL));
//	printf("case not NULL: %s\n", ft_strjoin(s1, s2));
//	printf("***********************************\n");
//	return (0);
//}
