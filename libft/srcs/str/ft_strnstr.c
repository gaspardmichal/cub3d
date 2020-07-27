/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:41:35 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:09:07 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		n;
	size_t		i;
	const char	*start;

	i = 0;
	if (needle[i] == 0)
		return ((char *)haystack);
	n = ft_strlen(needle);
	while (haystack[i] && i < len)
	{
		if (needle[0] == haystack[i])
		{
			start = haystack + i;
			if (ft_strncmp(start, needle, n) == 0 && i + n <= len)
				return ((char *)start);
		}
		++i;
	}
	return (0);
}
