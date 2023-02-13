
#include "../../inc/cube.h"

int	parse_path(char *ptr)
{
	int		i;
	int 	fd;
	char	**paco;

	i = 0;
	paco = ft_split(ptr, ' ');
	if (ft_strcmp(paco[0], "NO")
		&& ft_strcmp(paco[0], "SO") && ft_strcmp(paco[0], "EA")
	&& ft_strcmp(paco[0], "WE"))
		return (print(2, "Paco In Map Error\n"), 1);
	print(1, "paco 1 = %s \n", paco[1]);
	fd = open(paco[1], O_CREAT | O_RDWR);
	if (fd == -1)
		return (print(2, "Opning Path In Map Error\n"), 1);
	return (0);
}

int	parse_paco(char **paco)
{
	int	i;

	i = 0;
	while(paco[i] && paco[i][0] != '\0')
	{
		parse_path(paco[i]);
		i++;
	}
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
