/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:53:25 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 09:53:26 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

t_ray_info	*ft_lstnew_rays(t_map *map)
{
	t_ray_info	*newlst;

	newlst = (t_ray_info *) malloc(sizeof(t_ray_info));
	if (!newlst)
		return (NULL);
	newlst->x_depart = map->player.x_screen;
	newlst->y_depart = map->player.y_screen;
	newlst->x_finish = map->rays.wall_hit_x;
	newlst->y_finish = map->rays.wall_hit_y;
	newlst->distance = map->rays.distance;
	newlst->next = NULL;
	return (newlst);
}

void	init_ray(t_map *newlst, t_map *map)
{
	newlst->rays.wall_width = 1;
	newlst->rays.num_rays = newlst->win.win_width / newlst->rays.wall_width;
	newlst->rays.ray_angle = map->player.rotation_angle - \
	(map->player.vue_angle / 2);
	newlst->rays.distance = 0;
	newlst->rays.wall_hit_x = 0;
	newlst->rays.wall_hit_y = 0;
	newlst->rays.id_col = 0;
	newlst->info_ray = NULL;
	newlst->rays.face_right = ((newlst->rays.ray_angle < (0.5 * M_PI)) || \
	(newlst->rays.ray_angle > (1.5 * M_PI)));
		newlst->rays.face_down = ((newlst->rays.ray_angle > 0) && \
	(newlst->rays.ray_angle < M_PI));
		newlst->rays.hit_vertical = 0;
}

t_map	*ft_lstnew(t_map *map, char mode)
{
	t_map	*newlst;

	newlst = (t_map *) malloc(sizeof(t_map));
	if (!newlst)
		return (NULL);
	newlst->map = map->map;
	newlst->max_len = get_max_len(map->map);
	newlst->size_tab = ft_size(map->map);
	newlst->win.mlx = NULL;
	newlst->dir = map->dir;
	newlst->color = map->color;
	newlst->win.mlx_win = NULL;
	newlst->direction = '\0';
	newlst->win.win_height = HEIGHT;
	newlst->win.win_width = WIDTH;
	newlst->mode = mode;
	init_ray(newlst, map);
	return (newlst);
}
