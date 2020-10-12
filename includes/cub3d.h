/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 10:41:49 by gamichal          #+#    #+#             */
/*   Updated: 2020/10/11 11:06:42 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>

# define CUB ".cub"
# define XPM ".xpm"
# define MAP "NSWE012 "

typedef	struct		s_struc
{
	int				fd;
	char			**map;
	int				len;
	int				map_info;
	int				width;
	int				height;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	int				f;
	int				c;
	int				pos_x;
	int				pos_y;
}					t_struc;

int					parse_map(t_struc *st, char *line);
int					check_parsing(t_struc *st);
int					line_is_in_map(const char *set, const char *s);
int					parse_line(t_struc *st, char *line);
int					allocate_map(t_struc *st, char *line);
int					parse_resolution(t_struc *st, char *line);
int					parse_texture(char **path, char *line, char *s);
int					parse_color(t_struc *st, char *line, char c);
int					check_map(t_struc *st);
int					check_up(char **map, char *error, int i, int j);
int					check_down(char **map, char *error, int i, int j);
int					check_left(char **map, char *error, int i, int j);
int					check_right(char **map, char *error, int i, int j);
int					check_map_char(t_struc *st, char *line, int ret);

#endif
