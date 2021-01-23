/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:50:11 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/23 16:38:26 by gamichal         ###   ########lyon.fr   */
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

# define KEY_PRESS 2
# define KEY_PRESS_MASK 1L<<0

# define KEY_RELEASE 3
# define KEY_RELEASE_MASK 1L<<1

# define W 0x0D
# define A 0x00
# define S 0x01
# define D 0x02
# define LEFT_ARROW 0x7B
# define RIGHT_ARROW 0x7C 

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
		t_int		cell;
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

typedef struct		s_display
{
		int			x;
}					t_display;

typedef struct		s_player
{
	t_double		pos;
	t_double		dir;
	t_double		cam;
	t_move			move;
}					t_player;

typedef struct		s_ray
{
	t_double		dir;
	t_double		plan;
	t_double		side;
	t_double		delta;
	t_int			step;
}					t_ray;

typedef struct		s_wall
{
	double			dist;
	int				height;
	int				side;
	int				start;
	int				end;
	int				hit;
}					t_wall;

typedef struct		s_move
{
		int			forward;
		int			backward;
		int			left;
		int			right;
}

typedef struct		s_parameters
{
	t_identifiers	id;
	t_map			map;
	t_minilibx		mlx;
	t_display		dis;
	t_player		ply;
	t_ray			ray;
	t_wall			wall;
}					t_parameters;

void				set_identifiers(t_parameters *p);
int					set_minilibx(t_parameters *p);
int					parse_map(t_parameters *p, char *line);
int					parse_colors(t_identifiers *id, char *line, char c);
int					parse_resolution(t_identifiers *id, char *line);
int					parse_textures(char **path_to_txt, char *line);
int					parse_check_identifiers(t_identifiers *id);
int					parse_check_map(t_parameters *p);
int					parse_check_map_characters(char *line, int count, int ret);
int					parse_check_walls(char **grid, char *err, int i, int j);
int					render_game(t_parameters *p);
void				render_moves(t_parameters  *p);
int					key_press(int keycode, t_parameters *p);
int					key_release(int keycode, t_parameters *p);
void				render_walls(t_parameters *p);
int					print_error(int err);
int					print_error2(int err);
void				free_all(t_parameters *p);

#endif
