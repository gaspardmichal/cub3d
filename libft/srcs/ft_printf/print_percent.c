/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:40:29 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 18:43:28 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	print_percent_w(t_dota *dt, int c, int offset)
{
	if (dt->minus == '0')
	{
		print_spaces(dt, c, offset);
		dt->res += write(1, "%", 1);
	}
	else if (dt->minus == '1')
	{
		dt->res += write(1, "%", 1);
		print_spaces(dt, 32, offset);
	}
}

void	print_percent_wp(t_dota *dt, int c, int offset)
{
	if (dt->minus == '0')
	{
		if (!dt->prec)
			--dt->width;
		print_s_spaces(dt, c, offset);
		dt->res += write(1, "%", 1);
	}
	else if (dt->minus == '1')
	{
		dt->res += write(1, "%", 1);
		if (!dt->prec)
			--dt->width;
		print_s_spaces(dt, 32, offset);
	}
}

void	print_percent_utils(t_dota *dt, int c, int offset)
{
	if (dt->w_read == '0' && dt->p_read == '0' &&
		(ft_strchr(FLAGS, *(dt->format + dt->i - 1)) ||
		ft_strchr(WIDTH, *(dt->format + dt->i - 1))))
		dt->res += write(1, "%", 1);
	else if (dt->w_read == '1' && dt->p_read == '0')
		print_percent_w(dt, c, offset);
	else if (dt->p_read == '1' && dt->w_read == '0')
		dt->res += write(1, "%", 1);
	else if (dt->w_read == '1' && dt->p_read == '1')
		print_percent_wp(dt, c, offset);
}

void	print_percent(t_dota *dt)
{
	int offset;

	offset = 1;
	if (*(dt->format + dt->i) == '%' && *(dt->format + dt->i - 1) == '%')
		dt->res += write(1, "%", 1);
	if (dt->zero == '0' && dt->minus == '0')
		print_percent_utils(dt, 32, offset);
	else if (dt->minus == '1')
		print_percent_utils(dt, 32, offset);
	else if (dt->zero == '1')
		print_percent_utils(dt, 48, offset);
}
