/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:48:25 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/17 10:37:40 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_arg_save(char *arg)
{
	if (ft_strcmp(arg, "--save"))
		exit(print_error(ft_printf("Error: ./cub3D <path.cub> --save\n") - 37));
	return (1);
}

int		check_arg_fd_ext(char *arg, int fd)
{
	if (fd < 0)
		exit(print_error(ft_printf("Error: ./cub3D <path.cub>\n") - 28));
	else if (ft_strcmp(arg + ft_strlen(arg) - 4, ".cub"))
		exit(print_error(ft_printf("Error: ./cub3D <path.cub>\n") - 29));
	return (1);
}

int		parse_cub(t_parameters *p, int fd, char *line)
{
	while ((get_next_line(fd, &line)))
	{
		if (parse_map(p, line))
			return (-1);
	}
	if (parse_map(p, line))
		return (-1);
	close(fd);
	if (check_identifiers(p) || check_map(&p->map))
		return (-1);
	return (0);
}

void	cub3d(int fd)
{
	t_parameters *p;

	p = NULL;
	set_identifiers(p);
	if (parse_cub(p, fd, NULL))
		free_all(p);
	set_minilibx(p);
}

int		main(int ac, char **av)
{
	int fd;

	if ((fd = open(av[1], O_DIRECTORY) >= 0))
		return ((print_error(ft_printf("Error: ./cub3D <path.cub>\n") - 27)));
	fd = open(av[1], O_RDONLY);
	if (ac == 2 && check_arg_fd_ext(av[1], fd))
		cub3d(fd);
	else if (ac == 3 && check_arg_fd_ext(av[1], fd) && check_arg_save(av[2]))
		cub3d(fd);
	else
		exit(print_error(ft_printf("Error: ./cub3D <path.cub>\n") - 31));
	while (1)
	{
	}
	return (0);
}
