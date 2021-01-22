/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:48:25 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/22 11:27:31 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Check that second argument is "save"
*/

static int	check_arg_save(char *arg)
{
	if (ft_strcmp(arg, "--save"))
		exit(print_error(ft_printf("Error: ./cub3D <path.cub> --save\n") - 37));
	return (1);
}

/*
** Check map fd and extension
*/

static int	check_arg_fd_ext(char *arg, int fd)
{
	if (fd < 0)
		exit(print_error(ft_printf("Error: ./cub3D <path.cub>\n") - 28));
	else if (ft_strcmp(arg + ft_strlen(arg) - 4, ".cub"))
		exit(print_error(ft_printf("Error: ./cub3D <path.cub>\n") - 29));
	return (1);
}

/*
** Parse map file with get_next_line
*/

static int	parse_cub(int fd, t_parameters *p, char *line)
{
	while ((get_next_line(fd, &line)))
	{
		if (parse_map(p, line))
			return (-1);
	}
	if (parse_map(p, line))
		return (-1);
	close(fd);
	if (parse_check_identifiers(&p->id) || parse_check_map(p))
		return (-1);
	return (0);
}

static void	cub3d(int fd, t_parameters *p)
{
	set_identifiers(p);
	if (parse_cub(fd, p, NULL))
		free_all(p);
	if (set_minilibx(p))
		free_all(p);
	mlx_loop_hook(p->mlx.ptr, render_game, p);
	mlx_loop(p->mlx.ptr);
}

int			main(int ac, char **av)
{
	int				fd;
	t_parameters	*p;

	if (!(p = malloc(sizeof(t_parameters))))
		return (print_error2(-3));
	if ((fd = open(av[1], O_DIRECTORY) >= 0))
		return ((print_error(ft_printf("Error: ./cub3D <path.cub>\n") - 27)));
	fd = open(av[1], O_RDONLY);
	if (ac == 2 && check_arg_fd_ext(av[1], fd))
		cub3d(fd, p);
	else if (ac == 3 && check_arg_fd_ext(av[1], fd) && check_arg_save(av[2]))
		cub3d(fd, p);
	else
		exit(print_error(ft_printf("Error: ./cub3D <path.cub>\n") - 31));
	while (1)
	{
	}
	return (0);
}
