/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:13:27 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 12:32:38 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	rotate_right(t_map *map, int x, int last)
{
	if (x > last)
	{
		map->player.rotation_angle += map->player.rotation_speed;
		map->player.rotation_angle = fmod(map->player.rotation_angle, 2 * M_PI);
		if (map->player.rotation_angle < 0)
			map->player.rotation_angle += 2 * M_PI;
	}
}

void	rotate_left(t_map *map, int x, int last)
{
	if (x < last)
	{
		map->player.rotation_angle -= map->player.rotation_speed;
		map->player.rotation_angle = fmod(map->player.rotation_angle, 2 * M_PI);
		if (map->player.rotation_angle < 0)
			map->player.rotation_angle += 2 * M_PI;
	}
}

int	ft_mouse(int x, int y, t_map *map)
{
	static int	last;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		mlx_clear_window(map->win.mlx, map->win.mlx_win);
		rotate_right(map, x, last);
		rotate_left(map, x, last);
		last = x;
		ft_draw_map(map);
	}
	return (0);
}
