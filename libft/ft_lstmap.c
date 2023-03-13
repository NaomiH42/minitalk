/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:39:03 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/14 11:02:06 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	head = NULL;
	if (!lst || !del || !f)
		return (NULL);
	head = ft_lstnew((f)(lst->content));
	temp = head;
	while (lst->next != NULL)
	{
		lst = lst->next;
		temp->next = ft_lstnew((f)(lst->content));
		if (!temp)
			(del)(lst);
		temp = temp->next;
	}
	return (head);
}
