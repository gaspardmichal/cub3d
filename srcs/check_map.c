/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 11:18:58 by gamichal          #+#    #+#             */
/*   Updated: 2020/06/01 10:54:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

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
		if (!line_is_in_map(MAP, st->map[i]))
			return (ft_printf("unauthorized character, use 'NSWE012 ' ONLY\n"));
		if (get_start_position(i, st))
			return (ft_printf("too many starting positions, use only one\n"));
		if (!st->pos_x || !st->pos_y)
			return (ft_printf("player is out of bounds\n"));
		++i;
	}
	if (st->pos_y == i - 1)
		return (ft_printf("player is out of bounds\n"));
	if (st->pos_x < 0)
		return (ft_printf("starting position was not found\n"));
	if (check_walls(st))
		return (ft_printf("map is not surrounded by walls\n"));
	return (0);
}
