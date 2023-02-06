/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:49:19 by ozahid-           #+#    #+#             */
/*   Updated: 2023/02/06 23:44:13 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cube.h"

int	main (int ac, char **av)
{
	int	fd;
	(void)ac;
	
	if (check_extention(av[1]))
		print(2, "Extention Error\n");
	fd = open("../maps/map.cub", O_RDONLY);
	if (fd == -1)
		print(2, "MapFile Error\n");
		
}