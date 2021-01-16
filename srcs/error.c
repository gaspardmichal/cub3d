/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:04:16 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/16 20:42:41 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		print_error(int err)
{
	(err == -1) ? write(2, "/!\\ first argument is a directory\n", 34) : 0;
	(err == -2) ? write(2, "/!\\ no such file or directory\n", 30) : 0;
	(err == -3) ? write(2, "/!\\ wrong file extension\n", 25) : 0;
	(err == -4) ? write(2, "/!\\ second argument is not '--save'\n", 36) : 0;
	(err == -5) ? write(2, "/!\\ wrong number of arguments\n", 30) : 0;
	(err == -6) ? write(2, "Error: empty line in map description\n", 37) : 0;
	(err == -7) ? write(2, "Error: map description is not last\n", 35) : 0;
	(err == -8) ? write(2, "/!\\ missing resolution\n", 23) : 0;
	(err == -9) ? write(2, "/!\\ missing northern texture\n", 29) : 0;
	(err == -10) ? write(2, "/!\\ missing southern texture\n", 29) : 0;
	(err == -11) ? write(2, "/!\\ missing western texture\n", 28) : 0;
	(err == -12) ? write(2, "/!\\ missing eastern texture\n", 28) : 0;
	(err == -13) ? write(2, "/!\\ missing sprite texture\n", 27) : 0;
	(err == -14) ? write(2, "/!\\ missing floor color\n", 24) : 0;
	(err == -15) ? write(2, "/!\\ missing ceiling color\n", 26) : 0;
	(err == -16) ? write(2, "/!\\ described more than once\n", 29) : 0;
	(err == -17) ? write(2, "/!\\ unauthorized character\n", 27) : 0;
	(err == -18) ? write(2, "/!\\ width or height is too high\n", 32) : 0;
	(err == -19) ? write(2, "/!\\ width or height equals zero\n", 32) : 0;
	(err == -20) ? write(2, "/!\\ wrong number of commas\n", 27) : 0;
	(err == -21) ? write(2, "/!\\ misplaced comma\n", 20) : 0;
	(err == -22) ? write(2, "/!\\ invalid value for r, g, or b\n", 33) : 0;
	(err == -23) ? write(2, "Error: no map description\n", 26) : 0;
	(err == -24) ? write(2, "Error: too many starting positions\n", 36) : 0;
	return (-1);
}

int		print_error2(int err)
{
	(err == -1) ? write(2, "Error: starting position ouf of bounds\n", 39) : 0;
	(err == -2) ? write(2, "Error: no starting position\n", 28) : 0;
	(err == -3) ? write(2, "Error: failed to allocate memory\n", 33) : 0;
	(err == -4) ? write(2, "Error: failed to initialise mlx\n", 32) : 0;
	return (-1);
}

void	free_parameters(t_parameters *p)
{
	int i;

	i = -1;
	while (p->map.grid && p->map.grid[++i])
		ft_free(p->map.grid[i]);
	ft_free(p->map.grid);
	ft_free(p->id.no);
	ft_free(p->id.so);
	ft_free(p->id.we);
	ft_free(p->id.ea);
	ft_free(p->id.s);
}
