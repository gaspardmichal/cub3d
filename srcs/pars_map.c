/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:58:59 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/07 17:02:50 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Check for potential missing information
*/

int		check_pars(t_all *s)
{
	if (s->res.width < 0 && s->res.height < 0)
		print_error(-8);
	if (!s->txt.no)
		print_error(-9);
	if (!s->txt.so)
		print_error(-10);
	if (!s->txt.we)
		print_error(-11);
	if (!s->txt.ea)
		print_error(-12);
	if (!s->txt.s)
		print_error(-13);
	if (s->col.f < 0)
		print_error(-14);
	if (s->col.c < 0)
		print_error(-15);
	return (0);
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

int		parse_res_txt_col(t_all *s, char *line)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (line[i] == ' ')
		++i;
	if (line[i] == 'R')
		ret = parse_res(s, line + i + 1);
	else if (!ft_strncmp(line + i, "NO", 2))
		ret = parse_txt(&s->txt.no, line + i + 2);
	else if (!ft_strncmp(line + i, "SO", 2))
		ret = parse_txt(&s->txt.so, line + i + 2);
	else if (!ft_strncmp(line + i, "WE", 2))
		ret = parse_txt(&s->txt.we, line + i + 2);
	else if (!ft_strncmp(line + i, "EA", 2))
		ret = parse_txt(&s->txt.ea, line + i + 2);
	else if (line[i] == 'S')
		ret = parse_txt(&s->txt.s, line + i + 1);
	else if (line[i] == 'F')
		ret = parse_col(s, line + i + 1, 'F');
	else if (line[i] == 'C')
		ret = parse_col(s, line + i + 1, 'C');
	return (check_grid(s, line, ret));
}

int		alloc_line_of_map(t_all *s, char *line)
{
	char	**tab;
	int		i;

	i = 0;
	while (s->map.grid && s->map.grid[i])
		++i;
	if (!(tab = malloc(sizeof(char **) * (++i + 1))))
		return (ft_exit(line, print_error2(-3)));
	tab[i] = 0;
	if (!(tab[--i] = ft_strdup(line)))
		return (ft_exit(line, print_error2(-3)));
	while (--i >= 0)
	{
		tab[i] = s->map.grid[i];
		s->map.grid[i] = NULL;
	}
	ft_free(s->map.grid);
	s->map.grid = tab;
	return (ft_exit(line, 0));
}

int		parse_line(t_all *s, char *line)
{
	if (!*line && s->map.grid)
		return (ft_exit(line, print_error(-6)));
	else if (is_line_of_map(MAP, line) && *line)
	{
		if (s->map.info == 4)
		{
			if (alloc_line_of_map(s, line))
				return (-1);
		}
		else
		{
			print_error(-7);
			return (ft_exit(line, -1));
		}
	}
	else if (parse_res_txt_col(s, line))
		return (-1);
	if (s->txt.no && s->txt.so && s->txt.we &&
		s->txt.ea && s->txt.s && s->map.info == 3)
		++s->map.info;
	return (0);
}