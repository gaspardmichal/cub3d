/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 06:19:59 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 17:56:33 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_isalpha(int c)
{
	if (ft_isupper(c) == TRUE || ft_islower(c) == TRUE)
		return (TRUE);
	return (FALSE);
}
