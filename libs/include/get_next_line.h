/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 04:36:17 by hmakino           #+#    #+#             */
/*   Updated: 2023/02/10 16:50:11 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <limits.h>
# include "ft_string.h"
# include "ft_stdlib.h"

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define NORMAL 0
# define END_OF_FILE 1

char	*get_next_line(int fd);
int		creat_buffer(char **stk, int fd, int *sig);
int		search_linefeed(char **stk, int fd, int *loc, int *sig);
int		split_buffer(char **stk, char **line, int loc);

#endif
