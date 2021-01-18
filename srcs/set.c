/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 11:27:23 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/17 14:21:31 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_identifiers(t_parameters *p)
{
	p->id.rx = -1;
	p->id.ry = -1;
	p->id.no = NULL;
	p->id.so = NULL;
	p->id.we = NULL;
	p->id.ea = NULL;
	p->id.s = NULL;
	p->id.f = -1;
	p->id.c = -1;
	p->id.count = 0;
	p->map.grid = NULL;
	p->map.x = -1;
	p->map.y = -1;
}

int		set_minilibx(t_parameters *p)
{
	t_minilibx	m;
	int			vm_width;
	int			vm_height;

	
	if (OS_LINUX == 1)
	{
		mlx_get_screen_size(m.ptr, &vm_width, &vm_height);
		m.width = (m.width > vm_width) ? vm_width : m.width;
		m.height = (m.height > vm_height) ? vm_height : m.height;
	}
	else
	{
		m.width = p->id.rx;
		m.height = p->id.ry;
	}
	if (!(m.ptr = mlx_init()))
		return (print_error2(-3));
	if (!(m.win = mlx_new_window(m.ptr, m.width, m.height, "cub3D")))
		return (print_error2(-3));
	if (!(m.img = mlx_new_image(m.ptr, m.width, m.height)))
		return (print_error2(-3));
	if (!(m.pxl = mlx_get_data_addr(m.ptr, &m.bpp, &m.size, &m.endian)))
		return (print_error2(-3));
	p->mlx = m;
	return (0);
}
