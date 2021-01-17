/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:17:25 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/17 09:17:34 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Check that the resolution format is precisely two integers
*/

int	check_resolution_format(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		++i;
	if (i != 2)
		return (print_error(ft_printf("Error: R <width> <height>\n") - 31));
	return (0);
}

/*
** Check that the width and height format is four digits or less
*/

int	check_value(char **tab)
{
	if (ft_strlen(tab[0]) > 4 || ft_strlen(tab[1]) > 4)
		return (print_error(ft_printf("Error: R <width> <height>\n") - 44));
	return (0);
}

/*
** Check that the resolution does not contain any unauthorized character
*/

int	check_characters(char *line)
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

/*
** Check the return values of the above functions
*/

int	check_resolution(char **tab, char *line)
{
	if (check_resolution_format(tab) || check_value(tab)
			|| check_characters(line))
	{
		ft_free(tab);
		return (-1);
	}
	return (0);
}

int	parse_resolution(t_parameters *p, char *line)
{
	char	**tab;
	int		i;

	if ((p->mlx.width > 0 && p->mlx.height > 0))
		return (print_error(ft_printf("Error: R <width> <height>\n") - 42));
	if (!(tab = ft_split(line, " ")))
		return (print_error2(-3));
	if (check_resolution(tab, line))
		return (-1);
	i = -1;
	while (tab[++i])
	{
		p->mlx.width = i == 0 ? ft_atoi(tab[i]) : p->mlx.width;
		p->mlx.height = i == 1 ? ft_atoi(tab[i]) : p->mlx.height;
	}
	ft_free_tab(tab);
	if (!p->mlx.width || !p->mlx.height)
		return (print_error(ft_printf("Error: R <width> <height>\n") - 45));
	if (p->mlx.width > 5120 || p->mlx.height > 2880)
	{
		p->mlx.width = 1920;
		p->mlx.height = 1080;
	}
	++p->id.count;
	return (0);
}
