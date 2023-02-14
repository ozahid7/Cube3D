
#include "cube.h"



int	main (int ac, char **av)
{
	t_map	map;
	char	**file;
	char	**paco;

	file = NULL;
	paco = NULL;
	file = clone_data(ac, av[1]);
	paco = split_file(&map, file);
	print2d(paco);
	if (paco && paco[1])
		parse_paco(paco);
}
