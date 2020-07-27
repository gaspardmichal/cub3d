/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 07:24:23 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:05:08 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*ptr_dst;
	char		*ptr_src;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	i = 0;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		++i;
	}
	return (dst);
}
