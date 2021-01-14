/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:50:54 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/14 15:26:28 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		get_start_pos(t_map *map, int i)
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

int		check_cell(char **grid, char *err, int i, int j)
{
	if (!i || !j || !grid[i + 1] || j == (int)ft_strlen(grid[i]) - 1)
		return (ft_printf("%s/!\\ [%d][%d] out of bounds\n", err, i, j));
	if (check_down(grid, err, i, j))
		return (-1);
	if (check_left(grid, err, i, j))
		return (-1);
	if (check_right(grid, err, i, j))
		return (-1);
	if (check_up(grid, err, i, j))
		return (-1);
	return (0);
}

int		check_walls(t_map *map)
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
				if (check_cell(map->grid, err, i, j))
					return (ft_exit(err, 1));
			}
			++j;
		}
		++i;
	}
	ft_free(err);
	return (0);
}

int		check_map(t_map *map)
{
	int	i;

	if (!map->grid)
		return (print_error(-23));
	i = -1;
	while (map->grid[++i])
	{
		if (get_start_pos(map, i))
			return (print_error2(-24));
		if (!map->x || !map->y)
			return (print_error2(-1));
	}
	if (map->y == i - 1)
		return (print_error2(-1));
	if (map->x < 0)
		return (print_error2(-2));
	if (check_walls(map))
		return (-1);
	return (0);
}
