/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:50:11 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/21 08:28:47 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../mlx_linux/mlx.h"
# include <string.h>
# include <math.h>
# include <fcntl.h>

# define CUB ".cub"
# define XPM ".xpm"
# define MAP_CHARSET "NSWE012 "

typedef struct		s_int
{
		int			x;
		int			y;
}					t_int;

typedef struct		s_double
{
		double		x;
		double		y;
}					t_double;

typedef struct		s_identifiers
{
		t_int		r;
		char		*no;
		char		*so;
		char		*we;
		char		*ea;
		char		*s;
		int			f;
		int			c;
		int			count;
}					t_identifiers;

typedef struct		s_map
{
		char		**grid;
}					t_map;

typedef struct		s_minilibx
{
		double		width;
		double		height;
		void		*ptr;
		void		*win;
		void		*img;
		int			*pxl;
		int			bpp;
		int			size;
		int			endian;
}					t_minilibx;

typedef struct		s_player
{
		t_double	pos;
		t_double	dir;
		t_double	plan;
}					t_player;

typedef struct		s_parameters
{
	t_identifiers	id;
	t_map			map;
	t_player		ply;
	t_ray			ray;
	t_minilibx		mlx;
}					t_parameters;

void				set_identifiers(t_parameters *p);
int					parse_map(t_parameters *p, char *line);
int					parse_identifiers(t_parameters *p, char *line);
int					parse_resolution(t_identifiers *id, char *line);
int					parse_colors(t_identifiers *id, char *line, char c);
int					parse_textures(char **path_to_txt, char *line);
int					check_identifiers(t_identifiers *id);
int					check_map(t_parameters *p);
int					check_map_characters(char *line, int count, int ret);
int					check_walls(char **grid, char *err, int i, int j);
int					set_minilibx(t_parameters *p);
int					draw(t_parameters *p);
int					print_error(int err);
int					print_error2(int err);
void				free_all(t_parameters *p);

#endif
