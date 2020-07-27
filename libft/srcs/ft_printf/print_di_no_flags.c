/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di_no_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:23:31 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 18:42:09 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	print_di_w(t_dota *dt, const char *d, int offset)
{
	if (d[0] == '-')
	{
		print_spaces(dt, 32, offset);
		dt->res += write(1, "-", 1);
		dt->res += write(1, &d[1], offset - 1);
	}
	else
		print_ux_w(dt, d, offset);
}

void	print_di_p(t_dota *dt, const char *d, int offset)
{
	if (d[0] == '-')
	{
		dt->res += write(1, "-", 1);
		print_zeros(dt, offset - 1);
		dt->res += write(1, &d[1], offset - 1);
	}
	else
		print_ux_p(dt, d, offset);
}

void	print_di_wp(t_dota *dt, const char *d, int offset)
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
		print_ux_wp(dt, d, offset);
}
