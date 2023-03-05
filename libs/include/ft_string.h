/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:48:09 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/07 22:52:57 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>
# include "ft_stdlib.h"

# ifndef TRUE
#  define TRUE 1
# endif

size_t	ft_strlen(const char *str);
size_t	ft_strlen_dptr(char **ptr);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_memcmp(const void *vptr1, const void *vptr2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *vptr, int ch, size_t n);
void	*ft_memset(void *vptr, int ch, size_t len);
void	ft_striteri(char *str, void (*f)(unsigned int, char*));
char	*ft_strchr(const char *str, int ch);
char	*ft_strrchr(const char *str, int ch);
char	*ft_strnstr(const char *str1, const char *str2, size_t len);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strtrim(char const *str, char const *set);
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
char	**ft_split(char const *str, char ch);
void	ft_bzero(void *s, size_t n);

#endif
