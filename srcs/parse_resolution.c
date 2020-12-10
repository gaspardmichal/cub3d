/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:35:18 by gamichal          #+#    #+#             */
/*   Updated: 2020/12/10 12:43:53 by gamichal         ###   ########lyon.fr   */
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
		ft_printf("Error: R <int> <int>\n");
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
			ft_printf("Error: R <int> <int>\n");
			return (ft_printf("/!\\ unauthorized character, '0-9 ' ONLY\n"));
		}
	}
	return (0);
}

static int	check_width_and_height_len(char **tab)
{
	if (ft_strlen(tab[0]) > 4 || ft_strlen(tab[1]) > 4)
		return (ft_printf("Error: height or width number is too high\n"));
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

int			parse_resolution(t_data *d, char *line)
{
	char	**tab;
	int		i;

	if ((d->res->x > 0 && d->res->y > 0))
		return (ft_printf("Error: resolution is described more than once\n"));
	if (!(tab = ft_split(line, " ")) || check_resolution_integrity(tab, line))
		return (1);
	i = -1;
	while (tab[++i])
	{
		d->res->x = i == 0 ? ft_atoi(tab[i]) : d->res->x;
		d->res->y = i == 1 ? ft_atoi(tab[i]) : d->res->y;
	}
	ft_free_tab(tab);
	if (!d->res->x || !d->res->y)
		return (ft_printf("Error: width or height is zero\n"));
	++d->map->info;
	return (0);
}
