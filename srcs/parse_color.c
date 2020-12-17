/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:35:02 by gamichal          #+#    #+#             */
/*   Updated: 2020/12/17 11:53:42 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_format(char *line)
{
	int i;

	if (ft_strcountchr(line, ',') != 2)
		return (print_error(ft_printf("Error: X <r>,<g>,<b>\n") - 41));
	i = 0;
	while (line[i] == ' ')
		++i;
	if (line[i] == ',')
		return (print_error(ft_printf("Error: X <r>,<g>,<b>\n") - 42));
	i = -1;
	while (line[++i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != ',')
			return (print_error(ft_printf("Error: X <r>,<g>,<b>\n") - 38));
	}
	return (0);
}

static int	check_number_of_col(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		++i;
	if (i != 3)
		return (print_error(ft_printf("Error: X <r>,<g>,<b>\n") - 26));
	return (0);
}

static int	check_col(char **tab, char *line)
{
	if (check_number_of_col(tab) || check_format(line))
	{
		ft_free(tab);
		return (-1);
	}
	return (0);
}

static int	atorgb(int r, int g, int b)
{
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (print_error(ft_printf("Error: X <r>,<g>,<b>\n") - 43));
	return ((r << 16) + (g << 8) + b);
}

int			parse_color(t_all *s, char *line, char c)
{
	char	**tab;
	int		i;
	int		col[3];

	if ((s->col->f >= 0 && c == 'F') || (s->col->c >= 0 && c == 'C'))
		return (print_error(ft_printf("Error: X <r>,<g>,<b>\n") - 37));
	if (!(tab = ft_split(line, " ,")))
		return (print_error2(-3));
	if (check_col(tab, line))
		return (-1);
	i = -1;
	while (tab[++i])
		col[i] = ft_atoi(tab[i]);
	ft_free_tab(tab);
	s->col->f = c == 'F' ? atorgb(col[0], col[1], col[2]) : s->col->f;
	s->col->c = c == 'C' ? atorgb(col[0], col[1], col[2]) : s->col->c;
	++s->map->info;
	return (0);
}
