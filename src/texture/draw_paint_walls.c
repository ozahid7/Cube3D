/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_paint_walls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:04:02 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/09 16:58:56 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	draw_sky(t_map *data, int x, int tpixel)
{
	int	y;

	y = 0;
	while (y < tpixel)
	{
		my_mlx_pixel_put(&data->win.img, x, y, data->color.c);
		y++;
	}
}

void	draw_floor(t_map *data, int y, int x)
{
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(&data->win.img, x, y, data->color.f);
		y++;
	}
}

void	d_utils(t_map *data, t_walls *wall)
{
	if (data->rays.distance == 0.0)
		data->rays.distance = 1.0;
	wall->rayd = data->rays.distance * \
		cos (data->rays.ray_angle - data->player.rotation_angle);
	wall->dtp = (WIDTH / 2) / tan(data->player.vue_angle / 2);
	wall->pwh = (wall->dtp / wall->rayd) * SIZE;
	wall->wheight = (int)wall->pwh;
	wall->tpix = (HEIGHT / 2) - (wall->wheight / 2);
}

void	draw_walls(t_map *data, int x, int txt)
{
	t_walls	wall;
	int		texcolor;
	int		y;
	int		tmp;

	tmp = 0;
	d_utils(data, &wall);
	if (wall.tpix < 0 || wall.tpix > HEIGHT)
	{
		tmp = wall.tpix;
		wall.tpix = 0;
	}
	draw_sky(data, x, wall.tpix);
	y = wall.tpix;
	while (y < wall.tpix + wall.wheight)
	{
		wall.dif = y - wall.tpix + abs(tmp);
		texcolor = get_color(data, txt, wall.dif, wall.wheight);
		my_mlx_pixel_put(&data->win.img, x, y, texcolor);
		if (y > HEIGHT)
			break ;
		y++;
	}
	draw_floor(data, y, x);
}
