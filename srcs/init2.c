/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:11:02 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/04 14:45:41 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mlx(t_all *s)
{
	t_mlx mlx;

	mlx.ptr = mlx_init();
	s->mlx = mlx;
	if (OS_LINUX == 1)
	{
		mlx_get_screen_size(mlx.ptr, &s->win.resx, &s->win.resy);
		s->win.x = (s->win.x > s->win.resx) ? s->win.resx : s->win.x;
		s->win.y = (s->win.y > s->win.resy) ? s->win.resy : s->win.y;
	}
	s->win.ptr = mlx_new_window(mlx.ptr, s->win.x, s->win.y, "cub3D");
}

void	init_img(t_all *s)
{
	t_img img;

	img.ptr = NULL;
	img.buf = NULL;
	img.bpp = 32;
	img.size_line = s->win.x * 4;
	img.endian = 0;
	s->img = img;
}
