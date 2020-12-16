/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:50:11 by gamichal          #+#    #+#             */
/*   Updated: 2020/12/15 16:57:07 by gamichal         ###   ########lyon.fr   */
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
		void		*add;
		void		*win;
		int			rx;
		int			ry;
		int			sx;
		int			sy;
}					t_mlx;

typedef	struct		s_map
{
		char		**grid;
		int			info;
}					t_map;

typedef	struct		s_p
{
		int			x;
		int			y;
}					t_p;

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
	t_mlx			*mlx;
	t_map			*map;
	t_p				*p;
	t_txt			*txt;
	t_col			*col;
}					t_all;

void				run_cub3d(int fd);
t_mlx				*init_mlx();
t_map				*init_map(void);
t_p					*init_player(void);
t_txt				*init_texture(void);
t_col				*init_color(void);
int					parse_line(t_all *s, char *line);
int					parse_identifiers(t_all *s, char *line);
int					parse_resolution(t_all *s, char *line);
int					parse_texture(char **path, char *line);
int					parse_color(t_all *s, char *line, char c);
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
