/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:11:21 by fbouteil          #+#    #+#             */
/*   Updated: 2024/11/26 12:22:26 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!lst || !f || !del)
		return (NULL);
	new_elem = ft_lstnew(f(lst->content));
	new_list = new_elem;
	while (lst && lst->next)
	{
		if (!new_elem)
			return (NULL);
		new_elem->next = ft_lstnew(f(lst->next->content));
		new_elem = new_elem->next;
		lst = lst->next;
	}
	return (new_list);
}
