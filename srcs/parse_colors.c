/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:04:48 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/16 20:34:09 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
* * Check the number and places of the commas in the color format
*/

int	check_commas(char *line)
{
	int i;

	if (ft_strcountchr(line, ',') != 2)
		return (print_error(ft_printf("Error: X <r>,<g>,<b>\n") - 41));
	i = 0;
	while (line[i] == ' ')
		++i;
	if (line[i] == ',')
		return (print_error(ft_printf("Error: X <r>,<g>,<b>\n") - 42));
	i = -1;
	while (line[++i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != ',')
			return (print_error(ft_printf("Error: X <r>,<g>,<b>\n") - 38));
	}
	return (0);
}

/*
* * Check that the color format is precisely three integers between 0 and 255
*/

int	check_color_format(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		++i;
	if (i != 3)
		return (print_error(ft_printf("Error: X <r>,<g>,<b>\n") - 26));
	return (0);
}

/*
* * Return the rgb color encoded in an integer with a left bitshift
*/

int	atorgb(int r, int g, int b)
{
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (print_error(ft_printf("Error: X <r>,<g>,<b>\n") - 43));
	return ((r << 16) + (g << 8) + b);
}

int	parse_colors(t_identifiers *id, char *line, char c)
{
	char	**tab;
	int		rgb[3];
	int		i;

	if ((id->f >= 0 && c == 'F') || (id->c >= 0 && c == 'C'))
		return (print_error(ft_printf("Error: X <r>,<g>,<b>\n") - 37));
	if (!(tab = ft_split(line, " ,")))
		return (print_error2(-3));
	if (check_color_format(tab) || check_commas(line))
	{
		ft_free(tab);
		return (-1);
	}
	i = -1;
	while (tab[++i])
		rgb[i] = ft_atoi(tab[i]);
	ft_free_tab(tab);
	id->f = c == 'F' ? atorgb(rgb[0], rgb[1], rgb[2]) : id->f;
	id->c = c == 'C' ? atorgb(rgb[0], rgb[1], rgb[2]) : id->c;
	++id->count;
	return (0);
}
