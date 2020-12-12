/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:33:49 by gamichal          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/12/12 17:07:17 by gamichal         ###   ########lyon.fr   */
=======
/*   Updated: 2020/12/11 14:34:02 by gamichal         ###   ########lyon.fr   */
>>>>>>> 5c228cfb11d9b811f519347160044789ce1bfdc1
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Read data from map file
*/

<<<<<<< HEAD
int		parse_file(t_data *s, int fd, char *line)
=======
int		read_config_file(t_data *s, int fd, char *line)
>>>>>>> 5c228cfb11d9b811f519347160044789ce1bfdc1
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

<<<<<<< HEAD
void	free_data(t_data *s)
=======
void	free_data_structs(t_data *s)
>>>>>>> 5c228cfb11d9b811f519347160044789ce1bfdc1
{
	int i;

	i = -1;
	while (s->map->grid && s->map->grid[++i])
		ft_free(s->map->grid[i]);
	ft_free(s->map);
	ft_free(s->p);
	ft_free(s->res);
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

t_data	*init_data_structs(void)
{
	t_data *s;

	if (!(s = malloc(sizeof(t_data))))
		return (NULL);
<<<<<<< HEAD
	s->map = init_map();
	s->p = init_player();
	s->res = init_resolution();
	s->txt = init_texture();
	s->col = init_color();
	if (!s->map || !s->p || !s->res || !s->txt || !s->col)
		free_data(s);
=======
	s->map = init_map_struct();
	s->p = init_player_struct();
	s->res = init_resolution_struct();
	s->txt = init_texture_struct();
	s->col = init_color_struct();
	if (!s->map || !s->p || !s->res || !s->txt || !s->col)
		free_data_structs(s);
>>>>>>> 5c228cfb11d9b811f519347160044789ce1bfdc1
	return (s);
}

/*
** Run game loop
*/

void	run_cub3d(int fd)
{
<<<<<<< HEAD
	t_data *s;

	s = init_data();
	if (parse_file(s, fd, NULL))
		free_data(s);
=======
	t_data	*s;
	t_mlx	*mlx;
	t_win	*win;

	s = init_data_structs();
	if (read_config_file(s, fd, NULL))
		free_data_structs(s);
	if (!(mlx = malloc(sizeof(t_mlx))))
		return ;
	mlx->ptr = mlx_init();
	s->mlx = mlx;
	if (!(win = malloc(sizeof(t_win))))
		return ;
	win->x = s->res->x;
	win->y = s->res->y;
	win->ptr = mlx_new_window(s->mlx->ptr, win->x, win->y, "cub3D");
	s->win = win;
	mlx_loop(s->win->ptr);
>>>>>>> 5c228cfb11d9b811f519347160044789ce1bfdc1
}
