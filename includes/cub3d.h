/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:50:11 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/04 15:04:30 by gamichal         ###   ########lyon.fr   */
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
		int			resx;
		int			resy;
}					t_win;

typedef struct		s_img
{
		void		*ptr;
		char		*buf;
		int			bpp;
		int			size_line;
		int			endian;
}					t_img;

typedef struct		s_ray
{
		double		dirx;
		double		diry;
}					t_ray;

typedef	struct		s_map
{
		char		**grid;
		int			info;
}					t_map;

typedef	struct		s_pos
{
		int			x;
		int			y;
}					t_pos;

typedef struct		s_txt
{
		char		*no;
		char		*so;
		char		*we;
		char		*ea;
		char		*s;
}					t_txt;

typedef	struct		s_col
{
		int			f;
		int			c;
}					t_col;

typedef struct		s_all
{
	t_mlx			mlx;
	t_win			win;
	t_map			map;
	t_pos			pos;
	t_txt			txt;
	t_col			col;
	t_img			img;
}					t_all;

void				run_cub3d(int fd);
void				init_win(t_all *s);
void				init_map(t_all *s);
void				init_pos(t_all *s);
void				init_txt(t_all *s);
void				init_col(t_all *s);
void				init_mlx(t_all *s);
void				init_img(t_all *s);
int					parse_line(t_all *s, char *line);
int					parse_identifiers(t_all *s, char *line);
int					parse_res(t_all *s, char *line);
int					parse_txt(char **path, char *line);
int					parse_col(t_all *s, char *line, char c);
int					is_line_of_map(const char *set, const char *s);
int					allocate_map(t_all *s, char *line);
int					check_map_grid_cells(t_all *s, char *line, int ret);
int					check_parsing(t_all *s);
int					parse_map(t_all *s);
int					check_up(char **map, char *error, int i, int j);
int					check_down(char **map, char *error, int i, int j);
int					check_left(char **map, char *error, int i, int j);
int					check_right(char **map, char *error, int i, int j);
int					check_map_grid_cells(t_all *s, char *line, int ret);
int					print_error(int err);
int					print_error2(int err);

#endif
