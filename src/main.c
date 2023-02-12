
#include "cube.h"

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
	map->paco = malloc(sizeof(char *) * len + 1);
	if (!map->paco)
		return ;
	while (file[i])
		i++;
	map->map = malloc(sizeof(char *) * i + 1);
	if (!map->map)
		return ;
	i = 0;
	while (file[i] && i < len)
	{
		map->paco[i] = file[i];
		i++;
	}
	map->paco[i] = 0;
	j = 0;
	while (file[i])
		map->map[j++] = file[i++];
	map->map[j] = 0;
	
}

int	main (int ac, char **av)
{
	t_map	map;
	char	**file;

	file = NULL;
	file = clone_data(ac, av[1]);
	split_file(&map, file);
	//print2d(map.paco);
	print2d(map.map);
}
