/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:22:37 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/16 19:01:05 by gamichal         ###   ########.fr       */
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

void	raycast(t_parameters *p)
{
	t_data	img;
	int		i;
	int		j;

	p->mlx.ptr = mlx_init();
	p->mlx.win = mlx_new_window(p->mlx.ptr, p->mlx.width, p->mlx.height, "cub3D");
	img.img = mlx_new_image(p->mlx.ptr, p->mlx.width, p->mlx.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	i = -1;
	while (++i < 100)
	{
		j = -1;
		while (++j < 100)
			my_mlx_pixel_put(&img, i - 1, j + 1, 0x00FF0000);
	}
	mlx_put_image_to_window(p->mlx.ptr, p->mlx.win, img.img, 0, 0);
	mlx_loop(p->mlx.ptr);
}
