/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:48:25 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/14 16:00:39 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

int		check_save(char *save)
{
	if (ft_strcmp(save, "--save"))
		exit(print_error(ft_printf("Error: ./cub3D <path.cub> --save\n") - 37));
	return (1);
}

int		check_file(char *file, int fd)
{
	if (fd < 0)
		exit(print_error(ft_printf("Error: ./cub3D <path.cub>\n") - 28));
	else if (ft_strcmp(file + ft_strlen(file) - 4, ".cub"))
		exit(print_error(ft_printf("Error: ./cub3D <path.cub>\n") - 29));
	return (1);
}

int		pars_file(t_all *s, int fd, char *line)
{
	while ((get_next_line(fd, &line)))
	{
		if (pars_line(s, line))
			return (-1);
	}
	if (pars_line(s, line))
		return (-1);
	close(fd);
	return (check_pars(s->id));
}

void	cub3d(int fd)
{
	t_all	s;

	init_id(&s);
	if (pars_file(&s, fd, NULL) || check_map(&s.map))
		free_all(&s);
	init_all(&s);
	raycast(&s);
}

int		main(int ac, char **av)
{
	int fd;

	if ((fd = open(av[1], O_DIRECTORY) >= 0))
		return ((print_error(ft_printf("Error: ./cub3D <path.cub>\n") - 27)));
	fd = open(av[1], O_RDONLY);
	if (ac == 2 && check_file(av[1], fd))
		cub3d(fd);
	else if (ac == 3 && check_file(av[1], fd) && check_save(av[2]))
		cub3d(fd);
	else
		exit(print_error(ft_printf("Error: ./cub3D <path.cub>\n") - 31));
	while (1)
	{
		
	}
	return (0);
}
