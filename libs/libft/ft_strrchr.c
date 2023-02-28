/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:37:42 by hmakino           #+#    #+#             */
/*   Updated: 2022/06/24 05:57:09 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	ch;

	ch = (char)c;
	len = ft_strlen(s);
	if (!ch)
		return ((char *)&s[len]);
	while (len--)
	{
		if (s[len] == ch)
			return ((char *)&s[len]);
	}
	return (NULL);
}

//#include <stdio.h>
//#include <string.h>
//
//int	main(void)
//{
//	int	i = 220;
//	char	array[] = "locates the LAST occurrence of c.";
//	int		ch = 'A';
//
//	printf("***********************************\n");
//	printf("strrchr    : %s\n", strrchr(array, 'L'));
//	printf("ft_strrchr : %s\n", ft_strrchr(array, 'L'));
//	printf("-----------------------------------\n");
//	printf("strrchr    : %s\n", strrchr(array, 'T' + 256));
//	printf("ft_strrchr : %s\n", ft_strrchr(array, 'T' + 256));
//	printf("-----------------------------------\n");
//	printf("strrchr    : %s\n", strrchr(array, '\0'));
//	printf("ft_strrchr : %s\n", ft_strrchr(array, '\0'));
//	printf("***********************************\n");
//
//	return (0);
//}
