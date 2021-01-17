/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:15:38 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/17 09:15:50 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_identifiers(t_parameters *p)
{
	if (p->mlx.width < 0 && p->mlx.height < 0)
		print_error(-8);
	if (!p->id.no)
		print_error(-9);
	if (!p->id.so)
		print_error(-10);
	if (!p->id.we)
		print_error(-11);
	if (!p->id.ea)
		print_error(-12);
	if (!p->id.s)
		print_error(-13);
	if (p->id.f < 0)
		print_error(-14);
	if (p->id.c < 0)
		print_error(-15);
	return (0);
}

int	check_map_characters(char *line, int count, int ret)
{
	if (*line && count == 4 && ret != -1)
		ret = ft_printf("Error: unauthorized character in map description\n");
	return (ft_exit(line, ret));
}

int	map_not_valid(t_map *map)
{
	int		i;
	int		j;
	char	*err;

	if (!(err = ft_strdup("Error: map not surrounded by walls\n")))
		return (print_error2(-3));
	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (ft_strchr("02NSWE", map->grid[i][j]))
			{
				if (check_walls(map->grid, err, i, j))
					return (ft_exit(err, 1));
			}
			++j;
		}
		++i;
	}
	ft_free(err);
	return (0);
}

int	get_start_position(t_map *map, int i)
{
	int		j;
	int		count;

	count = 0;
	j = 0;
	while (map->grid[i][j])
	{
		if (ft_strchr("NSWE", map->grid[i][j]))
		{
			if (map->x >= 0 && map->y >= 0)
				return (-1);
			map->x = j;
			map->y = i;
			map->grid[i][j] = '0';
			++count;
		}
		++j;
	}
	if (count > 1)
		return (-1);
	return (0);
}

int	check_map(t_map *map)
{
	int	i;

	if (!map->grid)
		return (print_error(-23));
	i = -1;
	while (map->grid[++i])
	{
		if (get_start_position(map, i))
			return (print_error2(-24));
		if (!map->x || !map->y)
			return (print_error2(-1));
	}
	if (map->y == i - 1)
		return (print_error2(-1));
	if (map->x < 0)
		return (print_error2(-2));
	if (map_not_valid(map))
		return (-1);
	return (0);
}
