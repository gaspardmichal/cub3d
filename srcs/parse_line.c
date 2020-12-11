/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 09:01:01 by gamichal          #+#    #+#             */
/*   Updated: 2020/12/11 09:04:10 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Check for potential missing information
*/

int		check_parsing(t_data *d)
{
	int ret;

	ret = 0;
	if (d->res->x < 0 && d->res->y < 0)
		ret = print_error(-8);
	if (!d->text->no)
		ret = print_error(-9);
	if (!d->text->so)
		ret = print_error(-10);
	if (!d->text->we)
		ret = print_error(-11);
	if (!d->text->ea)
		ret = print_error(-12);
	if (!d->text->s)
		ret = print_error(-13);
	if (d->col->f < 0)
		ret = print_error(-14);
	if (d->col->c < 0)
		ret = print_error(-15);
	return (ret);
}

/*
** Check if line only made of map characters "NSWE012 "
*/

int		is_line_of_map(const char *set, const char *s)
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

int		parse_identifiers(t_data *d, char *line)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (line[i] == ' ')
		++i;
	if (line[i] == 'R')
		ret = parse_resolution(d, line + i + 1);
	else if (!ft_strncmp(line + i, "NO", 2))
		ret = parse_texture(&d->text->no, line + i + 2, "NO");
	else if (!ft_strncmp(line + i, "SO", 2))
		ret = parse_texture(&d->text->so, line + i + 2, "SO");
	else if (!ft_strncmp(line + i, "WE", 2))
		ret = parse_texture(&d->text->we, line + i + 2, "WE");
	else if (!ft_strncmp(line + i, "EA", 2))
		ret = parse_texture(&d->text->ea, line + i + 2, "EA");
	else if (line[i] == 'S')
		ret = parse_texture(&d->text->s, line + i + 1, "S");
	else if (line[i] == 'F')
		ret = parse_color(d, line + i + 1, 'F');
	else if (line[i] == 'C')
		ret = parse_color(d, line + i + 1, 'C');
	return (check_map_char(d, line, ret));
}

int		alloc_map_line(t_data *d, char *line)
{
	char	**tab;
	int		i;

	i = 0;
	while (d->map->grid && d->map->grid[i])
		++i;
	if (!(tab = malloc(sizeof(char **) * (++i + 1))))
		return (ft_exit(line, 1));
	tab[i] = 0;
	tab[--i] = ft_strdup(line);
	while (--i >= 0)
	{
		tab[i] = d->map->grid[i];
		d->map->grid[i] = NULL;
	}
	ft_free(d->map->grid);
	d->map->grid = tab;
	return (ft_exit(line, 0));
}

int		parse_line(t_data *d, char *line)
{
	if (!*line && d->map->grid)
		return (ft_exit(line, print_error(-6)));
	else if (is_line_of_map(MAP, line) && *line)
	{
		if (d->map->info == 4)
		{
			if (alloc_map_line(d, line))
				return (-1);
		}
		else
		{
			print_error(-7);
			check_parsing(d);
			return (ft_exit(line, -1));
		}
	}
	else if (parse_identifiers(d, line))
		return (-1);
	if (d->text->no && d->text->so && d->text->we &&
		d->text->ea && d->text->s && d->map->info == 3)
		++d->map->info;
	return (0);
}
