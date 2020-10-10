/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:34:19 by gamichal          #+#    #+#             */
/*   Updated: 2020/10/10 13:12:34 by gamichal         ###   ########.fr       */
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

static int	check_around(char **map, int i, int j)
{
	char	*err;
	int		ret;

	if (!(err = ft_strdup("ERROR: map not surrounded by walls\n")))
		return (1);
	ret = 0;
	if (i == 0 || j == 0 || map[i + 1] == 0)
		ret = ft_printf("%s/!\\ '%c' in map[%d][%d]\n", err, map[i][j], i, j);
	else if (i)
		ret = check_up(map, err, i, j);
	else if (map[i + 1] != 0)
		ret = check_down(map, err, i, j);
	else if (j)
		ret = check_left(map, err, i, j);
	else if (j != (int)ft_strlen(map[i]))
		ret = check_right(map, err, i, j);
	return (ret > 0 ? ft_exit(err, ret) : ret);
}

static int	check_walls(t_struc *st)
{
	int i;
	int j;

	i = 0;
	while (st->map[i])
	{
		j = 0;
		while (st->map[i][j])
		{
			if (ft_strchr("02NSWE", st->map[i][j]))
			{
				if (check_around(st->map, i, j))
					return (1);
			}
			++j;
		}
		++i;
	}
	return (0);
}

int			check_map(t_struc *st)
{
	int	i;

	i = 0;
	while (st->map[i])
	{
		if (get_start_position(i, st))
			return (ft_printf("ERROR: too many start positions\n"));
		if (!st->pos_x || !st->pos_y)
			return (ft_printf("ERROR: start position out of bounds\n"));
		++i;
	}
	if (st->pos_y == i - 1)
		return (ft_printf("ERROR: start position out of bounds\n"));
	if (st->pos_x < 0)
		return (ft_printf("ERROR: no start position\n"));
	if (check_walls(st))
		return (1);
	return (0);
}
