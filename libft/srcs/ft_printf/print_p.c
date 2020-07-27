/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:27:46 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/22 18:43:07 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int		get_n_encoding(unsigned long int n, const char *base)
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

static void		charcat(char *dst, char c)
{
	int i;

	i = ft_strlen(dst);
	dst[i] = c;
	dst[i + 1] = 0;
}

static void		to_ascii(unsigned long int n, char *s, const char *base)
{
	unsigned int len;

	len = ft_strlen(base);
	if (n >= len)
		to_ascii(n / len, s, base);
	charcat(s, base[n % len]);
}

static char		*ft_utoa_base(unsigned long int n, const char *base)
{
	char *s;

	if (!(s = malloc(sizeof(char) * get_n_encoding(n, base) + 1)))
		return (NULL);
	*s = 0;
	to_ascii(n, s, base);
	return (s);
}

void			print_p(t_dota *dt)
{
	char	*p;
	int		offset;

	p = va_arg(dt->ap, void *);
	p = ft_utoa_base((unsigned long)p, dt->base);
	offset = ft_strlen(p);
	if (dt->minus == '0')
		print_p_no_flag(dt, p, offset);
	else if (dt->minus == '1')
		print_p_minus(dt, p, offset);
	free(dt->base);
	free(p);
}
