/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:35:18 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/03 14:31:51 by gamichal         ###   ########lyon.fr   */
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

int	check_map_grid_cells(t_all *s, char *line, int ret)
{
	if (*line && s->map.info == 4 && ret != -1)
		ret = ft_printf("Error: unauthorized character in map description\n");
	return (ft_exit(line, ret));
}
