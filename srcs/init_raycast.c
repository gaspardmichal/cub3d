/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:57:19 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/13 12:16:48 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		init_mlx(t_all *s)
{
	t_mlx	mlx;

	if (!(mlx.ptr = mlx_init()))
		return (-1);
	s->mlx = mlx;
	return (0);
}

int		init_win(t_all *s)
{
	t_win win;

	win.x = s->res.width;
	win.y = s->res.height;
	if (OS_LINUX == 1)
	{
		mlx_get_screen_size(s->mlx.ptr, &win.sizex, &win.sizey);
		win.x = (win.x > win.sizex) ? win.sizex : win.x;
		win.y = (win.y > win.sizey) ? win.sizey : win.y;
	}
	if (!(win.ptr = mlx_new_window(s->mlx.ptr, win.x, win.y, "cub3D")))
		return (-1);
	s->win = win;
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
	img.ptr = mlx_new_image(s->mlx.ptr, s->win.x, s->win.y);
	img.buf = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endian);
	s->img = img;
}

void	init_ray(t_all *s)
{
	t_ray ray;

	ray.dirx = 0;
	ray.diry = 0;
	ray.planx = 0;
	ray.plany = 0;
	ray.raydirx = 0;
	ray.raydiry = 0;
	ray.camerax = 0;
	ray.mapx = 0;
	ray.mapy = 0;
	ray.sidedistx = 0;
	ray.sidedisty = 0;
	ray.stepx = 0;
	ray.stepy = 0;
	ray.hit = 0;
	ray.side = 0;
	ray.perpwalldist = 0;
	ray.lineheight = 0;
	ray.drawstart = 0;
	ray.drawend = 0;
	ray.x = 0;
	s->ray = ray;
}
