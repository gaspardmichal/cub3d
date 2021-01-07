/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:33:31 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/04 14:40:07 by gamichal         ###   ########lyon.fr   */
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

/*
** Initialize all objects
*/

void	init_all(t_all *s)
{
	init_win(s);
	init_map(s);
	init_pos(s);
	init_txt(s);
	init_col(s);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->buf + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

/*
** Run game loop
*/

void	run_cub3d(int fd)
{
	t_all	s;
	//t_img	img;
	int i;

	init_all(&s);
	if (parse_map_file(&s, fd, NULL) || parse_map(&s))
		free_all(&s);
	/*init_mlx(&s);
	img.ptr = mlx_new_image(s.mlx.ptr, s.win.x, s.win.y);
	img.buf = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0xFF0000);
	mlx_put_image_to_window(s.mlx.ptr, s.win.ptr, img.ptr, 0, 0);
	mlx_loop(s.mlx.ptr);*/
	i = -1;
	ft_printf("%d	%d\n", s.win.x, s.win.y);
	ft_printf("%s\n", s.txt.no);
	ft_printf("%s\n", s.txt.so);
	ft_printf("%s\n", s.txt.we);
	ft_printf("%s\n", s.txt.ea);
	ft_printf("%s\n", s.txt.s);
	ft_printf("%d\n", s.col.f);
	ft_printf("%d\n", s.col.c);
	ft_printf("\n");
	while (s.map.grid[++i])
		ft_printf("%s\n", s.map.grid[i]);
}
