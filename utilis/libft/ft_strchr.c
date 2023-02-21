
#include "../../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == 0)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char) c)
		{
			return ((char *) s + i);
		}
		i++;
	}
	if (c == '\0')
		return ((char *) s + i);
	return (NULL);
}
