/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:56:38 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/13 12:33:57 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*nodet;

	node = *lst;
	while (node)
	{
		nodet = node->next;
		(del)(node->content);
		free(node);
		node = nodet;
	}
	*lst = NULL;
}
