/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:57:40 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/13 08:17:17 by gamichal         ###   ########.fr       */
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

	if ((s->res.width > 0 && s->res.height > 0))
		return (print_error(ft_printf("Error: R <width> <height>\n") - 42));
	if (!(tab = ft_split(line, " ")))
		return (print_error2(-3));
	if (check_res(tab, line))
		return (-1);
	i = -1;
	while (tab[++i])
	{
		s->res.width = i == 0 ? ft_atoi(tab[i]) : s->res.width;
		s->res.height = i == 1 ? ft_atoi(tab[i]) : s->res.height;
	}
	ft_free_tab(tab);
	if (!s->res.width || !s->res.height)
		return (print_error(ft_printf("Error: R <width> <height>\n") - 45));
	if (s->res.width > 5120 || s->res.height > 2880)
	{
		s->res.width = 1920;
		s->res.height = 1080;
	}
	++s->map.info;
	return (0);
}
