/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:03:39 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 11:03:40 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_print(int fd, char c, va_list ptr)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += ft_putchar(fd, va_arg(ptr, int));
	else if (c == 'd')
		counter += ft_putnbr(fd, va_arg(ptr, int));
	else if (c == 'i')
		counter += ft_putnbr(fd, va_arg(ptr, int));
	else if (c == 's')
		counter += ft_putstr(fd, va_arg(ptr, char *));
	else if (c == 'u')
		counter += ft_unsignednumber(fd, va_arg(ptr, unsigned int));
	else if (c == 'x' || c == 'X')
		counter += ft_hexa(fd, va_arg(ptr, unsigned int), c);
	else if (c == 'p')
		counter += ft_argp(fd, va_arg(ptr, unsigned long));
	else
		counter += ft_putchar(fd, c);
	return (counter);
}

int	print(int fd, const char *str, ...)
{
	int		i;
	int		counter;
	va_list	ptr;

	i = 0;
	counter = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			counter += ft_print(fd, str[i], ptr);
		}
		else
			counter += ft_putchar(fd, str[i]);
		i++;
	}
	va_end(ptr);
	return (counter);
}
