/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:25:23 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 18:43:54 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		display_spaces(t_dota *dt, int c, int offset)
{
	while (offset < dt->width)
	{
		dt->res += write(1, &c, 1);
		++offset;
	}
}

void		print_s_spaces(t_dota *dt, int c, int offset)
{
	if (dt->width <= offset)
		display_spaces(dt, c, dt->prec);
	else
	{
		if (dt->prec < offset)
			display_spaces(dt, c, dt->prec);
		else
			display_spaces(dt, c, offset);
	}
}

static void	print_s_utils(t_dota *dt, const char *s, int offset)
{
	if (dt->w_read == '0' && dt->p_read == '0')
		dt->res += write(1, s, offset);
	else if (dt->w_read == '1' && dt->p_read == '0')
		print_s_w(dt, s, offset);
	else if (dt->p_read == '1' && dt->w_read == '0')
		print_s_p(dt, s, offset);
	else if (dt->w_read == '1' && dt->p_read == '1')
		print_s_wp(dt, s, offset);
}

void		print_s(t_dota *dt)
{
	char	*s;
	int		offset;

	if (!(s = va_arg(dt->ap, char *)))
		s = ft_strdup("(null)");
	offset = ft_strlen(s);
	print_s_utils(dt, s, offset);
	if (!ft_strncmp(s, "(null)", 6))
		free(s);
}
