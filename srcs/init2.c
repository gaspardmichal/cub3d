/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:11:02 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/03 14:22:28 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_img(t_all *s)
{
	t_img img;

	img.img = NULL;
	img.add = NULL;
	img.bpp = 0;
	img.line_len = 0;
	img.endian = 0;
	s->img = img;
}
