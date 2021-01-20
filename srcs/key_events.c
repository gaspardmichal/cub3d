/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:33:25 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/20 17:05:24 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_released(int key, t_parameters *p)
{
	if (key == W)
		p->ply.walk_dir = 0;
	if (key == S)
		p->ply.walk_dir = 0;
	/*if (k == A)
	{

	}
	if (key == D)
	{

	}*/
	if (key == LEFT_ARROW)
		p->ply.turn_dir = 0;
	if (key == RIGHT_ARROW)
		p->ply.turn_dir = 0;
	return (0);
}

int	key_pressed(int key, t_parameters *p)
{
	if (key == W)
		p->ply.walk_dir = +1;
	if (key == S)
		p->ply.walk_dir = -1;
	/*if (k == A)
	{

	}
	if (key == D)
	{

	}*/
	if (key == RIGHT_ARROW)
		p->ply.turn_dir = +1;
	if (key == LEFT_ARROW)
		p->ply.turn_dir = -1;
	return (0);
}
