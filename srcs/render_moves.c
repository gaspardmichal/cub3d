/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:10:16 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/23 16:55:10 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	walk_forward(t_parameters *p)
{
	double	move_speed;
	int		stepx;
	int		stepy;

	speed = 0.07;
	stepx = p->ply.pos.x + p->ray.dir.x * speed;
	stepy = p->ply.pos.x + p->ray.dir.x * speed;
	if (p->map.grid[stepx][(int)p->ply.pos.y] != '1')
		p->ply.pos.x += p->ray.dir.x * speed;
	if (p->map.grid[(int)p->ply.pos.x][stepy] != '1')
		p->ply.pos.y += p->ray.dir.y * speed;
}

static void	walk_backward(t_parameters *p)
{

}

static void	walk_left(t_parameters *p)
{

}

static void	walk_right(t_parameters *p)
{

}

void		render_moves(t_parameters *p)
{
	if (p->ply.move.forward)
		walk_forward(p);
	if (p->ply.move.backward)
		walk_backward(p);
	if (p->ply.move.left)
		walk_left(p);
	if (p->ply.move.right)
		walk_right(p);
}
