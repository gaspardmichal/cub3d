/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:35:28 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/04 10:34:50 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_win(t_all *s)
{
	t_win win;

	win.ptr = NULL;
	win.x = -1;
	win.y = -1;
	s->win = win;
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
