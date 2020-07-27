/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:14:50 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 18:40:37 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		parse_form(const char *format, t_dota *dt)
{
	while (*(format + dt->i))
	{
		if (*(format + dt->i) != '%')
			dt->res += write(1, format + dt->i, 1);
		else if (*(format + dt->i) == '%' && *(format + dt->i + 1))
		{
			++dt->i;
			parse_modif(format, dt);
			if (!ft_strchr(SPEC, *(format + dt->i)))
				break ;
			parse_spec(dt, *(format + dt->i));
			reset_data(dt);
		}
		++dt->i;
	}
}

static void		fill(void (*arr[9]) (t_dota *))
{
	arr[0] = print_c;
	arr[1] = print_s;
	arr[2] = print_p;
	arr[3] = print_di;
	arr[4] = print_di;
	arr[5] = print_ux;
	arr[6] = print_ux;
	arr[7] = print_ux;
	arr[8] = print_percent;
}

static t_dota	*set_data(const char *format)
{
	t_dota *dt;

	if (!(dt = malloc(sizeof(t_dota))))
		return (NULL);
	dt->i = 0;
	dt->res = 0;
	dt->minus = '0';
	dt->zero = '0';
	dt->w_star = '0';
	dt->p_star = '0';
	dt->w_read = '0';
	dt->p_read = '0';
	dt->width = 0;
	dt->prec = 0;
	dt->indx = 1;
	dt->format = format;
	dt->spec = ft_strdup(SPEC);
	fill(dt->arr);
	return (dt);
}

static int		del_data(t_dota *dt)
{
	int n;

	n = dt->res;
	free(dt->spec);
	dt->spec = NULL;
	free(dt);
	dt = NULL;
	return (n);
}

int				ft_printf(const char *format, ...)
{
	t_dota		*dt;

	dt = set_data(format);
	va_start(dt->ap, format);
	parse_form(format, dt);
	va_end(dt->ap);
	return (del_data(dt));
}
