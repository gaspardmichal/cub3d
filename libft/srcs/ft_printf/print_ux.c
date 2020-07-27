/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:34:39 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 18:44:30 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	print_ux_no_flags(t_dota *dt, const char *u, int offset)
{
	if (dt->w_read == '0' && dt->p_read == '0')
		dt->res += write(1, u, offset);
	else if (dt->w_read == '1' && dt->p_read == '0')
		print_ux_w(dt, u, offset);
	else if (dt->p_read == '1' && dt->w_read == '0')
		print_ux_p(dt, u, offset);
	else if (dt->w_read == '1' && dt->p_read == '1')
		print_ux_wp(dt, u, offset);
}

static void	print_ux_minus(t_dota *dt, const char *u, int offset)
{
	if (dt->w_read == '0' && dt->p_read == '0')
		dt->res += write(1, u, offset);
	else if (dt->w_read == '1' && dt->p_read == '0')
		print_ux_m_w(dt, u, offset);
	else if (dt->p_read == '1' && dt->w_read == '0')
		print_ux_p(dt, u, offset);
	else if (dt->w_read == '1' && dt->p_read == '1')
		print_ux_m_wp(dt, u, offset);
}

static void	print_ux_zero(t_dota *dt, const char *u, int offset)
{
	if (dt->w_read == '0' && dt->p_read == '0')
		dt->res += write(1, u, offset);
	else if (dt->w_read == '1' && dt->p_read == '0')
		print_ux_z_w(dt, u, offset);
	else if (dt->p_read == '1' && dt->w_read == '0')
		print_ux_p(dt, u, offset);
	else if (dt->w_read == '1' && dt->p_read == '1')
		print_ux_z_wp(dt, u, offset);
}

void		print_ux(t_dota *dt)
{
	char	*u;
	int		offset;

	u = ft_itoa_base(va_arg(dt->ap, unsigned int), dt->base);
	offset = ft_strlen(u);
	if (dt->zero == '0' && dt->minus == '0')
		print_ux_no_flags(dt, u, offset);
	else if (dt->minus == '1')
		print_ux_minus(dt, u, offset);
	else if (dt->zero == '1')
		print_ux_zero(dt, u, offset);
	free(dt->base);
	free(u);
}
