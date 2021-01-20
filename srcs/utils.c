/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:50:51 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/20 14:55:27 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	normalize_angle(double angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

double	distance_between_points(double x1, double x2, double y1, double y2)
{
	return (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}

int		grid_has_wall_at(t_parameters *p)
{
	t_int cell;

	if (p->ply.pos.x < 0 || p->ply.pos.y < 0 || p->ply.pos.x > p->mlx.width ||
			p->ply.pos.y > p->mlx.height)
		return (0);
	cell.x = floor(p->ply.pos.x / TILE_SIZE);
	cell.y = floor(p->ply.pos.y / TILE_SIZE);
	if (p->map.grid[cell.x][cell.y] == '1')
		return (1);
	return (0);
}
