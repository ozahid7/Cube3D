#include "../../inc/cube.h"

char	**ft_realoc(char **str, int len, char *allocate)
{
	int		i;
	char	**map;

	map = malloc(sizeof(char *) * (len + 2));
	i = 0;
	while (str && str[i])
	{
		map[i] = str[i];
		i++;
	}
	map[i++] = allocate;
	map[i] = 0;
	return (map);
}

char	**get_map(char **str, char *allocate)
{
	int		len;
	char	**map;

	len = 0;
	while (str && str[len])
		len++;
	map = ft_realoc(str, len, allocate);
	free (str);
	return (map);
}
