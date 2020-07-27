/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:06:28 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:07:30 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dst, const char *src)
{
	int i;
	int j;

	i = 0;
	while (dst[i])
	{
		++i;
	}
	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		++i;
		++j;
	}
	dst[i] = 0;
	return (dst);
}
