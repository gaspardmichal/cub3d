/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:37:27 by gamichal          #+#    #+#             */
/*   Updated: 2020/03/07 14:02:00 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_exit(void *ptr, int ret)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (ret);
}
