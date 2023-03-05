/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:30:17 by hiroaki           #+#    #+#             */
/*   Updated: 2023/02/07 21:08:06 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

int	free_error_exit(char *str)
{
	if (str != NULL)
		ft_free((void **)&str);
	return (-1);
}

void	*ft_free(void **vptr)
{
	free(*vptr);
	*vptr = NULL;
	return (NULL);
}

void	*ft_free_dptr(void ***triptr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free((*triptr)[i]);
		(*triptr)[i] = NULL;
		i++;
	}
	free(*triptr);
	*triptr = NULL;
	return (NULL);
}
