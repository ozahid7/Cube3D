
#include "cube.h"



int	main (int ac, char **av)
{
	t_map	map;
	char	**file;

	file = NULL;
	file = clone_data(ac, av[1]);
	split_file(&map, file);
	if (map.paco && map.paco[1])
		parse_paco(map.paco);
}
