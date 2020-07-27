/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:51:52 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:08:48 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	if (!dst && !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (size > 1 && src[i])
	{
		dst[i] = src[i];
		++i;
		--size;
	}
	dst[i] = 0;
	j = i;
	while (dst[i] || src[j])
	{
		if (src[j])
			++j;
	}
	return (j);
}
