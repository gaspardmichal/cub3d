/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:09:53 by gamichal          #+#    #+#             */
/*   Updated: 2020/12/12 15:57:57 by gamichal         ###   ########lyon.fr   */
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
	t_player *p;

	if (!(p = malloc(sizeof(t_player))))
		return (NULL);
	p->x = -1;
	p->y = -1;
	return (p);
}

t_resolution	*init_resolution(void)
{
	t_resolution *res;

	if (!(res = malloc(sizeof(t_resolution))))
		return (NULL);
	res->x = -1;
	res->y = -1;
	return (res);
}

t_texture		*init_texture(void)
{
	t_texture		*txt;

	if (!(txt = malloc(sizeof(t_texture))))
		return (NULL);
	txt->no = NULL;
	txt->so = NULL;
	txt->we = NULL;
	txt->ea = NULL;
	txt->s = NULL;
	return (txt);
}

t_color			*init_color(void)
{
	t_color *col;

	if (!(col = malloc(sizeof(t_color))))
		return (NULL);
	col->f = -1;
	col->c = -1;
	return (col);
}
