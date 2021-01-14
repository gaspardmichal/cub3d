/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:58:59 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/14 15:24:14 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_pars(t_id id)
{
	if (id.x < 0 && id.y < 0)
		print_error(-8);
	if (!id.no)
		print_error(-9);
	if (!id.so)
		print_error(-10);
	if (!id.we)
		print_error(-11);
	if (!id.ea)
		print_error(-12);
	if (!id.s)
		print_error(-13);
	if (id.f < 0)
		print_error(-14);
	if (id.c < 0)
		print_error(-15);
	return (0);
}

int		line_of_map(const char *set, const char *s)
{
	int i;
	int j;

	if (!set || !s || !*set)
		return (0);
	i = 0;
	while (s[i])
	{
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
				break ;
			++j;
			if (!set[j])
				return (0);
		}
		++i;
	}
	return (1);
}

int		pars_id(t_id *id, char *line)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (line[i] == ' ')
		++i;
	if (line[i] == 'R')
		ret = pars_res(id, line + i + 1);
	else if (!ft_strncmp(line + i, "NO", 2))
		ret = pars_txt(&id->no, line + i + 2);
	else if (!ft_strncmp(line + i, "SO", 2))
		ret = pars_txt(&id->so, line + i + 2);
	else if (!ft_strncmp(line + i, "WE", 2))
		ret = pars_txt(&id->we, line + i + 2);
	else if (!ft_strncmp(line + i, "EA", 2))
		ret = pars_txt(&id->ea, line + i + 2);
	else if (line[i] == 'S')
		ret = pars_txt(&id->s, line + i + 1);
	else if (line[i] == 'F')
		ret = pars_col(id, line + i + 1, 'F');
	else if (line[i] == 'C')
		ret = pars_col(id, line + i + 1, 'C');
	return (check_grid(id, line, ret));
}

int		alloc_line_of_map(t_map *map, char *line)
{
	char	**tab;
	int		i;

	i = 0;
	while (map->grid && map->grid[i])
		++i;
	if (!(tab = malloc(sizeof(char **) * (++i + 1))))
		return (ft_exit(line, print_error2(-3)));
	tab[i] = 0;
	if (!(tab[--i] = ft_strdup(line)))
		return (ft_exit(line, print_error2(-3)));
	while (--i >= 0)
	{
		tab[i] = map->grid[i];
		map->grid[i] = NULL;
	}
	ft_free(map->grid);
	map->grid = tab;
	return (ft_exit(line, 0));
}

int		pars_line(t_all *s, char *line)
{
	if (!*line && s->map.grid)
		return (ft_exit(line, print_error(-6)));
	else if (line_of_map("NSWE012 ", line) && *line)
	{
		if (s->id.i == 4)
		{
			if (alloc_line_of_map(&s->map, line))
				return (-1);
		}
		else
		{
			print_error(-7);
			return (ft_exit(line, -1));
		}
	}
	else if (pars_id(&s->id, line))
		return (-1);
	if (s->id.no && s->id.so && s->id.we && s->id.ea && s->id.s && s->id.i == 3)
		++s->id.i;
	return (0);
}
