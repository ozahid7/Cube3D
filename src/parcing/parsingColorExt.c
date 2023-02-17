
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

void	get_rgb(t_map *map, char **paco)
{
	if (!strcmp(paco[0], "C"))
	{
		map->dir.ci++;
		map->dir.c = ft_strdup(paco[1]);
	}
	else if (!strcmp(paco[0], "F"))
	{
		map->dir.fi++;
		map->dir.f = ft_strdup(paco[1]);
	}
}

int	parse_rgb(char **cf)
{
	int	r;
	int g;
	int	b;
	int	color;

	r = ft_atoi(cf[0]);
	g = ft_atoi(cf[1]);
	b = ft_atoi(cf[2]);
	r = r<<16;
	g = g<<8;
	color = r + g + b;
	return (color);
}

int	parse_color(t_map *map)
{
	char	**floor;
	char	**ceiling;
	
	floor = NULL;
	ceiling = NULL;
	floor = ft_split(map->dir.f, ',');
	if (len2d(floor) != 3)
		return (1);
	map->dir.color.f = parse_rgb(floor);
	ceiling = ft_split(map->dir.c, ',');
	if (len2d(ceiling) != 3)
		return (1);
	map->dir.color.c = parse_rgb(ceiling);
	return (0);
}