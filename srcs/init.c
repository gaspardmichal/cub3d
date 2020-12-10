/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:09:53 by gamichal          #+#    #+#             */
/*   Updated: 2020/12/10 14:57:58 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_map			*init_map(void)
{
	t_map *map;

	if (!(map = malloc(sizeof(t_map))))
		return (NULL);
	map->grid = NULL;
	map->info = 0;
	return (map);
}

t_player		*init_player(void)
{
	t_player *player;

	if (!(player = malloc(sizeof(t_player))))
		return (NULL);
	player->x = -1;
	player->y = -1;
	return (player);
}

t_resolution	*init_resolution(void)
{
	t_resolution *resolution;

	if (!(resolution = malloc(sizeof(t_resolution))))
		return (NULL);
	resolution->x = -1;
	resolution->y = -1;
	return (resolution);
}

t_texture		*init_texture(void)
{
	t_texture		*texture;

	if (!(texture = malloc(sizeof(t_texture))))
		return (NULL);
	texture->no = NULL;
	texture->so = NULL;
	texture->we = NULL;
	texture->ea = NULL;
	texture->s = NULL;
	return (texture);
}

t_color			*init_color(void)
{
	t_color *color;

	if (!(color = malloc(sizeof(t_color))))
		return (NULL);
	color->f = -1;
	color->c = -1;
	return (color);
}
