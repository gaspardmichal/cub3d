/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:31:35 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 18:41:31 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		get_pos(const char c, const char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}

void	parse_spec(t_dota *dt, const char c)
{
	int tmp;

	tmp = get_pos(c, SPEC);
	if (tmp == 2 || tmp == 6)
		dt->base = ft_strdup("0123456789abcdef");
	else if (tmp == 7)
		dt->base = ft_strdup("0123456789ABCDEF");
	else if (tmp == 3 || tmp == 4 || tmp == 5)
		dt->base = ft_strdup("0123456789");
	(*dt->arr[tmp])(dt);
}
