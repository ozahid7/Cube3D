/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:03:32 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 11:03:33 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_counterp(unsigned long n)
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

void	ft_rcrsvp(int fd, unsigned long nb, char *base)
{
	if (nb >= 16)
	{
		ft_rcrsvp(fd, nb / 16, base);
		ft_rcrsvp(fd, nb % 16, base);
	}
	else
	{
		ft_putchar(fd, base[nb]);
	}
}

int	ft_argp(int fd, unsigned long nb)
{
	int		i;
	char	*base;

	i = ft_counterp(nb);
	base = "0123456789abcdef";
	i += ft_putstr(fd, "0x");
	ft_rcrsvp(fd, nb, base);
	return (i);
}
