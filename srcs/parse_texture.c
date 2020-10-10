/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 09:35:32 by gamichal          #+#    #+#             */
/*   Updated: 2020/10/10 10:43:13 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_texture_exist(char *path, char *id)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ERROR: %s <path_to_file.xpm>\n", id);
		return (ft_printf("/!\\ invalid fd\n"));
	}
	if (ft_strcmp(ft_strrchr(path, '.'), XPM))
	{
		ft_printf("ERROR: %s <path_to_file.xpm>\n", id);
		return (ft_printf("/!\\ invalid file extension\n"));
	}
	return (0);
}

static int	check_number_of_arguments(char **tab, char *id)
{
	int i;

	i = 0;
	while (tab[i])
		++i;
	if (i != 1)
	{
		i = -1;
		while (tab[++i])
			ft_free(tab[i]);
		ft_free(tab);
		ft_printf("ERROR: %s <path_to_file.xpm>\n", id);
		return (ft_printf("/!\\ wrong nb of arguments\n"));
	}
	return (0);
}

int			parse_texture(char **path, char *line, char *id)
{
	char	**tab;
	int		i;

	if (*path)
		return (ft_printf("ERROR: %s texture described more than once\n", id));
	tab = ft_split(line, " ");
	if (check_number_of_arguments(tab, id))
		return (1);
	i = 0;
	while (tab[i])
	{
		*path = ft_strdup(tab[i]);
		ft_free(tab[i]);
		++i;
	}
	ft_free(tab);
	if (check_texture_exist(*path, id))
		return (1);
	return (0);
}
