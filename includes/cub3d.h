/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:50:11 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/16 21:08:14 by gamichal         ###   ########.fr       */
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

typedef struct		s_identifiers
{
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
		int			x;
		int			y;
}					t_map;

typedef struct		s_minilibx
{
		void		*ptr;
		void		*win;
		double		width;
		double		height;
		void		*img;
		int			*pxl;
}					t_minilibx;

typedef struct		s_parameters
{
	t_identifiers	id;
	t_map			map;
	t_minilibx		mlx;
}					t_parameters;

void				init_identifiers(t_parameters *p);
int					parse_line(t_parameters *p, char *line);
int					parse_identifiers(t_parameters *p, char *line);
int					parse_resolution(t_parameters *p, char *line);
int					parse_textures(char **path_to_txt, char *line);
int					parse_colors(t_identifiers *id, char *line, char c);
int					check_identifiers(t_parameters *p);
int					check_map(t_map *map);
int					check_map_characters(char *line, int count, int ret);
int					check_walls(char **grid, char *err, int i, int j);
void				init_parameters(t_parameters *p);
void				raycast(t_parameters *p);
int					print_error(int err);
int					print_error2(int err);
void				free_parameters(t_parameters *p);

#endif
