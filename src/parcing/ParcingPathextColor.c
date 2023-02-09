#include "../../inc/cube.h"

int	check_extention(char *av1)
{
	int		i;
	char	*ext;

	i = 0;
	if (av1 == 0)
		return (0);
	ext = ft_strrchr(av1, '.');
	if (ft_strncmp(ext, ".cub", 5) == 1)
		return (1);
	return (0);
}

char	**ft_realoc(char **str, int len, char *allocate)
{
	int		i;
	char	**map;

	map = malloc(sizeof(char *) * (len + 2));
	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			map[i] = str[i];
			i++;
		}
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
	if (str == NULL)
		len = 1;
	else
	{
		while (str[len])
			len++;
	}
	map = ft_realoc(str, len, allocate);
	free (str);
	return (map);
}
