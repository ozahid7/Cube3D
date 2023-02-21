
#include "../../inc/libft.h"

void	free2d(char **str)
{
	int	i;

	i = 0;
	if (str == 0)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
