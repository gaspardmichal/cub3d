/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 11:47:02 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:04:02 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *save;

	if (!lst || !f)
		return ;
	save = lst;
	while (save)
	{
		f(save->content);
		save = save->next;
	}
}
