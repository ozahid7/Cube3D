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

int	print2d(char **str)
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

int	get_len(char *path)
{
	int		len;
	char	*line;
	int		fd;

	len = 0;
	fd = open(path, O_RDWR);
	if (fd == -1)
		return(print(2, "Opning File Error\n"), -1);
	line = get_next_line(fd);
	while (line)
	{
		len++;
		line = get_next_line(fd);
	}
	close(fd);
	return(len);
}

char	**ft_alloc(char *path, t_map *map)
{
	int		len;
	char	*line;
	int		i;
	int		fd;

	i = 0;
	len = get_len(path);
	fd = open(path, O_RDWR);
	if (fd == -1)
		return(print(2, "Opning File Error\n"), NULL);
	map->map = malloc(sizeof(char *) * len + 1);
	if (!map->map)
		return (NULL);
	print(1, "here\n");
	line = get_next_line(fd);
	while (map->map && line)
	{
		map->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map->map[i] = NULL;
	return(map->map);
}