/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 11:49:59 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:03:52 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*to_del;
	t_list	*temp;

	if (!lst || !del)
		return ;
	to_del = *lst;
	while (to_del)
	{
		temp = to_del->next;
		ft_lstdelone(to_del, del);
		to_del = temp;
	}
	*lst = NULL;
}
