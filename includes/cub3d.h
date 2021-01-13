/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:50:11 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/13 13:59:36 by gamichal         ###   ########.fr       */
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



typedef struct		s_res
{
		double		width;
		double		height;
}					t_res;



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



typedef	struct		s_mlx
{
		void		*ptr;
}					t_mlx;



typedef struct		s_win
{
		void		*ptr;
		double		x;
		double		y;
		int			sizex;
		int			sizey;
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
		double		planx;
		double		plany;
		double		raydirx;
		double		raydiry;
		double		camerax;
		int			mapx;
		int			mapy;
		double		sidedistx;
		double		sidedisty;
		int			stepx;
		int			stepy;
		int			hit;
		int			side;
		double		perpwalldist;
		int			lineheight;
		int			drawstart;
		int			drawend;
		int			x;
}					t_ray;



typedef struct		s_all
{
	t_res			res;
	t_txt			txt;
	t_col			col;
	t_map			map;
	t_pos			pos;
	t_mlx			mlx;
	t_win			win;
	t_img			img;
	t_ray			ray;
}					t_all;



void				run_cub3d(int fd);

void				init_map(t_all *s);
void				init_pos(t_all *s);
void				init_res(t_all *s);
void				init_txt(t_all *s);
void				init_col(t_all *s);
int					init_mlx(t_all *s);
int					init_win(t_all *s);
void				init_img(t_all *s);
void				init_ray(t_all *s);

int					parse_line(t_all *s, char *line);
int					parse_res_col_txt(t_all *s, char *line);
int					parse_res(t_all *s, char *line);
int					parse_txt(char **path, char *line);
int					parse_col(t_all *s, char *line, char c);
int					is_line_of_map(const char *set, const char *s);
int					alloc_line_of_map(t_all *s, char *line);

int					check_map(t_all *s);
int					check_up(char **map, char *error, int i, int j);
int					check_down(char **map, char *error, int i, int j);
int					check_left(char **map, char *error, int i, int j);
int					check_right(char **map, char *error, int i, int j);
int					check_grid(t_all *s, char *line, int ret);
int					check_pars(t_all *s);

int					print_error(int err);
int					print_error2(int err);

#endif
