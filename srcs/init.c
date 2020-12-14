/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:35:28 by gamichal          #+#    #+#             */
/*   Updated: 2020/12/14 15:25:08 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_mlx	*init_mlx(void)
{
	t_mlx *mlx;

	if (!(mlx = malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->rx = -1;
	mlx->ry = -1;
	return (mlx);
}

t_map	*init_map(void)
{
	t_map *map;

	if (!(map = malloc(sizeof(t_map))))
		return (NULL);
	map->grid = NULL;
	map->info = 0;
	return (map);
}

t_p		*init_player(void)
{
	t_p	*p;

	if (!(p = malloc(sizeof(t_p))))
		return (NULL);
	p->x = -1;
	p->y = -1;
	return (p);
}

t_txt	*init_texture(void)
{
	t_txt *txt;

	if (!(txt = malloc(sizeof(t_txt))))
		return (NULL);
	txt->no = NULL;
	txt->so = NULL;
	txt->we = NULL;
	txt->ea = NULL;
	txt->s = NULL;
	return (txt);
}

t_col	*init_color(void)
{
	t_col *col;

	if (!(col = malloc(sizeof(t_col))))
		return (NULL);
	col->f = -1;
	col->c = -1;
	return (col);
}
