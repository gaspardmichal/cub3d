/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:42:36 by gamichal          #+#    #+#             */
/*   Updated: 2020/12/11 11:37:40 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Print specific error message
*/

int		print_error(int err)
{
	(err == -2) ? write(2, "Error: No such file or directory\n", 33) : 0;
	(err == -3) ? write(2, "Error: Map has a wrong extension\n", 33) : 0;
	(err == -4) ? write(2, "Error: Second argument is not '--save'\n", 39) : 0;
	(err == -5) ? write(2, "Error: empty line in map description\n", 37) : 0;
	(err == -6) ? write(2, "Error: map description is not last\n", 35) : 0;
	(err == -7) ? write(2, "/!\\ missing resolution\n", 24) : 0;
	(err == -8) ? write(2, "/!\\ missing northern texture\n", 30) : 0;
	(err == -9) ? write(2, "/!\\ missing southern texture\n", 30) : 0;
	(err == -10) ? write(2, "/!\\ missing western texture\n", 29) : 0;
	(err == -11) ? write(2, "/!\\ missing eastern texture\n", 29) : 0;
	(err == -12) ? write(2, "/!\\ missing sprite texture\n", 28) : 0;
	(err == -13) ? write(2, "/!\\ missing floor color\n", 25) : 0;
	(err == -14) ? write(2, "/!\\ missing ceiling color\n", 27) : 0;
	return (-1);
}

/*
** Check second argument is "--save"
*/

int		check_save(char *save)
{
	if (ft_strcmp(save, "--save"))
		exit(print_error(-4));
	return (1);
}

/*
** Check fd and file extension
*/

int		check_file(char *file, int fd)
{
	if (fd < 0)
		exit(print_error(-2));
	else if (ft_strcmp(file + ft_strlen(file) - 4, ".cub"))
		exit(print_error(-3));
	return (1);
}

int		main(int ac, char **av)
{
	int fd;

	fd = open(av[1], O_RDONLY);
	if (ac == 2 && check_file(av[1], fd))
		run_cub3d(fd);
	else if (ac == 3 && check_file(av[1], fd) && check_save(av[2]))
		run_cub3d(fd);
	else
		write(2, "Error: invalid number of arguments\n", 36);
	return (0);
}
