/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:04:22 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/16 20:00:51 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_fd_ext(char *path_txt)
{
	int fd;

	if ((fd = open(path_txt, O_DIRECTORY) >= 0))
		return (print_error(ft_printf("Error: XX <path.xpm>\n") - 23));
	fd = open(path_txt, O_RDONLY);
	if (fd < 0)
		return (print_error(ft_printf("Error: XX <path.xpm>\n") - 23));
	if (ft_strcmp(ft_strrchr(path_txt, '.'), XPM))
		return (print_error(ft_printf("Error: XX <path.xpm>\n") - 24));
	return (0);
}

int	check_texture(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		++i;
	if (i != 1)
	{
		ft_free_tab(tab);
		return (print_error(ft_printf("Error: XX <path.xpm>\n") - 26));
	}
	return (0);
}

int	parse_textures(char **path_txt, char *line)
{
	char	**tab;
	int		i;

	if (*path_txt)
		return (print_error(ft_printf("Error: XX <path.xpm>\n") - 37));
	if (!(tab = ft_split(line, " ")))
		return (print_error2(-3));
	if (check_texture(tab))
		return (-1);
	i = -1;
	while (tab[++i])
		*path_txt = ft_strdup(tab[i]);
	ft_free_tab(tab);
	if (!*path_txt)
		return (print_error2(-3));
	if (check_fd_ext(*path_txt))
		return (-1);
	return (0);
}
