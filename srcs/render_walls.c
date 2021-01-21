/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:21:09 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/21 15:57:33 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

static void	set_vectors(t_parameters *p)
{
	p->ply.cam.x = 2 * p->dis.x / (double)p->mlx.width - 1;
	p->ray.dir.x = p->ply.dir.x + p->ray.plane.x + p->ply.cam.x;
	p->ray.dir.y = p->ply.dir.y + p->ray.plane.y + p->ply.cam.x;
	p->map.cell.x = (int)p->ply.pos.x;
	p->map.cell.y = (int)p->ply.pos.y;
	p->ray.delta.x = sqrt(1 + (p->ray.dir.y * p->ray.dir.y)
	/ (p->ray.dir.x * p->ray.dir.x));
	p->ray.delta.y = sqrt(1 + (p->ray.dir.x * p->ray.dir.x)
	/ (p->ray.dir.y * p->ray.dir.y));
	p->wall.hit = 0;
}

static void	set_delta(t_parameters *p)
{
	if (p->ray.dir.x < 0)
	{
		p->ray.step.x = -1;
		p->ray.side.x = (p->ply.pos.x - p->map.cell.x) * p->ray.delta.x;
	}
	else
	{
		p->ray.step.x = 1;
		p->ray.side.x = (p->map.cell.x + 1 - p->ply.pos.x) * p->ray.delta.x;
	}
	if (p->ray.dir.y < 0)
	{
		p->ray.step.y = -1;
		p->ray.side.y = (p->ply.pos.y - p->map.cell.y) * p->ray.delta.y;
	}
	else
	{
		p->ray.step.y = 1;
		p->ray.side.y = (p->map.cell.y + 1 - p->ply.pos.y) * p->ray.delta.y;
	}
}

static void	get_wall_hit(t_parameters *p)
{
	while (p->wall.hit == 0)
	{
		if (p->ray.side.x < p->ray.side.y)
		{
			p->ray.side.x += p->ray.delta.x;
			p->map.cell.x += p->ray.step.x;
			p->wall.side = 0;
		}
		else
		{
			p->ray.side.y += p->ray.delta.y;
			p->map.cell.y += p->ray.step.y;
			p->wall.side = 1;
		}
		printf("%f	%f\n", p->map.cell.x, p->map.cell.y);
		if (p->map.grid[(int)p->map.cell.x][(int)p->map.cell.y] == '1')
			p->wall.hit = 1;
	}
}

void		render_walls(t_parameters *p)
{
	set_vectors(p);
	set_delta(p);
	get_wall_hit(p);
}
