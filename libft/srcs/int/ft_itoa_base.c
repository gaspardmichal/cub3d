/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:21:11 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:03:17 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	get_n_encoding(long int n, const char *base)
{
	int n_encoding;

	n_encoding = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= ft_strlen(base);
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

static void	to_ascii(long int n, char *s, const char *base)
{
	int len;

	len = ft_strlen(base);
	if (n < 0)
	{
		charcat(s, '-');
		n = -n;
	}
	if (n >= len)
		to_ascii(n / len, s, base);
	charcat(s, base[n % len]);
}

char		*ft_itoa_base(long int n, const char *base)
{
	char *s;

	if (n < 0)
	{
		if (!(s = malloc(sizeof(char) * get_n_encoding(n, base) + 2)))
			return (NULL);
	}
	else
	{
		if (!(s = malloc(sizeof(char) * get_n_encoding(n, base) + 1)))
			return (NULL);
	}
	*s = 0;
	to_ascii(n, s, base);
	return (s);
}
