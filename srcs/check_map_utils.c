/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 10:41:15 by gamichal          #+#    #+#             */
/*   Updated: 2020/10/12 11:24:31 by gamichal         ###   ########.fr       */
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

int	check_map_char(t_struc *st, char *line, int ret)
{
	if (*line && st->map_info == 4)
		ret = ft_printf("ERROR: unauthorized character in map description\n");
	return (ft_exit(line, ret));
}
