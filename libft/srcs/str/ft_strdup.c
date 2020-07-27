/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:14:47 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:08:29 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(src);
	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	*dst = 0;
	ft_strcpy(dst, src);
	return (dst);
}
