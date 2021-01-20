/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:50:11 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/20 17:03:27 by gamichal         ###   ########lyon.fr   */
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
# define TILE_SIZE 64

# define PRESS 2
# define PRESS_MASK	1
# define RELEASE 3
# define RELEASE_MASK 10

# define W 13
# define A 0
# define S 1
# define D 2
# define RIGHT_ARROW 123
# define LEFT_ARROW 124

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

typedef struct		s_player
{
		t_double	pos;
		double		turn_dir;
		double		walk_dir;
		double		move_speed;
		double		rot_angle;
		double		rot_speed;
}					t_player;

typedef struct		s_ray
{
		int			x;
		double		dist;
		double		ray_angle;
		double		was_vert_hit;
		double		ray_facing_up;
		double		ray_facing_down;
		double		ray_facing_left;
		double		ray_facing_right;
}					t_ray;

typedef struct		s_minilibx
{
		void		*ptr;
		void		*win;
		double		width;
		double		height;
		void		*img;
		int			*pxl;
		int			bpp;
		int			size;
		int			endian;
}					t_minilibx;

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
void				set_player(t_parameters *p);
int					draw(t_parameters *p);
int					key_pressed(int key, t_parameters *p);
int					key_released(int key, t_parameters *p);
int					grid_has_wall_at(t_parameters *p);
int					print_error(int err);
int					print_error2(int err);
void				free_all(t_parameters *p);

#endif
