/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr            +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:30:41 by hiroaki           #+#    #+#             */
/*   Updated: 2022/06/21 19:08:00 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_all_element(char **s, size_t i)
{
	while (i--)
	{
		free(s[i]);
		s[i--] = NULL;
	}
	free(s);
	return (NULL);
}

static size_t	element_cnt(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s++ != c)
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
	}
	return (cnt);
}

static char	**element_cpy(char const *s, char **split, char c, size_t cnt)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s && i < cnt)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (*(s + len) && *(s + len) != c)
			len++;
		if (len)
		{
			split[i] = ft_substr(s, 0, len);
			if (!(split[i]))
				return (free_all_element(&split[i], i));
			i++;
		}
		s += len;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	cnt;
	char	**split;

	if (!s)
		return (NULL);
	cnt = element_cnt(s, c);
	split = (char **)malloc((cnt + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (element_cpy(s, split, c, cnt));
}

//#include <stdio.h>
//
//int main(void)
//{
//	char **split;
//	char src[] = "      split       this for   me  !       ";
//	char delimiter = ' ';
//	size_t	i = 0;
//	size_t	elem_cnt = 0;
//
//	printf("***********************************************\n");
//	split = ft_split(src, delimiter);
//	elem_cnt = element_cnt(src, delimiter);
//	printf("src : %s\ndelimiter : %c\n", src, delimiter);
//	printf("-----------------------------------------------\n");
//	while (i <= elem_cnt)
//	{
//		printf("ft_split %lu: %s\n", i ,split[i]);
//		i++;
//	}
//	printf("************************************************\n");
//	return 0;
//}
