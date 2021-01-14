/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:22:37 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/14 16:12:51 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

typedef	struct	t_data
{
		void	*img;
		char	*addr;
		int		bpp;
		int		line_length;
		int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	raycast(t_all *s)
{
	t_data	img;
	int		i;
	int		j;

	ft_printf("%f	%f\n", s->mlx.x, s->mlx.y);
	s->mlx.ptr = mlx_init();
	s->mlx.win = mlx_new_window(s->mlx.ptr, s->mlx.x, s->mlx.y, "cub3D");
	img.img = mlx_new_image(s->mlx.ptr, s->mlx.x, s->mlx.y);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	i = -1;
	while (++i < 100)
	{
		j = -1;
		while (++j < 100)
			my_mlx_pixel_put(&img, i - 1, j + 1, 0x00FF0000);
	}
	mlx_put_image_to_window(s->mlx.ptr, s->mlx.win, img.img, 0, 0);
	mlx_loop(s->mlx.ptr);
}
