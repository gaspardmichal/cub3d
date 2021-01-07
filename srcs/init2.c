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

int		init_mlx(t_all *s)
{
	t_mlx mlx;

	if (!(mlx.ptr = mlx_init()))
		return (print_error2(-3));
	s->mlx = mlx;
	if (OS_LINUX == 1)
	{
		mlx_get_screen_size(mlx.ptr, &s->win.resx, &s->win.resy);
		s->win.x = (s->win.x > s->win.resx) ? s->win.resx : s->win.x;
		s->win.y = (s->win.y > s->win.resy) ? s->win.resy : s->win.y;
	}
	if (!(s->win.ptr = mlx_new_window(mlx.ptr, s->win.x, s->win.y, "cub3D")))
		return (print_error2(-3));
	return (0);
}

void	init_img(t_all *s)
{
	t_img img;

	img.ptr = NULL;
	img.buf = NULL;
	img.bpp = 32;
	img.size_line = s->win.x * 4;
	img.endian = 0;
	img.ptr = mlx_new_image(s->mlx.ptr, s->win.x, w->win.y);
	img.buf = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endian);
	s->img = img;
}
