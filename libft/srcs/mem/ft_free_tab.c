/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:32:39 by gamichal          #+#    #+#             */
/*   Updated: 2020/10/16 15:41:09 by gamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_free_tab(char **tab)
{
	int i;

	i = -1;
	while (tab && tab[++i])
		ft_free(tab[i]);
	ft_free(tab);
}
