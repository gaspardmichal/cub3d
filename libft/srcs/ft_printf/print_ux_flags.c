/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ux_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:36:20 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 18:44:05 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	print_ux_m_w(t_dota *dt, const char *u, int offset)
{
	dt->res += write(1, u, offset);
	print_spaces(dt, 32, offset);
}

void	print_ux_m_wp(t_dota *dt, const char *u, int offset)
{
	print_zeros(dt, offset);
	if (!dt->prec)
	{
		if (u[0] == '0')
			offset = 0;
		dt->res += write(1, u, offset);
		print_spaces(dt, 32, offset);
	}
	else
	{
		dt->res += write(1, u, offset);
		if (u[0] == '0')
			print_spaces(dt, 32, dt->prec);
		else
			print_spaces(dt, 32, offset);
	}
}

void	print_ux_z_w(t_dota *dt, const char *u, int offset)
{
	print_spaces(dt, 48, offset);
	dt->res += write(1, u, offset);
}

void	print_ux_z_wp(t_dota *dt, const char *u, int offset)
{
	if (!dt->prec)
	{
		if (u[0] == '0')
			offset = 0;
		print_spaces(dt, 32, offset);
	}
	else
	{
		if (u[0] == '0')
			print_spaces(dt, 32, dt->prec);
		else
			print_spaces(dt, 32, offset);
	}
	print_zeros(dt, offset);
	dt->res += write(1, u, offset);
}
