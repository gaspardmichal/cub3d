/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:35:05 by gamichal          #+#    #+#             */
/*   Updated: 2020/10/10 13:11:35 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_parsing(t_struc *st)
{
	int ret;

	ret = 0;
	if (st->width < 0 && st->height < 0)
		ret = ft_printf("/!\\ missing resolution\n");
	if (!st->no)
		ret = ft_printf("/!\\ missing northern texture\n");
	if (!st->so)
		ret = ft_printf("/!\\ missing southern texture\n");
	if (!st->we)
		ret = ft_printf("/!\\ missing western texture\n");
	if (!st->ea)
		ret = ft_printf("/!\\ missing eastern texture\n");
	if (!st->s)
		ret = ft_printf("/!\\ missing sprite texture\n");
	if (st->f < 0)
		ret = ft_printf("/!\\ missing floor color\n");
	if (st->c < 0)
		ret = ft_printf("/!\\ missing ceiling color\n");
	return (ret > 0 ? 1 : 0);
}

int		line_is_in_map(const char *set, const char *s)
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

int		parse_line(t_struc *st, char *line)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (line[i] == ' ')
		++i;
	if (line[i] == 'R')
		ret = parse_resolution(st, line + i + 1);
	else if (!ft_strncmp(line + i, "NO", 2))
		ret = parse_texture(&st->no, line + i + 2, "NO");
	else if (!ft_strncmp(line + i, "SO", 2))
		ret = parse_texture(&st->so, line + i + 2, "SO");
	else if (!ft_strncmp(line + i, "WE", 2))
		ret = parse_texture(&st->we, line + i + 2, "WE");
	else if (!ft_strncmp(line + i, "EA", 2))
		ret = parse_texture(&st->ea, line + i + 2, "EA");
	else if (line[i] == 'S')
		ret = parse_texture(&st->s, line + i + 1, "S");
	else if (line[i] == 'F')
		ret = parse_color(st, line + i + 1, 'F');
	else if (line[i] == 'C')
		ret = parse_color(st, line + i + 1, 'C');
	return (check_map_char(st, line, ret));
}

int		allocate_map(t_struc *st, char *line)
{
	char	**tab;
	int		i;

	i = 0;
	while (st->map && st->map[i])
		++i;
	if (!(tab = malloc(sizeof(char **) * (++i + 1))))
		return (ft_exit(line, 1));
	tab[i] = 0;
	tab[--i] = ft_strdup(line);
	while (--i >= 0)
	{
		tab[i] = st->map[i];
		st->map[i] = NULL;
	}
	ft_free(st->map);
	st->map = tab;
	return (ft_exit(line, 0));
}

int		parse_map(t_struc *st, char *line)
{
	if (!*line && st->map)
	{
		ft_printf("ERROR: empty line in map description\n");
		return (ft_exit(line, 1));
	}
	else if (line_is_in_map(MAP, line) && *line)
	{
		if (st->map_info == 4)
		{
			if (allocate_map(st, line))
				return (1);
		}
		else
		{
			ft_printf("ERROR: map description is not last\n");
			check_parsing(st);
			return (ft_exit(line, 1));
		}
	}
	else if (parse_line(st, line))
		return (1);
	if (st->no && st->so && st->we && st->ea && st->s && st->map_info == 3)
		++st->map_info;
	return (0);
}
