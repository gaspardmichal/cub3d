/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 09:27:15 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:08:42 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	check_null_byte(char *dst, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (!dst[i])
			break ;
		if (dst[i] && i == size - 1)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (i < size)
		j += i;
	else if (check_null_byte(dst, size) == FALSE)
		return (j + size);
	k = 0;
	while (src[k] && i + k + 1 < size)
	{
		dst[i + k] = src[k];
		++k;
	}
	dst[i + k] = 0;
	return (j);
}
