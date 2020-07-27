/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:11:07 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 18:39:07 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		get_offset(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

void	get_modif(t_dota *dt)
{
	if (dt->w_read == '1' && dt->p_read == '0')
	{
		dt->w_star = '1';
		dt->width = va_arg(dt->ap, int);
		if (dt->width < 0)
		{
			dt->width *= -1;
			dt->minus = '1';
		}
	}
	else if (dt->p_read == '1')
	{
		dt->p_star = '1';
		dt->prec = va_arg(dt->ap, int);
		if (dt->prec < 0)
			dt->p_read = '0';
	}
}

void	print_spaces(t_dota *dt, int c, int offset)
{
	int i;

	if (dt->width > dt->prec)
	{
		if (dt->prec > offset)
			i = dt->prec;
		else
			i = offset;
		while (i < dt->width)
		{
			dt->res += write(1, &c, 1);
			++i;
		}
	}
}

void	print_zeros(t_dota *dt, int offset)
{
	int i;

	i = dt->prec;
	while (i > offset)
	{
		dt->res += write(1, "0", 1);
		--i;
		++dt->indx;
	}
}

void	reset_data(t_dota *dt)
{
	dt->minus = '0';
	dt->zero = '0';
	dt->w_star = '0';
	dt->p_star = '0';
	dt->w_read = '0';
	dt->p_read = '0';
	dt->width = 0;
	dt->prec = 0;
	dt->indx = 1;
}
