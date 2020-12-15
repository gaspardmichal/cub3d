/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:48:25 by gamichal          #+#    #+#             */
/*   Updated: 2020/12/15 12:48:49 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Print a specific error message for a specific error number
*/

int		print_error(int err)
{
	(err == -1) ? write(2, "/!\\ first argument is a directory\n", 34) : 0;
	(err == -2) ? write(2, "/!\\ no such file or directory\n", 30) : 0;
	(err == -3) ? write(2, "/!\\ wrong file extension\n", 25) : 0;
	(err == -4) ? write(2, "/!\\ second argument is not '--save'\n", 36) : 0;
	(err == -5) ? write(2, "/!\\ wrong number of arguments\n", 30) : 0;
	(err == -6) ? write(2, "Error: empty line in map description\n", 37) : 0;
	(err == -7) ? write(2, "Error: Map description is not last\n", 35) : 0;
	(err == -8) ? write(2, "/!\\ missing resolution\n", 23) : 0;
	(err == -9) ? write(2, "/!\\ missing northern texture\n", 29) : 0;
	(err == -10) ? write(2, "/!\\ missing southern texture\n", 29) : 0;
	(err == -11) ? write(2, "/!\\ missing western texture\n", 28) : 0;
	(err == -12) ? write(2, "/!\\ missing eastern texture\n", 28) : 0;
	(err == -13) ? write(2, "/!\\ missing sprite texture\n", 27) : 0;
	(err == -14) ? write(2, "/!\\ missing floor color\n", 24) : 0;
	(err == -15) ? write(2, "/!\\ missing ceiling color\n", 26) : 0;
	(err == -16) ? write(2, "/!\\ described more than once\n", 29) : 0;
	(err == -17) ? write(2, "/!\\ unauthorized character\n", 27) : 0;
	(err == -18) ? write(2, "/!\\ width or height is too high\n", 32) : 0;
	(err == -19) ? write(2, "/!\\ width or height equals zero\n", 32) : 0;
	(err == -20) ? write(2, "/!\\ wrong number of commas\n", 27) : 0;
	(err == -21) ? write(2, "/!\\ misplaced comma\n", 20) : 0;
	(err == -22) ? write(2, "/!\\ invalid value for r, g, or b\n", 33) : 0;
	return (-1);
}

/*
** Check second argument is "--save"
*/

int		check_save(char *save)
{
	if (ft_strcmp(save, "--save"))
		exit(print_error(ft_printf("Error: ./cub3D <path.cub> --save\n") - 37));
	return (1);
}

/*
** Check fd and file extension
*/

int		check_file(char *file, int fd)
{
	if (fd < 0)
		exit(print_error(ft_printf("Error: ./cub3D <path.cub>\n") - 28));
	else if (ft_strcmp(file + ft_strlen(file) - 4, ".cub"))
		exit(print_error(ft_printf("Error: ./cub3D <path.cub>\n") - 29));
	return (1);
}

int		main(int ac, char **av)
{
	int fd;

	if ((fd = open(av[1], O_DIRECTORY) >= 0))
		return ((print_error(ft_printf("Error: ./cub3D <path.cub>\n") - 27)));
	fd = open(av[1], O_RDONLY);
	if (ac == 2 && check_file(av[1], fd))
		run_cub3d(fd);
	else if (ac == 3 && check_file(av[1], fd) && check_save(av[2]))
		run_cub3d(fd);
	else
		exit(print_error(ft_printf("Error: ./cub3D <path.cub>\n") - 31));
	return (0);
}
