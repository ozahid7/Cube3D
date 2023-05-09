/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule_intersiction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:51:07 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/08 18:44:15 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	get_vertical_step(t_map *map, t_calc *vertical)
{
	vertical->intercept.x = floor(map->player.x_screen / SIZE) * SIZE;
	if (map->rays.face_right)
		vertical->intercept.x += SIZE;
	vertical->intercept.y = map->player.y_screen + \
	(vertical->intercept.x - map->player.x_screen) * tan(map->rays.ray_angle);
	vertical->step.x = SIZE;
	if (!map->rays.face_right)
		vertical->step.x *= -1;
	vertical->step.y = vertical->step.x * tan(map->rays.ray_angle);
	vertical->next.x = vertical->intercept.x;
	vertical->next.y = vertical->intercept.y;
}

t_point	intersiction_wall_vertical(t_map *map, t_calc *vertical)
{
	double	x;

	get_vertical_step(map, vertical);
	while (inside_map(map, vertical->next.x, vertical->next.y))
	{
		x = vertical->next.x;
		if (!map->rays.face_right)
			x--;
		if (check_wall(x, vertical->next.y, map, 0))
		{
			vertical->is_wall_v = 1;
			vertical->wall.x = vertical->next.x;
			vertical->wall.y = vertical->next.y;
			break ;
		}
		else
		{
			vertical->is_wall_v = 0;
			vertical->next.x += vertical->step.x;
			vertical->next.y += vertical->step.y;
		}
	}
	return (vertical->wall);
}

void	get_horizontal_step(t_map *map, t_calc *horizontal)
{
	horizontal->intercept.y = floor(map->player.y_screen / SIZE) * SIZE;
	if (map->rays.face_down)
		horizontal->intercept.y += SIZE;
	horizontal->intercept.x = map->player.x_screen + \
	(horizontal->intercept.y - map->player.y_screen) / tan(map->rays.ray_angle);
	horizontal->step.y = SIZE;
	if (!map->rays.face_down)
		horizontal->step.y *= -1;
	horizontal->step.x = horizontal->step.y / tan(map->rays.ray_angle);
	horizontal->next.x = horizontal->intercept.x;
	horizontal->next.y = horizontal->intercept.y;
}

t_point	intersiction_wall_horiz(t_map *map, t_calc *horizontal)
{
	double	y;

	get_horizontal_step(map, horizontal);
	while (inside_map(map, horizontal->next.x, horizontal->next.y))
	{
		y = horizontal->next.y;
		if (!map->rays.face_down)
			y--;
		if (check_wall(horizontal->next.x, y, map, 0))
		{
			horizontal->is_wall_h = 1;
			horizontal->wall.x = horizontal->next.x;
			horizontal->wall.y = horizontal->next.y;
			break ;
		}
		else
		{
			horizontal->is_wall_h = 0;
			horizontal->next.x += horizontal->step.x;
			horizontal->next.y += horizontal->step.y;
		}
	}
	return (horizontal->wall);
}
