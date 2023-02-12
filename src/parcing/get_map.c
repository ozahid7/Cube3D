#include "../../inc/cube.h"

char	**clone_data(int ac, char *av, t_map *map)
{
	int		fd;
	char	*path;
	char	*line;
	int		len;
	
	fd = 0;
	len = 0;
	if (ac != 2)
		return(print(2, "Invalid Arguments\n"), NULL);
	if (check_extention(av))
		return(print(2, "Extention Error\n"), NULL);
	path = ft_strjoin(ft_strdup("maps/"), av);
	free(path);
	fd = open(path, O_RDWR);
	if (fd == -1)
		return (print(1, "Opening File Error\n"), NULL);
	line = get_next_line(fd);
	while (line)
	{
		map->map = get_map(map->map, line);
		line = get_next_line(fd);
	}
	return(map->map);
}

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