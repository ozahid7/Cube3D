#include "../../inc/cube.h"

void	print2d(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while(str[i])
	{
		print(1, "%s\n", str[i]);
		i++;
	}
}

int	len2d(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
		i++;
	return (i);
}