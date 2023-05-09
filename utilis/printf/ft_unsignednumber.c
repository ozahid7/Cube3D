/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignednumber.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:03:53 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 11:03:54 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_unsignednumber(int fd, unsigned int nb)
{
	int	i;

	i = 0;
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
