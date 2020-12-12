/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:09:53 by gamichal          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/12/12 15:57:57 by gamichal         ###   ########lyon.fr   */
=======
/*   Updated: 2020/12/11 11:17:12 by gamichal         ###   ########lyon.fr   */
>>>>>>> 5c228cfb11d9b811f519347160044789ce1bfdc1
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_map			*init_map_struct(void)
{
	t_map *map;

	if (!(map = malloc(sizeof(t_map))))
		return (NULL);
	map->grid = NULL;
	map->info = 0;
	return (map);
}

t_player		*init_player_struct(void)
{
	t_player *p;

	if (!(p = malloc(sizeof(t_player))))
		return (NULL);
	p->x = -1;
	p->y = -1;
	return (p);
}

t_resolution	*init_resolution_struct(void)
{
	t_resolution *res;

	if (!(res = malloc(sizeof(t_resolution))))
		return (NULL);
	res->x = -1;
	res->y = -1;
	return (res);
}

t_texture		*init_texture_struct(void)
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

t_color			*init_color_struct(void)
{
	t_color *col;

	if (!(col = malloc(sizeof(t_color))))
		return (NULL);
	col->f = -1;
	col->c = -1;
	return (col);
}
