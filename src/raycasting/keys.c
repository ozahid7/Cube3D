/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:51:11 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 10:33:00 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

int	release_key(int key, t_map *map)
{
	if (key == 13)
		map->player.deplacement_directiony = 0;
	else if (key == 1)
		map->player.deplacement_directiony = 0;
	if (key == 0)
		map->player.deplacement_directionx = 0;
	else if (key == 2)
		map->player.deplacement_directionx = 0;
	if (key == 123)
		map->player.rotation_direction = 0;
	else if (key == 124)
		map->player.rotation_direction = 0;
	return (0);
}

int	exec_key(int key, t_map *map)
{
	if (key == 53)
		exit(0);
	if (key == 13)
		map->player.deplacement_directiony = 1;
	else if (key == 1)
		map->player.deplacement_directiony = -1;
	if (key == 0)
		map->player.deplacement_directionx = -1;
	else if (key == 2)
		map->player.deplacement_directionx = 1;
	if (key == 123)
			map->player.rotation_direction = -1;
	else if (key == 124)
			map->player.rotation_direction = 1;
	return (0);
}

int	ft_exit(t_map *map)
{
	(void) map;
	exit(0);
	return (0);
}
