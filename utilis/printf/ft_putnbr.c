
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
