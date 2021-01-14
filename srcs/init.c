/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:36:31 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/14 16:02:09 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_id(t_all *s)
{
	s->id.x = -1;
	s->id.y = -1;
	s->id.no = NULL;
	s->id.so = NULL;
	s->id.we = NULL;
	s->id.ea = NULL;
	s->id.s = NULL;
	s->id.f = -1;
	s->id.c = -1;
	s->id.i = 0;
	s->map.grid = NULL;
	s->map.x = -1;
	s->map.y = -1;
}

void	init_all(t_all *s)
{
	s->mlx.ptr = NULL;
	s->mlx.win = NULL;
	s->mlx.x = s->id.x;
	s->mlx.y = s->id.y;
	if (OS_LINUX == 1)
	{
		mlx_get_screen_size(s->mlx.ptr, &s->mlx.sizex, &s->mlx.sizey);
		s->mlx.x = (s->mlx.x > s->mlx.sizex) ? s->mlx.sizex : s->mlx.x;
		s->mlx.y = (s->mlx.y > s->mlx.sizey) ? s->mlx.sizey : s->mlx.y;
	}
}
