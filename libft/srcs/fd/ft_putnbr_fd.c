/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:47:37 by gamichal          #+#    #+#             */
/*   Updated: 2020/02/20 17:58:26 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr_fd(long int n, int fd)
{
	char c;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	c = n % 10 + '0';
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(c, fd);
}
