/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:50:12 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/09 12:54:42 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	draw_minimap(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
				carre(&(map->win), (0xdda15e), i * SIZE, j * SIZE);
			j++;
		}
		i++;
	}
	draw_line(map);
	draw_player(map, map->player.x_screen, map->player.y_screen);
}

void	draw_player(t_map *map, int x, int y)
{
	int	i;
	int	j;
	int	x0;
	int	y0;

	i = 0;
	j = 0;
	while (j < 35)
	{
		i = 0;
		while (i <= 360)
		{
			x0 = cos(i) * j;
			y0 = sin(i) * j;
			my_mlx_pixel_put(&map->win.img, (x0 + x) * MF, \
			(y0 + y) * MF, 0xFFFFFF);
			i++;
		}
		j++;
	}
}

void	draw_line(t_map *map)
{
	int	j;
	int	x0;
	int	y0;

	j = 0;
	while (j < 200)
	{
		x0 = (int)floor(cos(map->player.rotation_angle) * j);
		y0 = (int)floor(sin(map->player.rotation_angle) * j);
		my_mlx_pixel_put(&map->win.img, (x0 + map->player.x_screen) * MF, \
		(y0 + map->player.y_screen) * MF, 0xFFFFFF);
		j++;
	}
}

void	carre(t_win *t, int color, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			my_mlx_pixel_put(&t->img, (x + j) * MF, (y + i) * MF, color);
			j++;
		}
		i++;
	}
}
