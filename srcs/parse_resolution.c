/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:34:36 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/03 14:29:01 by gamichal         ###   ########lyon.fr   */
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
		return (print_error(ft_printf("Error: R <width> <height>\n") - 31));
	return (0);
}

static int	check_unauthorized_char(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ')
			return (print_error(ft_printf("Error: R <width> <height>\n") - 43));
	}
	return (0);
}

static int	check_width_and_height_len(char **tab)
{
	if (ft_strlen(tab[0]) > 4 || ft_strlen(tab[1]) > 4)
		return (print_error(ft_printf("Error: R <width> <height>\n") - 44));
	return (0);
}

static int	check_res(char **tab, char *line)
{
	if (check_width_and_height(tab) || check_unauthorized_char(line)
			|| check_width_and_height_len(tab))
	{
		ft_free_tab(tab);
		return (-1);
	}
	return (0);
}

int			parse_resolution(t_all *s, char *line)
{
	char	**tab;
	int		i;

	if ((s->mlx.rx > 0 && s->mlx.ry > 0))
		return (print_error(ft_printf("Error: R <width> <height>\n") - 42));
	if (!(tab = ft_split(line, " ")))
		return (print_error2(-3));
	if (check_res(tab, line))
		return (-1);
	i = -1;
	while (tab[++i])
	{
		s->mlx.rx = i == 0 ? ft_atoi(tab[i]) : s->mlx.rx;
		s->mlx.ry = i == 1 ? ft_atoi(tab[i]) : s->mlx.ry;
	}
	ft_free_tab(tab);
	if (!s->mlx.rx || !s->mlx.ry)
		return (print_error(ft_printf("Error: R <width> <height>\n") - 45));
	if (s->mlx.rx > 5120 || s->mlx.ry > 2880)
	{
		s->mlx.rx = 2560;
		s->mlx.ry = 1400;
	}
	++s->map.info;
	return (0);
}
