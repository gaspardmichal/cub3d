/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:21:09 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/22 12:53:29 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

static void	set_vectors(t_parameters *p)
{
	p->ply.cam.x = 2 * p->dis.x / (double)p->mlx.height - 1;
	p->ray.dir.x = p->ply.dir.x + p->ray.plan.x * p->ply.cam.x;
	p->ray.dir.y = p->ply.dir.y + p->ray.plan.y * p->ply.cam.x;
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
		p->ray.side.x = (p->map.cell.x + 1.0 - p->ply.pos.x) * p->ray.delta.x;
	}
	if (p->ray.dir.y < 0)
	{
		p->ray.step.y = -1;
		p->ray.side.y = (p->ply.pos.y - p->map.cell.y) * p->ray.delta.y;
	}
	else
	{
		p->ray.step.y = -1;
		p->ray.side.y = (p->map.cell.y + 1.0 - p->ply.pos.y) * p->ray.delta.y;
	}
}

static void	get_wall_hit(t_parameters *p)
{
	while (!p->wall.hit)
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
		if (p->map.grid[p->map.cell.x][p->map.cell.y] == '1')
			p->wall.hit = 1;
	}
}

static void	get_wall_height(t_parameters *p)
{
	if (!p->wall.side)
		p->wall.dist = (p->map.cell.x - p->ply.pos.x
				+ (1 - p->ray.step.x) / 2) / p->ray.dir.x;
	else
		p->wall.dist = (p->map.cell.y - p->ply.pos.y
				+ (1 - p->ray.step.y) / 2) / p->ray.dir.y;
	p->wall.height = (int)(p->mlx.height / p->wall.dist);
	p->wall.start = -p->wall.height / 2 + p->mlx.height / 2;
	if (p->wall.start < 0)
		p->wall.start = 0;
	p->wall.end = p->wall.height / 2 + p->mlx.height / 2;
	if (p->wall.end >= p->mlx.height)
		p->wall.end = p->mlx.height - 1;
}

void		render_walls(t_parameters *p)
{
	set_vectors(p);
	set_delta(p);
	get_wall_hit(p);
	get_wall_height(p);
}
