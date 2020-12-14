/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:46:52 by gamichal          #+#    #+#             */
/*   Updated: 2020/12/14 14:54:16 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_texture_exist(char *path, char *id)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (print_error(ft_printf("Error: %s <path.xpm>\n", id) - 44));
	if (ft_strcmp(ft_strrchr(path, '.'), XPM))
		return (print_error(ft_printf("Error: %s <path.xpm>\n", id) - 45));
	return (0);
}

static int	check_number_of_arguments(char **tab, char *id)
{
	int i;

	i = 0;
	while (tab[i])
		++i;
	if (i != 1)
		return (print_error(ft_printf("Error: %s <path.xpm>\n", id) - 39));
	return (0);
}

int			parse_texture(char **path, char *line, char *id)
{
	char	**tab;
	int		i;

	if (*path)
		return (print_error(ft_printf("Error: %s <path.xpm>\n", id) - 42));
	if (!(tab = ft_split(line, " ")) || check_number_of_arguments(tab, id))
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
	if (check_texture_exist(*path, id))
		return (-1);
	return (0);
}
