/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 08:37:08 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 10:33:13 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	cast_rays(t_map *map)
{
	map->rays.id_col = 0;
	map->rays.ray_angle = map->player.rotation_angle - \
	(map->player.vue_angle / 2);
	while (map->rays.id_col < map->rays.num_rays)
	{
		map->rays.ray_angle = fmod(map->rays.ray_angle, 2 * M_PI);
		if (map->rays.ray_angle < 0)
			map->rays.ray_angle += 2 * M_PI;
		map->rays.face_right = ((map->rays.ray_angle < (0.5 * M_PI)) || \
		(map->rays.ray_angle > (1.5 * M_PI)));
		map->rays.face_down = ((map->rays.ray_angle > 0) && \
		(map->rays.ray_angle < M_PI));
		get_distance(map, map->rays.id_col);
		ft_lstadd_back(&(map->info_ray), ft_lstnew_rays(map));
		map->rays.ray_angle += map->player.vue_angle / map->rays.num_rays;
		map->rays.id_col++;
	}
}
