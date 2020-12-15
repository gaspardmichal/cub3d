/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:46:52 by gamichal          #+#    #+#             */
/*   Updated: 2020/12/15 12:00:17 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_fd_ext(char *path)
{
	int fd;

	if ((fd = open(path, O_DIRECTORY) >= 0))
		return (print_error(ft_printf("Error: XX <path.xpm>\n") - 23));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (print_error(ft_printf("Error: XX <path.xpm>\n") - 23));
	if (ft_strcmp(ft_strrchr(path, '.'), XPM))
		return (print_error(ft_printf("Error: XX <path.xpm>\n") - 24));
	return (0);
}

static int	check_txt(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		++i;
	if (i != 1)
		return (print_error(ft_printf("Error: XX <path.xpm>\n") - 26));
	return (0);
}

int			parse_texture(char **path, char *line)
{
	char	**tab;
	int		i;

	if (*path)
		return (print_error(ft_printf("Error: XX <path.xpm>\n") - 37));
	if (!(tab = ft_split(line, " ")) || check_txt(tab))
	{
		ft_free_tab(tab);
		return (-1);
	}
	i = 0;
	while (tab[i])
	{
		*path = ft_strdup(tab[i]);
		++i;
	}
	ft_free_tab(tab);
	if (check_fd_ext(*path))
		return (-1);
	return (0);
}
