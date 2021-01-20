/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 11:27:23 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/20 14:55:47 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_identifiers(t_parameters *p)
{
	p->id.r.x = -1;
	p->id.r.y = -1;
	p->id.no = NULL;
	p->id.so = NULL;
	p->id.we = NULL;
	p->id.ea = NULL;
	p->id.s = NULL;
	p->id.f = -1;
	p->id.c = -1;
	p->id.count = 0;
	p->map.grid = NULL;
	p->ply.pos.x = -1;
	p->ply.pos.y = -1;
}

int		set_minilibx(t_parameters *p)
{
	t_minilibx	m;
	int			vm_width;
	int			vm_height;

	if (OS_LINUX == 1)
	{
		mlx_get_screen_size(m.ptr, &vm_width, &vm_height);
		m.width = (m.width > vm_width) ? vm_width : m.height;
		m.height = (m.height > vm_height) ? vm_height : m.height;
	}
	else
	{
		m.width = p->id.r.x;
		m.height = p->id.r.y;
	}
	if (!(m.ptr = mlx_init()))
		return (print_error2(-3));
	if (!(m.win = mlx_new_window(m.ptr, m.width, m.height, "cub3D")))
		return (print_error2(-3));
	if (!(m.img = mlx_new_image(m.ptr, m.width, m.height)))
		return (print_error2(-3));
	if (!(m.pxl = (int *)mlx_get_data_addr(m.ptr, &m.bpp, &m.size, &m.endian)))
		return (print_error2(-3));
	p->mlx = m;
	return (0);
}

void	set_player(t_parameters *p)
{
	t_player one;

	one.turn_dir = 0;
	one.walk_dir = 0;
	one.rot_angle = M_PI / 2;
	one.move_speed = 5.0;
	one.rot_speed = 2.0 * M_PI;
	p->ply = one;
}
