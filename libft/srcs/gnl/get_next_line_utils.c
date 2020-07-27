/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:46:25 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:03:22 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		endl(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

void	line_cat(char *dst, const char *src)
{
	size_t i;
	size_t j;

	if (!src)
		return ;
	i = ft_strlen(dst);
	j = 0;
	while (src[j])
	{
		if (src[j] == '\n')
			break ;
		dst[i] = src[j];
		++i;
		++j;
	}
	dst[i] = 0;
}

char	*line_join(char *line, char const *buffer)
{
	char	*s;

	if (!buffer)
		return (NULL);
	if (!(s = malloc(ft_strlen(line) + ft_strlen(buffer) + 1)))
		return (NULL);
	*s = 0;
	line_cat(s, line);
	line_cat(s, buffer);
	free(line);
	line = NULL;
	return (s);
}

char	*stringdup(const char *src)
{
	char	*dst;
	size_t	i;

	i = BUFFER_SIZE;
	if (!(dst = malloc(i + 1)))
		return (NULL);
	*dst = 0;
	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = 0;
	return (dst);
}
