/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:35:28 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/03 14:09:06 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mlx(t_all *s)
{
	t_mlx mlx;

	mlx.rx = -1;
	mlx.ry = -1;
	s->mlx = mlx;
}

void	init_map(t_all *s)
{
	t_map map;

	map.grid = NULL;
	map.info = 0;
	s->map = map;
}

void	init_player(t_all *s)
{
	t_p p;

	p.x = -1;
	p.y = -1;
	s->p = p;
}

void	init_texture(t_all *s)
{
	t_txt txt;

	txt.no = NULL;
	txt.so = NULL;
	txt.we = NULL;
	txt.ea = NULL;
	txt.s = NULL;
	s->txt = txt;
}

void	init_color(t_all *s)
{
	t_col col;

	col.f = -1;
	col.c = -1;
	s->col = col;
}
