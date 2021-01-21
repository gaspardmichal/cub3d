/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:59:06 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/21 13:36:53 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Check that no identifier is missing
*/

int			parse_check_identifiers(t_identifiers *id)
{
	if (id->r.x < 0 && id->r.y < 0)
		print_error(-8);
	if (!id->no)
		print_error(-9);
	if (!id->so)
		print_error(-10);
	if (!id->we)
		print_error(-11);
	if (!id->ea)
		print_error(-12);
	if (!id->s)
		print_error(-13);
	if (id->f < 0)
		print_error(-14);
	if (id->c < 0)
		print_error(-15);
	return (0);
}

/*
** Check map description for unauthorized characters
*/

int			parse_check_map_characters(char *line, int count, int ret)
{
	if (*line && count == 4 && ret != -1)
		ret = ft_printf("Error: unauthorized character in map description\n");
	return (ft_exit(line, ret));
}

/*
** Check map validity
*/

static int	map_not_valid(t_map map)
{
	int		i;
	int		j;
	char	*err;

	if (!(err = ft_strdup("Error: map not surrounded by walls\n")))
		return (print_error2(-3));
	i = 0;
	while (map.grid[i])
	{
		j = 0;
		while (map.grid[i][j])
		{
			if (ft_strchr("02NSWE", map.grid[i][j]))
			{
				if (parse_check_walls(map.grid, err, i, j))
					return (ft_exit(err, 1));
			}
			++j;
		}
		++i;
	}
	ft_free(err);
	return (0);
}

/*
** Find player starting position and replace it with an empty space i.e '0'
*/

static int	get_player_position(t_parameters *p, int i)
{
	int		j;
	int		count;

	count = 0;
	j = 0;
	while (p->map.grid[i][j])
	{
		if (ft_strchr("NSWE", p->map.grid[i][j]))
		{
			if (p->ply.pos.x >= 0 && p->ply.pos.y >= 0)
				return (-1);
			p->ply.pos.x = j;
			p->ply.pos.y = i;
			p->map.grid[i][j] = '0';
			++count;
		}
		++j;
	}
	if (count > 1)
		return (-1);
	return (0);
}

int			parse_check_map(t_parameters *p)
{
	int	i;

	if (!p->map.grid)
		return (print_error(-23));
	i = -1;
	while (p->map.grid[++i])
	{
		if (get_player_position(p, i))
			return (print_error2(-24));
		if (!p->ply.pos.x || !p->ply.pos.y)
			return (print_error2(-1));
	}
	if (p->ply.pos.y == i - 1)
		return (print_error2(-1));
	if (p->ply.pos.x < 0)
		return (print_error2(-2));
	if (map_not_valid(p->map))
		return (-1);
	return (0);
}
