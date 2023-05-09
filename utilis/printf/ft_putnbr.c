/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:03:46 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 11:03:47 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_putnbr(int fd, long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		i += ft_putchar(fd, '-');
		nb = -nb;
	}
	if (nb < 10 && nb >= 0)
	{
		i += ft_putchar(fd, nb + 48);
	}
	else
	{
		i += ft_putnbr(fd, nb / 10);
		i += ft_putnbr(fd, nb % 10);
	}
	return (i);
}
