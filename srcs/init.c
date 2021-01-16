/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:36:31 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/16 19:03:24 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_identifiers(t_parameters *p)
{
	p->mlx.width = -1;
	p->mlx.height = -1;
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

void	init_parameters(t_parameters *p)
{
	int vm_width;
	int vm_height;
	
	p->mlx.ptr = NULL;
	p->mlx.win = NULL;
	if (OS_LINUX == 1)
	{
		mlx_get_screen_size(p->mlx.ptr, &vm_width, &vm_height);
		p->mlx.width = (p->mlx.width > vm_width) ? vm_width : p->mlx.width;
		p->mlx.height = (p->mlx.height > vm_height) ? vm_height : p->mlx.height;
	}
}
