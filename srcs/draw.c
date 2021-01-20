/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 09:03:49 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/20 17:03:56 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	update_player(t_parameters *p)
{
	double	move_step;

	move_step = p->ply.walk_dir * p->ply.move_speed;
	p->ply.rot_angle += p->ply.turn_dir * p->ply.rot_speed;
	if (grid_has_wall_at(p))
	{
		p->ply.pos.x += cos(p->ply.rot_angle) * move_step;
		p->ply.pos.y += sin(p->ply.rot_angle) * move_step;
	}
}

void	cast_rays(t_parameters *p)
{
	(void)p;
}

int		draw(t_parameters *p)
{
	update_player(p);
	while (++p->ray.x < p->mlx.width)
		cast_rays(p);
	return (0);
}
