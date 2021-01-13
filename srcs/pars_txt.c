/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_txt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:58:01 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/07 16:58:03 by gamichal         ###   ########.fr       */
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
	{
		ft_free_tab(tab);
		return (print_error(ft_printf("Error: XX <path.xpm>\n") - 26));
	}
	return (0);
}

int			parse_txt(char **path, char *line)
{
	char	**tab;
	int		i;

	if (*path)
		return (print_error(ft_printf("Error: XX <path.xpm>\n") - 37));
	if (!(tab = ft_split(line, " ")))
		return (print_error2(-3));
	if (check_txt(tab))
		return (-1);
	i = -1;
	while (tab[++i])
		*path = ft_strdup(tab[i]);
	ft_free_tab(tab);
	if (!*path)
		return (print_error2(-3));
	if (check_fd_ext(*path))
		return (-1);
	return (0);
}
