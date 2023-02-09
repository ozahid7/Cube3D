/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:49:19 by ozahid-           #+#    #+#             */
/*   Updated: 2023/02/09 16:05:31 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(void)
{
	// int		fd;
	t_map	*map;

	map = NULL;
	// if (ac != 2)
	// 	exit(1);
	// if (check_extention(av[1]))
	// 	print(2, "Extention Error\n");
	// fd = open("maps/map.cub", O_RDONLY);
	// if (fd == -1)
	// 	print(2, "MapFile Error\n");
	map = remplir_map(map);
	if (!parse_map(map))
		exit(1);
	print(1, "okey\n");
}
