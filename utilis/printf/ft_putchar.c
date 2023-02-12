
#include "../../inc/ft_printf.h"

int	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}
