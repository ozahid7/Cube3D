/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:51:18 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/08 18:30:43 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	normalise_angle(t_map *map)
{
	if (map->player.rotation_direction != 0)
		map->player.rotation_angle += map->player.rotation_direction \
		* map->player.rotation_speed;
	map->player.rotation_angle = fmod(map->player.rotation_angle, 2 * M_PI);
	if (map->player.rotation_angle < 0)
		map->player.rotation_angle += 2 * M_PI;
}

void	update_player(t_map *map)
{
	double	step;
	t_point	pos;

	pos.x = map->player.x_screen;
	pos.y = map->player.y_screen;
	step = map->player.deplacement_directiony * map->player.move_speed;
	normalise_angle(map);
	pos.x += cos(map->player.rotation_angle) * step;
	pos.y += sin(map->player.rotation_angle) * step;
	step = map->player.deplacement_directionx * map->player.move_speed;
	pos.x += cos(map->player.rotation_angle + M_PI_2) * step;
	pos.y += sin(map->player.rotation_angle + M_PI_2) * step;
	if (!check_wall(pos.x, pos.y, map, 1))
	{
		map->player.x_screen = pos.x;
		map->player.y_screen = pos.y;
	}
	map->player.x = (int)floor(map->player.x_screen / SIZE);
	map->player.y = (int)floor(map->player.y_screen / SIZE);
	map->rays.face_right = ((map->rays.ray_angle < (0.5 * M_PI)) || \
		(map->rays.ray_angle > (1.5 * M_PI)));
	map->rays.face_down = ((map->rays.ray_angle > 0) && \
		(map->rays.ray_angle < M_PI));
}
