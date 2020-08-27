/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:36:52 by gamichal          #+#    #+#             */
/*   Updated: 2020/06/05 10:41:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libft/includes/libft.h"
# include "../libmlx/mlx.h"
# include <math.h>
# include <fcntl.h>

# define CUB ".cub"
# define XPM ".xpm"
# define MAP "NSWE012 "

typedef	struct		s_struc
{
	int				fd;
	char			**map;
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

#endif
