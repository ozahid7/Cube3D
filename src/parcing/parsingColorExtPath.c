
#include "../../inc/cube.h"
int	putnew(char **paco)
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

int	parse_path(char **ptr)
{
	int		i;
	int 	fd;
	int		j;
	char	**paco;

	i = 0;
	j = 0;
	putnew(ptr);
	//check split[0] and init t_dir vars
	while(ptr[i])
	{
		paco = ft_split(ptr[i], ' ');
		if (paco[0] && len2d(paco) != 2)
			return (1);
		if (paco[0])
			j++;
		if (paco[0][0] != '\n' && (ft_strcmp(paco[0], "NO")
			|| ft_strcmp(paco[0], "SO") || ft_strcmp(paco[0], "EA")
		|| ft_strcmp(paco[0], "WE")))
		{
			fd = open(paco[1], O_RDWR);
			if (fd == -1)
				return (1);
		}
		i++;
		free2d(paco);
	}
	if (j != 6)
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

int	parse_paco(char **paco)
{
	parse_path(paco);
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
