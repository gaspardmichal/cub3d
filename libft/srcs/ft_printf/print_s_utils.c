/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:34:05 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 18:43:41 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	print_s_w(t_dota *dt, const char *s, int offset)
{
	if (dt->minus == '0')
	{
		print_spaces(dt, 32, offset);
		dt->res += write(1, s, offset);
	}
	else if (dt->minus == '1')
	{
		dt->res += write(1, s, offset);
		print_spaces(dt, 32, offset);
	}
}

void	print_s_p(t_dota *dt, const char *s, int offset)
{
	int i;

	i = 0;
	while (i < dt->prec && i < offset)
	{
		dt->res += write(1, s + i, 1);
		++i;
	}
}

void	print_s_wp(t_dota *dt, const char *s, int offset)
{
	if (dt->minus == '0')
	{
		print_s_spaces(dt, 32, offset);
		print_s_p(dt, s, offset);
	}
	else if (dt->minus == '1')
	{
		print_s_p(dt, s, offset);
		print_s_spaces(dt, 32, offset);
	}
}
