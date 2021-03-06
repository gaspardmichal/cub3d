/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:33:49 by gamichal          #+#    #+#             */
/*   Updated: 2020/10/12 10:50:36 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_struc	*init_struct(void)
{
	t_struc	*st;

	if (!(st = malloc(sizeof(t_struc))))
		return (NULL);
	st->map = NULL;
	st->len = 0;
	st->map_info = 0;
	st->width = -1;
	st->height = -1;
	st->no = NULL;
	st->so = NULL;
	st->we = NULL;
	st->ea = NULL;
	st->s = NULL;
	st->f = -1;
	st->c = -1;
	st->pos_x = -1;
	st->pos_y = -1;
	return (st);
}

static void		free_struct(t_struc *st)
{
	int i;

	i = -1;
	while (st->map && st->map[++i])
		ft_free(st->map[i]);
	ft_free(st->map);
	ft_free(st->no);
	ft_free(st->so);
	ft_free(st->we);
	ft_free(st->ea);
	ft_free(st->s);
	ft_free(st);
	while (1)
	{
	}
	//exit(1);
}

static int		check_av(t_struc *st, char *av)
{
	st->fd = open(av, O_RDONLY);
	if (st->fd < 0)
	{
		ft_printf("ERROR: ./cub3D <filename.cub>\n");
		ft_printf("/!\\ %s does not exist\n", av);
		ft_free(st);
		exit(1);
	}
	else if (ft_strcmp(ft_strrchr(av, '.'), CUB))
	{
		ft_printf("ERROR: ./cub3D <filename.cub>\n");
		ft_printf("/!\\ map has invalid extension\n");
		ft_free(st);
		exit(1);
	}
	return (0);
}

static int		parse_cub_file(t_struc *st, char *line)
{
	while ((get_next_line(st->fd, &line)))
	{
		if (parse_map(st, line))
			return (1);
	}
	if (parse_map(st, line))
		return (1);
	close(st->fd);
	return (check_parsing(st));
}

int				main(int ac, char **av)
{
	t_struc	*st;
	int		i;

	if (ac == 2)
	{
		st = init_struct();
		check_av(st, av[1]);
		if (parse_cub_file(st, NULL))
		{
			/*ft_printf("WIDTH  = %d\nHEIGHT = %d\n", st->width, st->height);
			ft_printf("NO     = %s\n", st->no);
			ft_printf("SO     = %s\n", st->so);
			ft_printf("WE     = %s\n", st->we);
			ft_printf("EA     = %s\n", st->ea);
			ft_printf("S      = %s\n", st->s);
			ft_printf("F      = %d\n", st->f);
			ft_printf("C      = %d\n", st->c);*/
			free_struct(st);
		}
		
		if (check_map(st))
			free_struct(st);
		i = 0;
		while (st->map[i])
		{
			ft_printf("[%d] %s\n", i, st->map[i]);
			++i;
		}
		while (1)
		{
		}
	}
	else if (ac == 3)
	{
		if (ft_strcmp(av[2], "--save"))
		{
			ft_printf("ERROR : ./cub3D <filename.cub> --save\n");
			ft_printf("/!\\ \"%s\" is not a valid argument\n", av[2]);
			exit(1);
		}
		/* La suite */
	}
	else
	{
		ft_printf("ERROR: ./cub3D <filename.cub>\n");
		ft_printf("/!\\ wrong number of arguments\n");
		exit(1);
	}
	return (0);
}
