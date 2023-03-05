/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:48:09 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/07 18:22:13 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <limits.h>
# include "ft_ctype.h"
# include "ft_string.h"

# define BASE "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

void	*ft_calloc(size_t count, size_t size);
void	*ft_realloc(void *src, size_t size);
void	*ft_xcalloc(size_t count, size_t size);
void	*ft_xmalloc(size_t size);
void	*ft_xrealloc(void *ptr, size_t size);
void	*ft_error_handler(char *funcname, int e);
void	*ft_free(void **vptr);
void	*ft_free_dptr(void ***triptr, size_t n);
int		free_error_exit(char *str);
int		ft_atoi(const char *str);
long	ft_strtol(const char *str, char **endptr, int base);
char	*ft_itoa(int n);
char	*ft_itoa_base(int n, unsigned int base);

#endif
