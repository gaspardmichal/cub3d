/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:32:58 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/04 10:30:04 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_start_position(int i, t_all *s)
{
	int		j;
	int		it;

	it = 0;
	j = 0;
	while (s->map.grid[i][j])
	{
		if (ft_strchr("NSWE", s->map.grid[i][j]))
		{
			if (s->pos.x >= 0 && s->pos.y >= 0)
				return (-1);
			s->pos.x = j;
			s->pos.y = i;
			s->map.grid[i][j] = '0';
			++it;
		}
		++j;
	}
	if (it > 1)
		return (-1);
	return (0);
}

static int	check_around(char **map, char *err, int i, int j)
{
	if (!i || !j || !map[i + 1] || j == (int)ft_strlen(map[i]) - 1)
		return (ft_printf("%s/!\\ [%d][%d] out of bounds\n", err, i, j));
	if (check_down(map, err, i, j))
		return (-1);
	if (check_left(map, err, i, j))
		return (-1);
	if (check_right(map, err, i, j))
		return (-1);
	if (check_up(map, err, i, j))
		return (-1);
	return (0);
}

static int	check_walls(t_all *s)
{
	int		i;
	int		j;
	char	*err;

	if (!(err = ft_strdup("Error: map not surrounded by walls\n")))
		return (print_error2(-3));
	i = 0;
	while (s->map.grid[i])
	{
		j = 0;
		while (s->map.grid[i][j])
		{
			if (ft_strchr("02NSWE", s->map.grid[i][j]))
			{
				if (check_around(s->map.grid, err, i, j))
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

	if (!s->map.grid)
		return (print_error(-23));
	i = 0;
	while (s->map.grid[i])
	{
		if (get_start_position(i, s))
			return (print_error2(-24));
		if (!s->pos.x || !s->pos.y)
			return (print_error2(-1));
		++i;
	}
	if (s->pos.y == i - 1)
		return (print_error2(-1));
	if (s->pos.x < 0)
		return (print_error2(-2));
	if (check_walls(s))
		return (-1);
	return (0);
}
