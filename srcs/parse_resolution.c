/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:34:36 by gamichal          #+#    #+#             */
/*   Updated: 2020/12/12 20:34:48 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_width_and_height(char **tab)			//21
{
	int i;

	i = 0;
	while (tab[i])
		++i;
	if (i != 2)
		return (print_error(ft_printf("Error: R <int> <int>\n") - 36));
	return (0);
}

static int	check_unauthorized_char(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ')
			return (print_error(ft_printf("Error: R <int> <int>\n") - 37));
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

int			parse_resolution(t_data *s, char *line)
{
	char	**tab;
	int		i;

	if ((s->res->x > 0 && s->res->y > 0))
		return (ft_printf("Error: resolution is described more than once\n"));
	if (!(tab = ft_split(line, " ")) || check_resolution_integrity(tab, line))
		return (1);
	i = -1;
	while (tab[++i])
	{
		s->res->x = i == 0 ? ft_atoi(tab[i]) : s->res->x;
		s->res->y = i == 1 ? ft_atoi(tab[i]) : s->res->y;
	}
	ft_free_tab(tab);
	if (!s->res->x || !s->res->y)
		return (ft_printf("Error: width or height is zero\n"));
	if (s->res->x > 5120 || s->res->y > 2880)
	{
		s->res->x = 2560;
		s->res->y = 1400;
	}
	++s->map->info;
	return (0);
}
