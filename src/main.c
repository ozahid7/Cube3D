
#include "cube.h"



int	main (int ac, char **av)
{
	t_map	map;
	//t_dir	dir;
	t_color	color;
	char	**file;
	char	**paco;

	file = NULL;
	paco = NULL;
	file = clone_data(ac, av[1]);
	paco = split_file(&map, file);
	if (paco && paco[1])
		parse_paco(&map, paco);
	print(1, "color f = %d | color c = %d \n", color.f, color.c);
}
