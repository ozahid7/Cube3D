/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 08:36:18 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/08 16:29:33 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	drawbackground(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			my_mlx_pixel_put(&data->win.img, j, i, 0xFF0000);
			j++;
		}
		i++;
	}
}

int	ft_draw_map(t_map *map)
{
	mlx_clear_window(map->win.mlx, map->win.mlx_win);
	freenode(map);
	update_player(map);
	cast_rays(map);
	if (map->mode == 'b')
		draw_minimap(map);
	mlx_put_image_to_window(map->win.mlx, map->win.mlx_win, \
	map->win.img.image, 0, 0);
	return (0);
}

void	render_map(t_map *map)
{
	map->win.mlx = mlx_init();
	map->win.mlx_win = mlx_new_window(map->win.mlx, WIDTH, HEIGHT, "Minimap");
	load_texture(map);
	map->win.img.image = mlx_new_image(map->win.mlx, WIDTH, HEIGHT);
	map->win.img.adrs = mlx_get_data_addr(map->win.img.image, \
		&map->win.img.bp, &map->win.img.line_len, &map->win.img.endian);
	mlx_hook(map->win.mlx_win, 3, 0, release_key, map);
	mlx_hook(map->win.mlx_win, 2, 0, exec_key, map);
	mlx_hook(map->win.mlx_win, 17, 0, ft_exit, map);
	if (map->mode == 'b')
		mlx_hook(map->win.mlx_win, 6, 0, ft_mouse, map);
	mlx_loop_hook(map->win.mlx, ft_draw_map, map);
	mlx_loop(map->win.mlx);
}
