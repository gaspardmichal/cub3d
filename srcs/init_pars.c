/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:59:32 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/07 17:02:26 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_res(t_all *s)
{
	t_res res;

	res.width = -1;
	res.height = -1;
	s->res = res;
}

void	init_txt(t_all *s)
{
	t_txt txt;

	txt.no = NULL;
	txt.so = NULL;
	txt.we = NULL;
	txt.ea = NULL;
	txt.s = NULL;
	s->txt = txt;
}

void	init_col(t_all *s)
{
	t_col col;

	col.f = -1;
	col.c = -1;
	s->col = col;
}

void	init_map(t_all *s)
{
	t_map map;

	map.grid = NULL;
	map.info = 0;
	s->map = map;
}

void	init_pos(t_all *s)
{
	t_pos pos;

	pos.x = -1;
	pos.y = -1;
	s->pos = pos;
}
