
#include "cube.h"

int	main (int ac, char **av)
{
	t_map	map;
	map.map = NULL;
	map.map = clone_data(ac, av[1], &map);
	print2d(map.map);
}
