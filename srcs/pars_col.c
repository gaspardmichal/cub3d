/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:58:26 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/14 15:25:44 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_col(char *line)
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

int		check_split_col(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		++i;
	if (i != 3)
		return (print_error(ft_printf("Error: X <r>,<g>,<b>\n") - 26));
	return (0);
}

int		atorgb(int r, int g, int b)
{
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (print_error(ft_printf("Error: X <r>,<g>,<b>\n") - 43));
	return ((r << 16) + (g << 8) + b);
}

int		pars_col(t_id *id, char *line, char c)
{
	char	**tab;
	int		rgb[3];
	int		i;

	if ((id->f >= 0 && c == 'F') || (id->c >= 0 && c == 'C'))
		return (print_error(ft_printf("Error: X <r>,<g>,<b>\n") - 37));
	if (!(tab = ft_split(line, " ,")))
		return (print_error2(-3));
	if (check_split_col(tab) || check_col(line))
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
	++id->i;
	return (0);
}
