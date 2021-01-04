/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:26:01 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/04 11:39:52 by gamichal         ###   ########lyon.fr   */
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

int			parse_res(t_all *s, char *line)
{
	char	**tab;
	int		i;

	if ((s->win.x > 0 && s->win.y > 0))
		return (print_error(ft_printf("Error: R <width> <height>\n") - 42));
	if (!(tab = ft_split(line, " ")))
		return (print_error2(-3));
	if (check_res(tab, line))
		return (-1);
	i = -1;
	while (tab[++i])
	{
		s->win.x = i == 0 ? ft_atoi(tab[i]) : s->win.x;
		s->win.y = i == 1 ? ft_atoi(tab[i]) : s->win.y;
	}
	ft_free_tab(tab);
	if (!s->win.x || !s->win.y)
		return (print_error(ft_printf("Error: R <width> <height>\n") - 45));
	if (s->win.x > 5120 || s->win.y > 2880)
	{
		s->win.x = 1920;
		s->win.y = 1080;
	}
	++s->map.info;
	return (0);
}
