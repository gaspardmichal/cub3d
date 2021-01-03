/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:33:31 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/03 18:33:28 by gamichal         ###   ########lyon.fr   */
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
			return (-1);
	}
	if (parse_line(s, line))
		return (-1);
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
	while (s->map.grid && s->map.grid[++i])
		ft_free(s->map.grid[i]);
	ft_free(s->map.grid);
	ft_free(s->txt.no);
	ft_free(s->txt.so);
	ft_free(s->txt.we);
	ft_free(s->txt.ea);
	ft_free(s->txt.s);
	//exit(-1);
}

/*
** Initialize all object s
*/

void	init_all(t_all *s)
{
	init_mlx(s);
	init_map(s);
	init_player(s);
	init_texture(s);
	init_color(s);
	init_img(s);
}

/*
** Run game loop
*/

void	run_cub3d(int fd)
{
	t_all s;

	init_all(&s);
	if (parse_map_file(&s, fd, NULL) || parse_map(&s))
		free_all(&s);
	s.mlx.add = mlx_init();
	s.img.img = mlx_new_image(s.mlx.add, 1920, 1080);
	s.img.add = mlx_get_data_addr(&s.img, &s.img.bpp, &s.img.line_len, &s.img.endian);
	s.mlx.win = mlx_new_window(s.mlx.add, 1920, 1080, "cub3D");
	mlx_loop(s.mlx.win);
}
