#include "../../inc/cube.h"

char	**get_paco(char **file, int len)
{
	int		i;
	char	**paco;

	i = 0;
	paco = NULL;
	paco = malloc(sizeof(char *) * len + 1);
	if (!paco)
		return (NULL);
	while (file[i] && i < len)
	{
		paco[i] = file[i];
		i++;
	}
	paco[i] = 0;
	return (paco);
}

void	get_map(t_map *map, char **file, int len, int j)
{
	int	i;

	i = 0;
	map->map = malloc(sizeof(char *) * len + 1);
	if (!map->map)
		return ;
	while (file[j])
	{
		map->map[i] = file[j];
		i++;
		j++;
	}
	map->map[i] = 0;
}

char	**split_file(t_map *map, char **file)
{
	int		i;
	size_t	j;
	int		len;
	char	**paco;

	i = 0;
	len = 0;
	while (file[i])
	{
		j = 0;
		if (file[i][j] == '1')
		{
			while (file[i] && file[i][j] == '1')
				j++;
			if (j == ft_strlen(file[i]))
				break ;
		}
		i++;
	}
	len = i;
	paco = get_paco(file, len);
	while (file[i])
		i++;
	get_map(map, file, i, len);
	return (paco);
}
