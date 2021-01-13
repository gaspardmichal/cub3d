/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:33:31 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/13 21:02:17 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

/*
** Read data from map file
*/

int		parse_file(t_all *s, int fd, char *line)
{
	while ((get_next_line(fd, &line)))
	{
		if (parse_line(s, line))
			return (-1);
	}
	if (parse_line(s, line))
		return (-1);
	close(fd);
	return (check_pars(s));
}

/*
** Free all objects
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
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->buf + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

/*
** Initialize all objects
*/

void	init_pars(t_all *s)
{
	init_res(s);
	init_txt(s);
	init_col(s);
	init_map(s);
	init_pos(s);
}

int		init_raycast(t_all *s)
{
	if (init_mlx(s))
		return (print_error2(-3));
	init_win(s);
		return (print_error2(-3));
	init_img(s);
	init_ray(s);
	return (0);
}

/*
** Run game loop
*/

void	run_cub3d(int fd)
{
	t_all	s;
	t_img	img;

	init_pars(&s);
	if ((parse_file(&s, fd, NULL) || check_map(&s)) || init_raycast(&s))
		free_all(&s);
	my_mlx_pixel_put(&img, 5, 5, 0xFF0000);
	mlx_put_image_to_window(s.mlx.ptr, s.win.ptr, img.ptr, 0, 0);
	mlx_loop(s.mlx.ptr);
}
