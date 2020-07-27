/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 06:06:00 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:09:17 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	is_set(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			end;
	char			*str;

	if (!s1)
		return (NULL);
	start = 0;
	while (is_set(set, s1[start]) == 1)
		++start;
	end = ft_strlen(s1) - 1;
	while (is_set(set, s1[end]) == 1 && start < end)
		--end;
	if (!(str = ft_substr(s1, start, end - start + 1)))
		return (NULL);
	return (str);
}
