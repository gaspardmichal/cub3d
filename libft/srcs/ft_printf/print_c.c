/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:22:49 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 18:41:33 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	print_c_w(t_dota *dt, const char c)
{
	if (dt->minus == '0')
	{
		print_spaces(dt, 32, 1);
		dt->res += write(1, &c, 1);
	}
	else if (dt->minus == '1')
	{
		dt->res += write(1, &c, 1);
		print_spaces(dt, 32, 1);
	}
}

static void	print_c_utils(t_dota *dt, const char c)
{
	if (dt->w_read == '0')
		dt->res += write(1, &c, 1);
	else if (dt->w_read == '1')
		print_c_w(dt, c);
}

void		print_c(t_dota *dt)
{
	char c;

	c = va_arg(dt->ap, int);
	print_c_utils(dt, c);
}
