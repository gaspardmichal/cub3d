/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:34:35 by gamichal          #+#    #+#             */
/*   Updated: 2020/09/29 15:37:44 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strcountchr(const char *s, int c)
{
	size_t i;
	size_t n;

	if (!s)
		return (0);
	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			++n;
		++i;
	}
	return (n);
}
