/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:33:31 by gamichal          #+#    #+#             */
/*   Updated: 2020/12/16 12:32:05 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Read data from map file
*/

int		parse_config_file(t_all *s, int fd, char *line)
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
** Free all objects
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
** Initialize all objects
*/

t_all	*init_all(void)
{
	t_all *s;

	if (!(s = malloc(sizeof(t_all))))
		return (NULL);
	s->mlx = init_mlx();
	s->map = init_map();
	s->p = init_player();
	s->txt = init_texture();
	s->col = init_color();
	if (!s->mlx || !s->map || !s->p || !s->txt || !s->col)
		free_all(s);
	return (s);
}

/*
** Run game loop
*/

void	run_cub3d(int fd)
{
	t_all	*s;

	s = init_all();
	if (parse_config_file(s, fd, NULL) || parse_map(s))
		free_all(s);
	parse_config_file(s, fd, NULL);
	parse_map(s);
	s->mlx->add = mlx_init();
	s->mlx->win = mlx_new_window(s->mlx->add, s->mlx->rx, s->mlx->ry, "cub3D");
	//mlx_loop(s->win->ptr);
}
