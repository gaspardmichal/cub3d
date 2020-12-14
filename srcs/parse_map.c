/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:32:58 by gamichal          #+#    #+#             */
/*   Updated: 2020/12/14 10:05:34 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_start_position(int i, t_all *s)
{
	int		j;
	int		it;

	it = 0;
	j = 0;
	while (s->map->grid[i][j])
	{
		if (ft_strchr("NSWE", s->map->grid[i][j]))
		{
			if (s->p->x >= 0 && s->p->y >= 0)
				return (1);
			s->p->x = j;
			s->p->y = i;
			++it;
		}
		++j;
	}
	if (it > 1)
		return (1);
	return (0);
}

static int	check_around(char **map, char *err, int i, int j)
{
	if (!i || !j || !map[i + 1] || j == (int)ft_strlen(map[i]) - 1)
		return (ft_printf("%s/!\\ [%d][%d] out of bounds\n", err, i, j));
	if (check_down(map, err, i, j))
		return (1);
	if (check_left(map, err, i, j))
		return (1);
	if (check_right(map, err, i, j))
		return (1);
	if (check_up(map, err, i, j))
		return (1);
	return (0);
}

static int	check_walls(t_all *s)
{
	int		i;
	int		j;
	char	*err;

	if (!(err = ft_strdup("Error: map not surrounded by walls\n")))
		return (1);
	i = 0;
	while (s->map->grid[i])
	{
		j = 0;
		while (s->map->grid[i][j])
		{
			if (ft_strchr("02NSWE", s->map->grid[i][j]))
			{
				if (check_around(s->map->grid, err, i, j))
					return (ft_exit(err, 1));
			}
			++j;
		}
		++i;
	}
	ft_free(err);
	return (0);
}

int			parse_map(t_all *s)
{
	int	i;

	if (!s->map->grid)
		return (ft_printf("Error: no map description\n"));
	i = 0;
	while (s->map->grid[i])
	{
		if (get_start_position(i, s))
			return (ft_printf("Error: too many starting positions\n"));
		if (!s->p->x || !s->p->y)
			return (ft_printf("Error: starting position out of bounds\n"));
		++i;
	}
	if (s->p->y == i - 1)
		return (ft_printf("Error: starting position out of bounds\n"));
	if (s->p->x < 0)
		return (ft_printf("Error: no starting position\n"));
	if (check_walls(s))
		return (1);
	return (0);
}
