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

int	tab2dlen(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
	{
		print(1, "%s", str[i]);
		i++;
	}
	return (i);
}

char	**ft_realloc(char **map, int len, char *alocate)
{
	char	**tmp;
	int		i;

	tmp = malloc(sizeof(char *) * len + 2);
	if (!tmp)
		return (NULL);
	i = 0;
	while (map && i < len){
		tmp[i] = map[i];
		i++;
	}
	tmp[i++] = alocate;
	tmp[i] = NULL;
	return (tmp);
}


char	**get_map(char **map, char *line)
{
	
	int		len;
	char	**tmp = NULL;
	
	len = 0;
	while (map && map[len])
	{
		len++;
	}
	tmp = ft_realloc(map, len, line);
	return (tmp);
}