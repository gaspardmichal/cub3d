/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 06:09:23 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 18:04:45 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *memory;

	if (!(memory = malloc(size * count)))
		return (NULL);
	ft_bzero(memory, size * count);
	return (memory);
}
