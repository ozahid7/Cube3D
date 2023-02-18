#include "../../inc/cube.h"

char	**clone_data(char *av)
{
	int		fd;
	char	*line;
	char	**file;
	int		len;

	fd = 0;
	len = 0;
	file = NULL;
	if (check_extention(av))
		return (print(2, "Extention Error\n"), NULL);
	fd = open(av, O_RDWR);
	if (fd == -1)
		return (print(1, "Opening File Error\n"), NULL);
	line = get_next_line(fd);
	while (line)
	{
		file = get_file(file, line);
		line = get_next_line(fd);
	}
	return (file);
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

char	**get_file(char **str, char *allocate)
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
