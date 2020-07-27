/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:25:40 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 18:42:34 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	print_p_m_w(t_dota *dt, const char *p, int offset)
{
	dt->res += write(1, "0x", 2) + write(1, p, offset);
	print_spaces(dt, 32, offset + 2);
}

void	print_p_m_wp(t_dota *dt, const char *p, int offset)
{
	print_zeros(dt, offset);
	if (!dt->prec)
	{
		if (p[0] == '0')
			offset = 0;
		dt->res += write(1, p, offset);
		print_spaces(dt, 32, offset);
	}
	else
	{
		dt->res += write(1, p, offset);
		if (p[0] == '0')
			print_spaces(dt, 32, dt->prec);
		else
			print_spaces(dt, 32, offset);
	}
}

void	print_p_minus(t_dota *dt, const char *p, int offset)
{
	if (dt->w_read == '0' && dt->p_read == '0')
		dt->res += write(1, "0x", 2) + write(1, p, offset);
	else if (dt->w_read == '1' && dt->p_read == '0')
		print_p_m_w(dt, p, offset);
	else if (dt->p_read == '1' && dt->w_read == '0')
		print_p_p(dt, p, offset);
	else if (dt->w_read == '1' && dt->p_read == '1')
		print_p_m_wp(dt, p, offset);
}
