/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 07:16:58 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:05:12 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ptr_dst;
	const char	*ptr_src;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	if (dst > src)
	{
		i = 0;
		while (i < len)
		{
			ptr_dst[len - i - 1] = ptr_src[len - i - 1];
			++i;
		}
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
