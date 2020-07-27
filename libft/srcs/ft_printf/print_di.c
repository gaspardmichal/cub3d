/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:22:02 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 18:42:22 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	print_di_no_flags(t_dota *dt, const char *d, int offset)
{
	if (dt->w_read == '0' && dt->p_read == '0')
		dt->res += write(1, d, offset);
	else if (dt->w_read == '1' && dt->p_read == '0')
		print_di_w(dt, d, offset);
	else if (dt->p_read == '1' && dt->w_read == '0')
		print_di_p(dt, d, offset);
	else if (dt->w_read == '1' && dt->p_read == '1')
		print_di_wp(dt, d, offset);
}

static void	print_di_minus(t_dota *dt, const char *d, int offset)
{
	if (dt->w_read == '0' && dt->p_read == '0')
		dt->res += write(1, d, offset);
	else if (dt->w_read == '1' && dt->p_read == '0')
		print_ux_m_w(dt, d, offset);
	else if (dt->p_read == '1' && dt->w_read == '0')
		print_di_p(dt, d, offset);
	else if (dt->w_read == '1' && dt->p_read == '1')
		print_di_m_wp(dt, d, offset);
}

static void	print_di_zero(t_dota *dt, const char *d, int offset)
{
	if (dt->w_read == '0' && dt->p_read == '0')
		dt->res += write(1, d, offset);
	else if (dt->w_read == '1' && dt->p_read == '0')
		print_di_z_w(dt, d, offset);
	else if (dt->p_read == '1' && dt->w_read == '0')
		print_di_p(dt, d, offset);
	else if (dt->w_read == '1' && dt->p_read == '1')
		print_di_z_wp(dt, d, offset);
}

void		print_di(t_dota *dt)
{
	char	*d;
	int		offset;

	d = ft_itoa_base(va_arg(dt->ap, int), dt->base);
	offset = ft_strlen(d);
	if (dt->zero == '0' && dt->minus == '0')
		print_di_no_flags(dt, d, offset);
	else if (dt->minus == '1')
		print_di_minus(dt, d, offset);
	else if (dt->zero == '1')
		print_di_zero(dt, d, offset);
	free(dt->base);
	free(d);
}
