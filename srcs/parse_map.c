/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:56:01 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/21 08:38:47 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Parse line according to its starting identifier
*/

int	parse_identifiers(t_parameters *p, char *line)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (line[i] == ' ')
		++i;
	if (line[i] == 'R')
		ret = parse_resolution(&p->id, line + i + 1);
	else if (!ft_strncmp(line + i, "NO", 2))
		ret = parse_textures(&p->id.no, line + i + 2);
	else if (!ft_strncmp(line + i, "SO", 2))
		ret = parse_textures(&p->id.so, line + i + 2);
	else if (!ft_strncmp(line + i, "WE", 2))
		ret = parse_textures(&p->id.we, line + i + 2);
	else if (!ft_strncmp(line + i, "EA", 2))
		ret = parse_textures(&p->id.ea, line + i + 2);
	else if (line[i] == 'S')
		ret = parse_textures(&p->id.s, line + i + 1);
	else if (line[i] == 'F')
		ret = parse_colors(&p->id, line + i + 1, 'F');
	else if (line[i] == 'C')
		ret = parse_colors(&p->id, line + i + 1, 'C');
	return (check_map_characters(line, p->id.count, ret));
}

/*
** Allocate line to map into a new map array
*/

int	alloc_map_line(t_map *map, char *line)
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

/*
** Check line contain only map characters i.e map charset : 012NSWE and ' '
*/

int	is_line_of_map(const char *map_charset, const char *line)
{
	int i;
	int j;

	if (!map_charset || !*map_charset || !line)
		return (0);
	i = 0;
	while (line[i])
	{
		j = 0;
		while (map_charset[j])
		{
			if (line[i] == map_charset[j])
				break ;
			++j;
			if (!map_charset[j])
				return (0);
		}
		++i;
	}
	return (-1);
}

/*
** Allocate map once every identifer has been parsed
*/

int	parse_map(t_parameters *p, char *line)
{
	if (!*line && p->map.grid)
		return (ft_exit(line, print_error(-6)));
	else if (is_line_of_map(MAP_CHARSET, line) && *line)
	{
		if (p->id.count == 4)
		{
			if (alloc_map_line(&p->map, line))
				return (-1);
		}
		else
		{
			print_error(-7);
			return (ft_exit(line, -1));
		}
	}
	else if (parse_identifiers(p, line))
		return (-1);
	if (p->id.no && p->id.so && p->id.we && p->id.ea && p->id.s &&
			p->id.count == 3)
		++p->id.count;
	return (0);
}
