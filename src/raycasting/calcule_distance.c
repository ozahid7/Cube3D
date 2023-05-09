/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 08:37:21 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/06 16:28:50 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

double	distance_between_points(double x_p, double y_p, double x, double y)
{
	return (sqrt((x - x_p) * (x - x_p) + (y - y_p) * (y - y_p)));
}

int	save_horizontal_distance(t_map *map, t_point p, double dis, int texture)
{
	map->rays.distance = dis;
	map->rays.wall_hit_x = p.x;
	map->rays.wall_hit_y = p.y;
	map->rays.hit_vertical = 0;
	if (map->rays.face_down)
	{
		map->no.tofx = ((int)map->rays.wall_hit_x) % map->no.height;
		texture = 1;
	}
	else
	{
		map->so.tofx = ((int)map->rays.wall_hit_x) % map->so.height;
		texture = 2;
	}
	return (texture);
}

int	save_vertical_distance(t_map *map, t_point p, double dis, int texture)
{
	map->rays.distance = dis;
	map->rays.wall_hit_x = p.x;
	map->rays.wall_hit_y = p.y;
	map->rays.hit_vertical = 1;
	if (map->rays.face_right)
	{
		map->we.tofx = ((int)map->rays.wall_hit_y) % map->we.height;
		texture = 4;
	}
	else
	{
		map->ea.tofx = ((int)map->rays.wall_hit_y) % map->ea.height;
		texture = 3;
	}
	return (texture);
}

int	choose_texture(t_map *map, t_point h, t_point v, t_point dis)
{
	int	texture;

	texture = 0;
	if (dis.x < dis.y)
	{
		texture = save_horizontal_distance(map, h, dis.x, texture);
	}
	else
	{
		texture = save_vertical_distance(map, v, dis.y, texture);
	}
	return (texture);
}

void	get_distance(t_map *map, int x)
{
	t_point	dis;
	t_point	v;
	t_point	h;
	int		texture;

	v = intersiction_wall_vertical(map, &map->rays.calc);
	h = intersiction_wall_horiz(map, &map->rays.calc);
	dis.x = 1e28;
	dis.y = 1e28;
	if (map->rays.calc.is_wall_h)
		dis.x = distance_between_points(map->player.x_screen, \
		map->player.y_screen, h.x, h.y);
	if (map->rays.calc.is_wall_v)
		dis.y = distance_between_points(map->player.x_screen, \
		map->player.y_screen, v.x, v.y);
	texture = choose_texture(map, h, v, dis);
	draw_walls(map, x, texture);
}
