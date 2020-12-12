/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:33:49 by gamichal          #+#    #+#             */
/*   Updated: 2020/12/12 17:07:17 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Read data from map file
*/

int		parse_file(t_data *s, int fd, char *line)
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

void	free_data(t_data *s)
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

t_data	*init_data(void)
{
	t_data *s;

	if (!(s = malloc(sizeof(t_data))))
		return (NULL);
	s->map = init_map();
	s->p = init_player();
	s->res = init_resolution();
	s->txt = init_texture();
	s->col = init_color();
	if (!s->map || !s->p || !s->res || !s->txt || !s->col)
		free_data(s);
	return (s);
}

/*
** Run game loop
*/

void	run_cub3d(int fd)
{
	t_data *s;

	s = init_data();
	if (parse_file(s, fd, NULL))
		free_data(s);
}
