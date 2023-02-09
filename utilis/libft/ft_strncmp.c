#include "../../inc/libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1 && s2 && (s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		if ((unsigned char) s1[i] == (unsigned char) s2[i])
			i++;
		else if ((unsigned char) s1[i] > (unsigned char) s2[i])
			return (1);
		else
			return (-1);
	}
	return (0);
}
