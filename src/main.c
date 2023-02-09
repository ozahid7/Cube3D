/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:49:19 by ozahid-           #+#    #+#             */
/*   Updated: 2023/02/09 06:15:47 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cube.h"

char	**clone_data(int ac, char *av, t_map *map)
{
	int		fd;
	char	*path;
	char	*line;
	int		len;
	
	fd = 0;
	len = 0;
	if (ac != 2)
		return(print(2, "Invalid Arguments\n"), NULL);
	if (check_extention(av))
		return(print(2, "Extention Error\n"), NULL);
	path = ft_strjoin(ft_strdup("maps/"), av);
	free(path);
	fd = open(path, O_RDWR);
	if (fd == -1)
		return (print(1, "Opening File Error\n"), NULL);
	line = get_next_line(fd);
	while (line)
	{
		map->map = get_map(map->map, line);
		line = get_next_line(fd);
	}
	return(map->map);
}

int	main (int ac, char **av)
{
	t_map	map;
	map.map = NULL;
	map.map = clone_data(ac, av[1], &map);
}
