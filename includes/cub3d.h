/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 10:41:49 by gamichal          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/12/12 18:25:54 by gamichal         ###   ########lyon.fr   */
=======
/*   Updated: 2020/12/11 11:23:00 by gamichal         ###   ########lyon.fr   */
>>>>>>> 5c228cfb11d9b811f519347160044789ce1bfdc1
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
# define MAP "NSWE012 "


typedef	struct		s_mlx
{
		void		*ptr;
}					t_mlx;

typedef struct		s_win
{
		void		*ptr;
		int			x;
		int			y;
}					t_win;

typedef	struct		s_map
{
		char		**grid;
		int			info;
}					t_map;

typedef	struct		s_player
{
		int			x;
		int			y;
}					t_player;

typedef	struct		s_resolution
{
		int			x;
		int			y;
}					t_resolution;

typedef struct		s_texture
{
		char		*no;
		char		*so;
		char		*we;
		char		*ea;
		char		*s;
}					t_texture;

typedef	struct		s_color
{
		int			f;
		int			c;
}					t_color;

typedef struct		s_data
{
	t_mlx			*mlx;
	t_win			*win;
	t_map			*map;
	t_player		*p;
	t_resolution	*res;
	t_texture		*txt;
	t_color			*col;
}					t_data;

void				run_cub3d(int fd);
<<<<<<< HEAD
t_map				*init_map(void);
t_player			*init_player(void);
t_resolution		*init_resolution(void);
t_texture			*init_texture(void);
t_color				*init_color(void);
int					parse_line(t_data *s, char *line);
int					allocate_map(t_data *s, char *line);
int					parse_identifiers(t_data *s, char *line);
int					parse_resolution(t_data *s, char *line);
int					parse_color(t_data *s, char *line, char c);
int					check_map_grid_cells(t_data *s, char *line, int ret);
int					check_parsing(t_data *s);
int					parse_map(t_data *s);
int					parse_texture(char **path, char *line, char *s);
int					is_line_of_map(const char *set, const char *s);
=======
t_map				*init_map_struct(void);
t_player			*init_player_struct(void);
t_resolution		*init_resolution_struct(void);
t_texture			*init_texture_struct(void);
t_color				*init_color_struct(void);
int					parse_line(t_data *s, char *line);
int					parse_identifiers(t_data *s, char *line);
int					parse_resolution(t_data *s, char *line);
int					parse_texture(char **path, char *line, char *s);
int					parse_color(t_data *s, char *line, char c);
int					is_line_of_map(const char *set, const char *s);
int					allocate_map(t_data *s, char *line);
int					parse_map(t_data *s);
>>>>>>> 5c228cfb11d9b811f519347160044789ce1bfdc1
int					check_up(char **map, char *error, int i, int j);
int					check_down(char **map, char *error, int i, int j);
int					check_left(char **map, char *error, int i, int j);
int					check_right(char **map, char *error, int i, int j);
<<<<<<< HEAD
=======
int					check_map_grid_cells(t_data *s, char *line, int ret);
int					check_parsing(t_data *s);
>>>>>>> 5c228cfb11d9b811f519347160044789ce1bfdc1
int					print_error(int err);

#endif
