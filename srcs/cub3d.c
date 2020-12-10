/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:33:49 by gamichal          #+#    #+#             */
/*   Updated: 2020/12/10 14:59:20 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Read data from map file
*/

int		parse_file(t_data *d, int fd, char *line)
{
	while ((get_next_line(fd, &line)))
	{
		if (parse_map(d, line))
			return (1);
	}
	if (parse_map(d, line))
		return (1);
	close(fd);
	return (check_parsing(d));
}

/*
** Free all objects
*/

void	free_data(t_data *d)
{
	int i;

	i = -1;
	while (d->map->grid[++i])
		ft_free(d->map->grid[i]);
	ft_free(d->map);
	ft_free(d->play);
	ft_free(d->res);
	ft_free(d->text->no);
	ft_free(d->text->so);
	ft_free(d->text->we);
	ft_free(d->text->ea);
	ft_free(d->text->s);
	ft_free(d->text);
	ft_free(d->col);
	ft_free(d);
	exit(print_error(-5));
}

/*
** Initialize all objects
*/

t_data	*init_data(void)
{
	t_data *d;

	if (!(d = malloc(sizeof(t_data))))
		return (NULL);
	d->map = init_map();
	d->play = init_player();
	d->res = init_resolution();
	d->text = init_texture();
	d->col = init_color();
	if (!d->map || !d->play || !d->res || !d->text || !d->col)
		free_data(d);
	return (d);
}

/*
** Run game loop
*/

void	run_cub3d(int fd)
{
	t_data *d;

	d = init_data();
	if (parse_file(d, fd, NULL))
		free_data(d);
}
