/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:34:52 by gamichal          #+#    #+#             */
/*   Updated: 2020/10/10 10:43:23 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_color_format(char *line, int c)
{
	int i;

	if (ft_strcountchr(line, ',') != 2)
	{
		ft_printf("ERROR: %c <int>,<int>,<int>\n", c);
		return (ft_printf("/!\\ wrong number of commas\n"));
	}
	i = 0;
	while (line[i] == ' ')
		++i;
	if (line[i] == ',')
	{
		ft_printf("ERROR: %c <int>,<int>,<int>\n", c);
		return (ft_printf("/!\\ comma placed before first color\n"));
	}
	return (0);
}

static int	check_unauthorized_char(char **tab, char *line, int c)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != ',')
		{
			while (tab[j])
			{
				ft_free(tab[j]);
				++j;
			}
			free(tab);
			ft_printf("ERROR: %c <int>,<int>,<int>\n", c);
			return (ft_printf("/!\\ unauthorized character, '0-9 ,' ONLY\n"));
		}
		++i;
	}
	return (0);
}

static int	check_number_of_colors(char **tab, int c)
{
	int i;

	i = 0;
	while (tab[i])
		++i;
	if (i != 3)
	{
		i = -1;
		while (tab[++i])
			ft_free(tab[i]);
		ft_free(tab);
		ft_printf("ERROR: %c <int>,<int>,<int>\n", c);
		return (ft_printf("/!\\ wrong nb of colors\n"));
	}
	return (0);
}

static int	convert_rgb(int r, int g, int b, int c)
{
	if (r < 0 || r > 255)
	{
		ft_printf("ERROR: %c <int>,<int>,<int>\n", c);
		ft_printf("/!\\ invalid value for the first <int> (red)\n");
		return (-1);
	}
	if (g < 0 || g > 255)
	{
		ft_printf("ERROR: %c <int>,<int>,<int>\n", c);
		ft_printf("/!\\ invalid value for the second <int> (green)\n");
		return (-1);
	}
	if (b < 0 || b > 255)
	{
		ft_printf("ERROR: %c <int>,<int>,<int>\n", c);
		ft_printf("/!\\ invalid value for third <int> (blue)\n");
		return (-1);
	}
	return ((r << 16) + (g << 8) + b);
}

int			parse_color(t_struc *st, char *line, char c)
{
	char	**tab;
	int		i;
	int		color[3];

	if (st->f >= 0 && c == 'F')
		return (ft_printf("ERROR: floor color described more than once\n"));
	if (st->c >= 0 && c == 'C')
		return (ft_printf("ERROR: ceiling color described more than once\n"));
	tab = ft_split(line, " ,");
	if (check_number_of_colors(tab, c) || check_color_format(line, c))
		return (1);
	if (check_unauthorized_char(tab, line, c))
		return (1);
	i = 0;
	while (tab[i])
	{
		color[i] = ft_atoi(tab[i]);
		ft_free(tab[i]);
		++i;
	}
	ft_free(tab);
	st->f = c == 'F' ? convert_rgb(color[0], color[1], color[2], c) : st->f;
	st->c = c == 'C' ? convert_rgb(color[0], color[1], color[2], c) : st->c;
	++st->map_info;
	return (0);
}
