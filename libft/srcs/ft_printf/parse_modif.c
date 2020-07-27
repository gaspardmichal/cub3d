/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_modif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:38:55 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 18:41:30 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	parse_flags(const char *format, t_dota *dt)
{
	while (*(format + dt->i) && ft_strchr(FLAGS, *(format + dt->i)))
	{
		if (*(format + dt->i) == '-')
			dt->minus = '1';
		if (*(format + dt->i) == '0')
			dt->zero = '1';
		++dt->i;
	}
}

void	parse_width(const char *format, t_dota *dt)
{
	int		offset;
	char	read;

	if (*(format + dt->i) && ft_strchr(WIDTH, *(format + dt->i)))
	{
		dt->w_read = '1';
		if (*(format + dt->i) == '*' && dt->w_star == '0')
			get_modif(dt);
		else if (!ft_isdigit(*(format + dt->i)))
		{
			dt->width = ft_atoi(format + dt->i);
			read = '1';
		}
		if (dt->w_star == '0' && read == '1')
		{
			offset = get_offset(dt->width);
			dt->i += offset == 0 ? 1 : offset;
		}
		else if (dt->w_star == '1')
			++dt->i;
	}
}

void	parse_prec(const char *format, t_dota *dt)
{
	int offset;
	int read;

	if (*(format + dt->i) == '.')
	{
		++dt->i;
		dt->p_read = '1';
		dt->prec = 0;
		if (*(format + dt->i) == '*' && dt->p_star == '0')
			get_modif(dt);
		else if (!ft_isdigit(*(format + dt->i)))
		{
			if (*(format + dt->i) == '0' && !ft_isdigit(*(format + dt->i + 1)))
				++dt->i;
			dt->prec = ft_atoi(format + dt->i);
			read = '1';
		}
		if (dt->p_star == '0' && read == '1')
		{
			offset = get_offset(dt->prec);
			dt->i += offset == 0 ? 1 : offset;
		}
		else if (dt->p_star == '1')
			++dt->i;
	}
}

void	parse_modif(const char *format, t_dota *dt)
{
	parse_flags(format, dt);
	parse_width(format, dt);
	parse_prec(format, dt);
}
