/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:33:31 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/02 10:34:44 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Read data from map file
*/

int		parse_map_file(t_all *s, int fd, char *line)
{
	while ((get_next_line(fd, &line)))
	{
		if (parse_line(s, line))
			return (1);
	}
	if (parse_line(s, line))
		return (1);
	close(fd);
	return (check_parsing(s));
}

/*
** Free all object
*/

void	free_all(t_all *s)
{
	int i;

	i = -1;
	while (s->map->grid && s->map->grid[++i])
		ft_free(s->map->grid[i]);
	ft_free(s->map);
	ft_free(s->p);
	ft_free(s->txt->no);
	ft_free(s->txt->so);
	ft_free(s->txt->we);
	ft_free(s->txt->ea);
	ft_free(s->txt->s);
	ft_free(s->txt);
	ft_free(s->col);
	ft_free(s);
	exit(-1);
}

/*
** Initialize all object s
*/

t_all	*init_all(void)
{
	t_all *s;

	if (!(s = malloc(sizeof(t_all))))
	{
		print_error2(-3);
		return (NULL);
	}
	s->mlx = init_mlx();
	s->map = init_map();
	s->p = init_player();
	s->txt = init_texture();
	s->col = init_color();
	return ((!s->mlx || !s->map || !s->p || !s->txt || !s->col) ? NULL : s);
}

/*
** Run game loop
*/

void	run_cub3d(int fd)
{
	t_all	*s;

	if (!(s = init_all()))
		free_all(s);
	if (parse_map_file(s, fd, NULL) || parse_map(s))
		free_all(s);
	/*s->mlx->add = mlx_init();
	s->mlx->win = mlx_new_window(s->mlx->add, 3200, 1440, "cub3D");
	mlx_loop(s->mlx->win);*/
}
