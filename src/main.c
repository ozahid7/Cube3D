/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:49:19 by ozahid-           #+#    #+#             */
/*   Updated: 2023/02/09 02:26:32 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cube.h"

char	**clone_data(int ac, char *av, t_map *map)
{
	int		fd;
	//char	*line;
	char	*path;
	int		len;
	
	fd = 0;
	len = 0;
	if (ac != 2)
		return(print(2, "Invalid Arguments\n"), NULL);
	if (check_extention(av))
		return(print(2, "Extention Error\n"), NULL);
	path = ft_strjoin(ft_strdup("maps/"), av);
	map->map = ft_alloc(path, map);
	return(map->map);
}

int	main (int ac, char **av)
{
	t_map	map;
	
	map.map = clone_data(ac, av[1], &map);
}
