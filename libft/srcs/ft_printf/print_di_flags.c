/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:31:52 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 18:41:56 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	print_m_spaces(t_dota *dt, int c)
{
	if (dt->width > dt->prec)
	{
		while (dt->indx < dt->width)
		{
			dt->res += write(1, &c, 1);
			++dt->indx;
		}
	}
}

void	print_di_m_wp(t_dota *dt, const char *d, int offset)
{
	if (d[0] == '-')
	{
		dt->res += write(1, "-", 1);
		print_zeros(dt, offset - 1);
		dt->res += write(1, &d[1], offset - 1);
		dt->indx += offset - 1;
		if (!dt->prec)
			print_spaces(dt, 32, offset);
		else
		{
			print_m_spaces(dt, 32);
		}
	}
	else
		print_ux_m_wp(dt, d, offset);
}

void	print_di_z_w(t_dota *dt, const char *d, int offset)
{
	if (d[0] == '-')
	{
		dt->res += write(1, "-", 1);
		print_spaces(dt, 48, offset);
		dt->res += write(1, &d[1], offset - 1);
	}
	else
		print_ux_z_w(dt, d, offset);
}

void	print_di_z_wp(t_dota *dt, const char *d, int offset)
{
	if (d[0] == '-')
	{
		if (!dt->prec)
			print_spaces(dt, 32, offset);
		else
		{
			if (dt->prec < offset)
				print_spaces(dt, 32, offset);
			else
				print_spaces(dt, 32, dt->prec + 1);
		}
		dt->res += write(1, "-", 1);
		print_zeros(dt, offset - 1);
		dt->res += write(1, &d[1], offset - 1);
	}
	else
		print_ux_z_wp(dt, d, offset);
}
