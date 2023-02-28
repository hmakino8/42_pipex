/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:30:25 by hiroaki           #+#    #+#             */
/*   Updated: 2022/03/10 23:23:59 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (start <= end && ft_strrchr(set, s1[end]))
		end--;
	return (ft_substr((char *)s1, start, end - start + 1));
}

//#include <stdio.h>
//
//int main(void)
//{
//	char array1[] = "*;|@123***456@|;";
//	char set1[] = "*;|@";
//	char array2[] = "*;|@123***456@|;";
//	char set2[] = "*;|@123456";
//	char array3[] = "#*;|@123***456@|;";
//	char array4[] = "*;|@123***456@|;#";
//	char array5[] = "* ;  |@123***456@|;#";
//	char set5[] = "*; | @  ";
//	char array6[] = "   xxx   xxx";
//	char set6[] = " x";
//
//	printf("***********************************\n");
//	printf("array1  *;|@123***456@|;\nset1    *;|@\n");
//	printf("ans     %s\n", ft_strtrim(array1, set1));
//	printf("-----------------------------------\n");
//	printf("array2  *;|@123***456@|;\nset2    *;|@123456\n");
//	printf("ans     %s\n", ft_strtrim(array2, set2));
//	printf("-----------------------------------\n");
//	printf("array5  #*;|@123***456@|;\nset1    *;|@\n");
//	printf("ans     %s\n", ft_strtrim(array3, set1));
//	printf("-----------------------------------\n");
//	printf("array4  *;|@123***456@|;#\nset1    *;|@\n");
//	printf("ans     %s\n", ft_strtrim(array4, set1));
//	printf("-----------------------------------\n");
//	printf("array5  * ; |@123***456@|;#\nset5    *; | @\n");
//	printf("ans     %s\n", ft_strtrim(array5, set5));
//	printf("-----------------------------------\n");
//	printf("array6     xxx   xxx\nset6    x\n");
//	printf("ans     %s\n", ft_strtrim(array6, set6));
//	printf("***********************************\n");
//
//	return (0);
//}
