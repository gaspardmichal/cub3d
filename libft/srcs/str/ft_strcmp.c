/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:09:46 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 15:22:27 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] == s2[i])
			++i;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
