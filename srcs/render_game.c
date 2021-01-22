/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:24:43 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/22 13:09:55 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render_game(t_parameters *p)
{
	render_moves(p);
	p->dis.x = -1;
	while (++p->dis.x < p->mlx.width)
	{
		render_walls(p);
	}
	return (0);
}
