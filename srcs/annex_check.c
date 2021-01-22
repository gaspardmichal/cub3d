/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:00:08 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/21 13:01:51 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	parse_check_up(char **grid, char *err, int i, int j)
{
	if (j >= (int)ft_strlen(grid[i - 1]))
		return (ft_printf("%s/!\\ no wall above [%d][%d]\n", err, i, j));
	else if (grid[i - 1][j] == ' ')
		return (ft_printf("%s/!\\ space above [%d][%d]\n", err, i, j));
	return (0);
}

static int	parse_check_down(char **grid, char *err, int i, int j)
{
	if (j >= (int)ft_strlen(grid[i + 1]))
		return (ft_printf("%s/!\\ no wall under [%d][%d]\n", err, i, j));
	else if (grid[i + 1][j] == ' ')
		return (ft_printf("%s/!\\ space under [%d][%d]\n", err, i, j));
	return (0);
}

static int	parse_check_left(char **grid, char *err, int i, int j)
{
	if (grid[i][j - 1] == ' ')
		return (ft_printf("%s/!\\ space left of [%d][%d]\n", err, i, j));
	return (0);
}

static int	parse_check_right(char **grid, char *err, int i, int j)
{
	if (grid[i][j + 1] == ' ')
		return (ft_printf("%s/!\\ space right of [%d][%d]\n", err, i, j));
	return (0);
}

int			parse_check_walls(char **grid, char *err, int i, int j)
{
	if (!i || !j || !grid[i + 1] || j == (int)ft_strlen(grid[i]) - 1)
		return (ft_printf("%s/!\\ [%d][%d] out of bounds\n", err, i, j));
	if (parse_check_down(grid, err, i, j))
		return (-1);
	if (parse_check_left(grid, err, i, j))
		return (-1);
	if (parse_check_right(grid, err, i, j))
		return (-1);
	if (parse_check_up(grid, err, i, j))
		return (-1);
	return (0);
}