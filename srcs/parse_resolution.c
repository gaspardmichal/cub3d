/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:35:18 by gamichal          #+#    #+#             */
/*   Updated: 2020/10/12 10:13:05 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_width_and_height(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		++i;
	if (i != 2)
	{
		i = -1;
		while (tab[++i])
			ft_free(tab[i]);
		ft_free(tab);
		ft_printf("ERROR: R <int> <int>\n");
		return (ft_printf("/!\\ wrong nb of arguments\n"));
	}
	return (0);
}

static int	check_unauthorized_char(char **tab, char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ')
		{
			while (tab[j])
			{
				ft_free(tab[j]);
				++j;
			}
			ft_free(tab);
			ft_printf("ERROR: R <int> <int>\n");
			return (ft_printf("/!\\ unauthorized character, '0-9 ' ONLY\n"));
		}
		++i;
	}
	return (0);
}

int			parse_resolution(t_struc *st, char *line)
{
	char	**tab;
	int		i;

	if ((st->width > 0 && st->height > 0))
		return (ft_printf("ERROR: resolution is described more than once\n"));
	tab = ft_split(line, " ");
	if (check_unauthorized_char(tab, line) || check_width_and_height(tab))
		return (1);
	i = -1;
	while (tab[++i])
	{
		st->width = i == 0 ? ft_atoi(tab[i]) : st->width;
		st->height = i == 1 ? ft_atoi(tab[i]) : st->height;
		ft_free(tab[i]);
	}
	ft_free(tab);
	if (!st->width || !st->height)
		return (ft_printf("ERROR: width or height is zero\n"));
	if (st->width > 2880 || st->height > 1800)
	{
		st->width = 2880;
		st->height = 1800;
	}
	++st->map_info;
	return (0);
}
