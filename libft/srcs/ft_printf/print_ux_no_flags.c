/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ux_no_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:04:45 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 18:44:17 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	print_ux_w(t_dota *dt, const char *u, int offset)
{
	print_spaces(dt, 32, offset);
	dt->res += write(1, u, offset);
}

void	print_ux_p(t_dota *dt, const char *u, int offset)
{
	if (u[0] == '0' && dt->prec == 0)
		return ;
	print_zeros(dt, offset);
	dt->res += write(1, u, offset);
}

void	print_ux_wp(t_dota *dt, const char *u, int offset)
{
	if (u[0] == '0')
		offset = 0;
	print_spaces(dt, 32, offset);
	print_zeros(dt, offset);
	dt->res += write(1, u, offset);
}
