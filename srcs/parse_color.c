/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 11:46:10 by gamichal          #+#    #+#             */
/*   Updated: 2020/06/11 16:09:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static int	check_unauthorized_char(char **tab, char *line, char c)
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

static int	check_number_of_colors(char **tab, char c)
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

static int	convert_rgb_color(int r, int g, int b)
{
	/* check color validity here */
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
	if (check_number_of_colors(tab, c))
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
	st->f = c == 'F' ? convert_rgb_color(color[0], color[1], color[2]) : st->f;
	st->c = c == 'C' ? convert_rgb_color(color[0], color[1], color[2]) : st->c;
	++st->map_info;
	return (0);
}
