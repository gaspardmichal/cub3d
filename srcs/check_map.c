/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:34:19 by gamichal          #+#    #+#             */
/*   Updated: 2020/10/12 15:46:33 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_start_position(int i, t_struc *st)
{
	int		j;
	int		it;

	it = 0;
	j = 0;
	while (st->map[i][j])
	{
		if (ft_strchr("NSWE", st->map[i][j]))
		{
			if (st->pos_x >= 0 && st->pos_y >= 0)
				return (1);
			st->pos_x = j;
			st->pos_y = i;
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

static int	check_walls(t_struc *st)
{
	int		i;
	int		j;
	char	*err;

	if (!(err = ft_strdup("ERROR: map not surrounded by walls\n")))
		return (1);
	i = 0;
	while (st->map[i])
	{
		j = 0;
		while (st->map[i][j])
		{
			if (ft_strchr("02NSWE", st->map[i][j]))
			{
				if (check_around(st->map, err, i, j))
					return (ft_exit(err, 1));
			}
			++j;
		}
		++i;
	}
	ft_free(err);
	return (0);
}

int			check_map(t_struc *st)
{
	int	i;

	if (!st->map)
		return (ft_printf("ERROR: no map description\n"));
	i = 0;
	while (st->map[i])
	{
		if (get_start_position(i, st))
			return (ft_printf("ERROR: too many starting positions\n"));
		if (!st->pos_x || !st->pos_y)
			return (ft_printf("ERROR: starting position out of bounds\n"));
		++i;
	}
	if (st->pos_y == i - 1)
		return (ft_printf("ERROR: starting position out of bounds\n"));
	if (st->pos_x < 0)
		return (ft_printf("ERROR: no starting position\n"));
	if (check_walls(st))
		return (1);
	return (0);
}
