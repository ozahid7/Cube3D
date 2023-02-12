
#include "cube.h"



int	main (int ac, char **av)
{
	t_map	map;
	char	**file;

	file = NULL;
	file = clone_data(ac, av[1]);
	split_file(&map, file);
	print2d(map.paco);
	print2d(map.map);
}
