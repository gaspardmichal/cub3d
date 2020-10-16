/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:35:18 by gamichal          #+#    #+#             */
/*   Updated: 2020/10/16 15:39:28 by gamichal         ###   ########.fr       */
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
		ft_printf("ERROR: R <int> <int>\n");
		return (ft_printf("/!\\ wrong nb of arguments\n"));
	}
	return (0);
}

static int	check_unauthorized_char(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ')
		{
			ft_printf("ERROR: R <int> <int>\n");
			return (ft_printf("/!\\ unauthorized character, '0-9 ' ONLY\n"));
		}
	}
	return (0);
}

static int	check_width_and_height_len(char **tab)
{
	if (ft_strlen(tab[0]) > 4 || ft_strlen(tab[1]) > 4)
		return (ft_printf("ERROR: height or width number is too high\n"));
	return (0);
}

static int	check_resolution_integrity(char **tab, char *line)
{
	if (check_width_and_height(tab) || check_unauthorized_char(line)
			|| check_width_and_height_len(tab))
	{
		ft_free_tab(tab);
		return (1);
	}
	return (0);
}

int			parse_resolution(t_struc *st, char *line)
{
	char	**tab;
	int		i;

	if ((st->width > 0 && st->height > 0))
		return (ft_printf("ERROR: resolution is described more than once\n"));
	if (!(tab = ft_split(line, " ")) || check_resolution_integrity(tab, line))
		return (1);
	i = -1;
	while (tab[++i])
	{
		st->width = i == 0 ? ft_atoi(tab[i]) : st->width;
		st->height = i == 1 ? ft_atoi(tab[i]) : st->height;
	}
	ft_free_tab(tab);
	if (!st->width || !st->height)
		return (ft_printf("ERROR: width or height is zero\n"));
	++st->map_info;
	return (0);
}
