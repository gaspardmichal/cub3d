/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 11:44:11 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:04:12 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*save;
	t_list	*head;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	if (!(head = ft_lstnew(f(lst->content))))
		return (NULL);
	save = lst->next;
	while (save)
	{
		if (!(new = ft_lstnew(f(save->content))))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		save = save->next;
	}
	return (head);
}
