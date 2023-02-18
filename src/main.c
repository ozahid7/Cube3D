
#include "cube.h"



int	main (int ac, char **av)
{
	t_map	map;
	t_dir	*dir;
	t_color	*color;
	char	**file;
	char	**paco;

	file = NULL;
	paco = NULL;
	if (ac != 2)
		return (print(2, "Invalid Arguments\n"), 0);
	dir = &map.dir;
	color = &dir->color;
	file = clone_data(av[1]);
	paco = split_file(&map, file);
	if (paco && paco[1])
		parse_paco(&map, paco);
}
