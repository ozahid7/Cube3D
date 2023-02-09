#include "cube.h"

char	**clone_data(int ac, char *av, t_map *map)
{
	int		fd;
	char	*path;
	char	*line;
	int		len;

	fd = 0;
	len = 0;
	if (ac != 2)
		return (print(2, "Invalid Arguments\n"), NULL);
	if (check_extention(av))
		return (print(2, "Extention Error\n"), NULL);
	path = ft_strjoin(ft_strdup("maps/"), av);
	free(path);
	fd = open(path, O_RDWR);
	if (fd == -1)
		return (print(1, "Opening File Error\n"), NULL);
	line = get_next_line(fd);
	while (line)
	{
		map->tab = get_map(map->tab, line);
		line = get_next_line(fd);
	}
	return (map->tab);
}

int	main(int ac, char **av)
{
	t_map	*map;

	map->tab = NULL;
	map->tab = clone_data(ac, av[1], map);
	map = remplir_map(map);
	if (!parse_map(map))
		exit(1);
	print2d(map->tab);
}
