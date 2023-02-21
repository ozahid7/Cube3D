
#include "cube.h"



int	main (int ac, char **av)
{
	t_map	mapp;
	t_map	*map;
	char	**file;
	char	**paco;

	file = clone_data(ac, av[1]);
	if (!file)
		return (0);
	paco = split_file(&mapp, file);
	if (paco && paco[1])
		parse_paco(&mapp, paco);

	map = ft_lstnew(&mapp);
	map = remplir_map(map);
	map->p = init_player();
	if (!parse_map(map))
		exit(1);
	render_map(map);
}
