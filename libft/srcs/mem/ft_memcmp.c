/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:16:02 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:04:58 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ptr_s1;
	char	*ptr_s2;
	size_t	i;

	ptr_s1 = (char *)s1;
	ptr_s2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr_s1[i] == ptr_s2[i])
			++i;
		else
			return ((unsigned char)ptr_s1[i] - (unsigned char)ptr_s2[i]);
	}
	return (0);
}
