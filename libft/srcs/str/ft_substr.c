/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:14:53 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:09:22 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len)
		len = 0;
	else
		len = len_s - start < len ? len_s - start : len;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	*str = 0;
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
