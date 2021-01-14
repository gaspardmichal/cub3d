/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:57:40 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/14 15:25:13 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_split_res(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		++i;
	if (i != 2)
		return (print_error(ft_printf("Error: R <width> <height>\n") - 31));
	return (0);
}

int		check_char(char *line)
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

int		check_len(char **tab)
{
	if (ft_strlen(tab[0]) > 4 || ft_strlen(tab[1]) > 4)
		return (print_error(ft_printf("Error: R <width> <height>\n") - 44));
	return (0);
}

int		check_res(char **tab, char *line)
{
	if (check_split_res(tab) || check_char(line) || check_len(tab))
	{
		ft_free(tab);
		return (-1);
	}
	return (0);
}

int		pars_res(t_id *id, char *line)
{
	char	**tab;
	int		i;

	if ((id->x > 0 && id->y > 0))
		return (print_error(ft_printf("Error: R <width> <height>\n") - 42));
	if (!(tab = ft_split(line, " ")))
		return (print_error2(-3));
	if (check_res(tab, line))
		return (-1);
	i = -1;
	while (tab[++i])
	{
		id->x = i == 0 ? ft_atoi(tab[i]) : id->x;
		id->y = i == 1 ? ft_atoi(tab[i]) : id->y;
	}
	ft_free_tab(tab);
	if (!id->x || !id->y)
		return (print_error(ft_printf("Error: R <width> <height>\n") - 45));
	if (id->x > 5120 || id->y > 2880)
	{
		id->x = 1920;
		id->y = 1080;
	}
	++id->i;
	return (0);
}
