/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_no_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:24:44 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 18:42:53 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	print_p_w(t_dota *dt, const char *p, int offset)
{
	print_spaces(dt, 32, offset + 2);
	dt->res += write(1, "0x", 2) + write(1, p, offset);
}

void	print_p_p(t_dota *dt, const char *p, int offset)
{
	if (p[0] == '0' && dt->prec == 0)
		offset = 0;
	print_zeros(dt, offset);
	dt->res += write(1, "0x", 2) + write(1, p, offset);
}

void	print_p_wp(t_dota *dt, const char *p, int offset)
{
	if (p[0] == '0')
		offset = 0;
	print_spaces(dt, 32, offset + 2);
	print_zeros(dt, offset);
	dt->res += write(1, "0x", 2) + write(1, p, offset);
}

void	print_p_no_flag(t_dota *dt, const char *p, int offset)
{
	if (dt->w_read == '0' && dt->p_read == '0')
		dt->res += write(1, "0x", 2) + write(1, p, offset);
	else if (dt->w_read == '1' && dt->p_read == '0')
		print_p_w(dt, p, offset);
	else if (dt->p_read == '1' && dt->w_read == '0')
		print_p_p(dt, p, offset);
	else if (dt->w_read == '1' && dt->p_read == '1')
		print_p_wp(dt, p, offset);
}
