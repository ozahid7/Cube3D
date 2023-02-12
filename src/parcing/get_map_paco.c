#include "../../inc/cube.h"

void	get_paco(t_map *map, char **file, int len)
{
	int	i;

	i = 0;
	map->paco = malloc(sizeof(char *) * len + 1);
	if (!map->paco)
		return ;
	while (file[i] && i < len)
	{
		map->paco[i] = file[i];
		i++;
	}
	map->paco[i] = 0;
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

void	split_file(t_map *map, char **file)
{
	int		i;
	size_t	j;
	int		len;

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
	get_paco(map, file, len);
	while (file[i])
		i++;
	get_map(map, file, i, len);
}
