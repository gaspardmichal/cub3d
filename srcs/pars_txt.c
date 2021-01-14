/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_txt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:58:01 by gamichal          #+#    #+#             */
/*   Updated: 2021/01/14 15:25:28 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_fd_ext(char *txt)
{
	int fd;

	if ((fd = open(txt, O_DIRECTORY) >= 0))
		return (print_error(ft_printf("Error: XX <path.xpm>\n") - 23));
	fd = open(txt, O_RDONLY);
	if (fd < 0)
		return (print_error(ft_printf("Error: XX <path.xpm>\n") - 23));
	if (ft_strcmp(ft_strrchr(txt, '.'), XPM))
		return (print_error(ft_printf("Error: XX <path.xpm>\n") - 24));
	return (0);
}

int		check_txt(char **tab)
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

int		pars_txt(char **txt, char *line)
{
	char	**tab;
	int		i;

	if (*txt)
		return (print_error(ft_printf("Error: XX <path.xpm>\n") - 37));
	if (!(tab = ft_split(line, " ")))
		return (print_error2(-3));
	if (check_txt(tab))
		return (-1);
	i = -1;
	while (tab[++i])
		*txt = ft_strdup(tab[i]);
	ft_free_tab(tab);
	if (!*txt)
		return (print_error2(-3));
	if (check_fd_ext(*txt))
		return (-1);
	return (0);
}
