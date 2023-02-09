#include "cube.h"

char	**clone_data(int ac, char *av)
{
	int		fd;
	char	*path;
	char	**str;
	char	*line;
	int		len;

	fd = 0;
	len = 0;
	str = NULL;
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
		str = get_map(str, line);
		line = get_next_line(fd);
	}
	return (str);
}

int	main(int ac, char **av)
{
	t_map	*map;
	char	**str;

	str = clone_data(ac, av[1]);
	map = ft_lstnew(str, get_max_len(str), ft_size(str));
	map = remplir_map(map);
	if (!parse_map(map))
		exit(1);
}
