/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:03:35 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 11:03:36 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_counter(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

void	ft_rcrsv(int fd, unsigned int nb, char *base)
{
	if (nb >= 16)
	{
		ft_rcrsv(fd, nb / 16, base);
		ft_rcrsv(fd, nb % 16, base);
	}
	else
		ft_putchar(fd, base[nb]);
}

int	ft_hexa(int fd, unsigned int nb, char arg)
{
	int		i;
	char	*base;

	i = ft_counter(nb);
	if (arg == 'x')
		base = "0123456789abcdef";
	if (arg == 'X')
		base = "0123456789ABCDEF";
	ft_rcrsv(fd, nb, base);
	return (i);
}
