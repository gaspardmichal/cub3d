/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:21:51 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/23 16:44:39 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int keycode, t_parameters *p)
{
	if (keycode == W)
		p->ply.move.forward = 1;
	if (keycode == A)
		p->ply.move.backward = 1;
	if (keycode == S)
		ft_printf("Hello ! You just pressed the s key !\n");
	if (keycode == D)
		ft_printf("Hello ! You just pressed the d key !\n");
	if (keycode == LEFT_ARROW)
		p->ply.move.left = 1;
	if (keycode == RIGHT_ARROW)
		p->ply.move.right = 1;
	return (0);
}

int	key_release(int keycode, t_parameters *p)
{
	if (keycode == W)
		p->ply.move.forward = 0;
	if (keycode == A)
		p->ply.move.backward = 0;
	if (keycode == S)
		ft_printf("Hello ! You just released the s key !\n");
	if (keycode == D)
		ft_printf("Hello ! You just released the d key !\n");
	if (keycode == LEFT_ARROW)
		p->ply.move.left = 0;
	if (keycode == RIGHT_ARROW)
		p->ply.move.right = 0;
	return (0);
}
