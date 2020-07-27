/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 08:03:13 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:03:15 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	get_n_encoding(long int n)
{
	int n_encoding;

	n_encoding = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		++n_encoding;
	}
	return (n_encoding);
}

static void	charcat(char *dst, char c)
{
	int i;

	i = ft_strlen(dst);
	dst[i] = c;
	dst[i + 1] = 0;
}

static void	to_ascii(long int n, char *s)
{
	if (n < 0)
	{
		charcat(s, '-');
		n = -n;
	}
	if (n >= 10)
		to_ascii(n / 10, s);
	charcat(s, n % 10 + '0');
}

char		*ft_itoa(long int n)
{
	char *s;

	if (n < 0)
	{
		if (!(s = malloc(sizeof(char) * get_n_encoding(n) + 2)))
			return (NULL);
	}
	else
	{
		if (!(s = malloc(sizeof(char) * get_n_encoding(n) + 1)))
			return (NULL);
	}
	*s = 0;
	to_ascii(n, s);
	return (s);
}
