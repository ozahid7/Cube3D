
#include "../../inc/cube.h"
void	putnew(char **paco)
{
	int	i;

	i = 0;
	while (paco[i])
	{
		if (paco[i][0] == '\0')
			paco[i][0] = '\n';
		i++;
	}
}

void	init_dir(t_map *map, char **paco)
{
	if (!strcmp(paco[0], "NO"))
	{
		map->dir.n++;
		map->dir.no = paco[1];
	}
	else if (!strcmp(paco[0], "WE"))
	{
		map->dir.w++;
		map->dir.we = paco[1];
	}
	else if (!strcmp(paco[0], "EA"))
	{
		map->dir.e++;
		map->dir.ea = paco[1];
	}
	else if (!strcmp(paco[0], "SO"))
	{
		map->dir.s++;
		map->dir.so = paco[1];
	}
}

int	parse_path(t_map *map, char **ptr)
{
	int		i;
	int 	fd;
	int		j;
	char	**paco;

	i = 0;
	j = 0;
	putnew(ptr);
	while(ptr[i])
	{
		if (ptr[i][0] == '\n')
		{
			i++;
			continue;
		}
		paco = ft_split(ptr[i], ' ');
		if (!paco || len2d(paco) != 2)
			return (1);
		init_dir(map, paco);
		if (paco[0][0] != '\n' && (!ft_strcmp(paco[0], "NO")
			|| !ft_strcmp(paco[0], "SO") || !ft_strcmp(paco[0], "EA")
		|| !ft_strcmp(paco[0], "WE")))
		{

			fd = open(paco[1], O_CREAT | O_RDWR);
			if (fd == -1)
				return (1);
			close(fd);
		}
		i++;
		free2d(paco);
	}
	if (map->dir.e != 1 || map->dir.n != 1 || map->dir.s != 1 || map->dir.w != 1)
		return (1);
	return (0);
}

// int	parse_color(t_map *map, char **paco)
// {
// 	char	**color;
// 	int		r;
// 	int 	g;
// 	int		b;

// 	color = ft_split(paco[1], ',');
// 	if (len2d(color) != 3)
// 		print(2, "Invalid Colors\n");
	

// }

int	parse_paco(t_map *map, char **paco)
{
	map->dir.n = 0;
	map->dir.w = 0;
	map->dir.e = 0;
	map->dir.s = 0;
	if (parse_path(map, paco))
		return (print(1, "Path In Map Error\n"), 1);
	return (0);
}

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
