/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 09:04:36 by gamichal          #+#    #+#             */
/*   Updated: 2020/12/11 09:06:33 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_up(char **map, char *err, int i, int j)
{
	if (j >= (int)ft_strlen(map[i - 1]))
		return (ft_printf("%s/!\\ no wall above [%d][%d]\n", err, i, j));
	else if (map[i - 1][j] == ' ')
		return (ft_printf("%s/!\\ space above [%d][%d]\n", err, i, j));
	return (0);
}

int	check_down(char **map, char *err, int i, int j)
{
	if (j >= (int)ft_strlen(map[i + 1]))
		return (ft_printf("%s/!\\ no wall under [%d][%d]\n", err, i, j));
	else if (map[i + 1][j] == ' ')
		return (ft_printf("%s/!\\ space under [%d][%d]\n", err, i, j));
	return (0);
}

int	check_left(char **map, char *err, int i, int j)
{
	if (map[i][j - 1] == ' ')
		return (ft_printf("%s/!\\ space left of [%d][%d]\n", err, i, j));
	return (0);
}

int	check_right(char **map, char *err, int i, int j)
{
	if (map[i][j + 1] == ' ')
		return (ft_printf("%s/!\\ space right of [%d][%d]\n", err, i, j));
	return (0);
}

int	check_map_char(t_data *d, char *line, int ret)
{
	if (*line && d->map->info == 4)
		ret = ft_printf("Error: unauthorized character in map description\n");
	return (ft_exit(line, ret));
}
