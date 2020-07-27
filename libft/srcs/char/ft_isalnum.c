/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:04:44 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 17:56:24 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == TRUE || ft_isdigit(c) == TRUE)
		return (TRUE);
	return (FALSE);
}
