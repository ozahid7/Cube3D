/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:49:19 by ozahid-           #+#    #+#             */
/*   Updated: 2023/02/09 00:10:02 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cube.h"

void	clone_data(int ac, char *av, t_map *map)
{
	int		fd;
	char	*path;
	char	*line;
	
	if (ac != 2)
		print(1, "Invalid Arguments\n");
	if (check_extention(av))
		print(2, "Extention Error\n");
	path = ft_strjoin(ft_strdup("maps/"), av);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd == -1)
		print(2, "Opening File Error\n");
	line = get_next_line(fd);
	while (line)
	{
		map->map = get_map(map->map, line);
		line = get_next_line(fd);
	}
}

int	main (int ac, char **av)
{
	t_map	map;
	
	map.map = NULL;
	clone_data(ac, av[1], &map);	
	while(1);
}
