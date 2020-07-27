/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:36:04 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:08:34 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *s;

	if (!s1 || !s2)
		return (NULL);
	if (!(s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	*s = 0;
	ft_strcat(s, s1);
	ft_strcat(s, s2);
	return (s);
}
