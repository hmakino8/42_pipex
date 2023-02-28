/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:48:30 by hiroaki           #+#    #+#             */
/*   Updated: 2022/06/21 18:50:18 by hmakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

//#include <stdio.h>
//
//int main(void)
//{
//	t_list	*node_first;
//	t_list	*node_second;
//	t_list	*node_third;
//
//	node_first = ft_lstnew("1st");
//	node_second = ft_lstnew("2nd");
//	node_third = ft_lstnew("3rd");
//	node_first->next = node_second;
//	node_second->next = node_third;
//
//	printf("\nthird->content : %s\n", (char *)ft_lstlast(node_first)->content);
//
//	return (0);
//}
