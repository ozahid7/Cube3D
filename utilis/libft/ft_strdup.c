
#include "../../inc/libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;
	if (s == 0)
		return (0);
	p = (char *)malloc(ft_strlen(s) + 1);
	i = 0;
	if (!p)
		return (NULL);
	while (s[i] != '\0')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
