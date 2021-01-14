/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:50:11 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/14 16:01:09 by gamichal         ###   ########lyon.fr   */
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

typedef struct		s_id
{
		double		x;
		double		y;
		char		*no;
		char		*so;
		char		*we;
		char		*ea;
		char		*s;
		int			f;
		int			c;
		int			i;
}					t_id;

typedef struct		s_map
{
		char		**grid;
		int			x;
		int			y;
}					t_map;

typedef struct		s_mlx
{
		void		*ptr;
		void		*win;
		int			sizex;
		int			sizey;
		double		x;
		double		y;
}					t_mlx;

typedef struct		s_all
{
	t_id			id;
	t_map			map;
	t_mlx			mlx;
}					t_all;

void				init_id(t_all *s);
int					pars_line(t_all *s, char *line);
int					pars_id(t_id *id, char *line);
int					pars_res(t_id *id, char *line);
int					pars_col(t_id *id, char *line, char c);
int					pars_txt(char **txt, char *line);
int					line_of_map(const char *set, const char *s);
int					alloc_line_of_map(t_map *map, char *line);
int					check_map(t_map *map);
int					check_up(char **grid, char *error, int i, int j);
int					check_down(char **grid, char *error, int i, int j);
int					check_left(char **grid, char *error, int i, int j);
int					check_right(char **grid, char *error, int i, int j);
int					check_grid(t_id *id, char *line, int ret);
int					check_pars(t_id id);
void				init_all(t_all *s);
void				raycast(t_all *s);
int					print_error(int err);
int					print_error2(int err);
void				free_all(t_all *s);

#endif
