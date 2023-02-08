/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:49:19 by ozahid-           #+#    #+#             */
/*   Updated: 2023/02/09 00:40:11 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cube.h"

void	clone_data(int ac, char *av, t_map *map)
{
	int		fd;
	char	*line;
	(void)map;
	
	fd = 0;
	if (ac != 2)
		print(2, "Invalid Arguments\n");
	if (check_extention(av))
		print(2, "Extention Error\n");
	if(open_file(fd, av))
		print(2, "Opning File Error\n");
	line = get_next_line(fd);
	print(1, "here\n");
	// while (line)
	// {
	// 	//map->map = get_map(map->map, line);
	// 	line = get_next_line(fd);
	// }
}

int	main (int ac, char **av)
{
	t_map	map;
	
	map.map = NULL;
	clone_data(ac, av[1], &map);	
}
