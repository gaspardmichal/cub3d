/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:33:36 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:04:21 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*save;
	int		size;

	save = lst;
	size = 0;
	while (save)
	{
		++size;
		save = save->next;
	}
	return (size);
}
