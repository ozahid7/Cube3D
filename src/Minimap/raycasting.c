#include"cube.h"

void	player_vue(t_map *map, int x, int y)
{
	int	i;
	int	j;
	int	x0;
	int	y0;

	i = 0;
	j = 0;
	while (i < 50)
	{
		x0 = cos(map->player.rotation_angle) * i;
		y0 = sin(map->player.rotation_angle) * i;
		mlx_pixel_put(map->win.mlx, map->win.mlx_win, x + x0 + (SIZE / 2), y + y0 + (SIZE / 2), 0xFF);
		i++;
	}
}

void	cast_rays(t_map *map, int y, int x)
{
	int		col_id;
	int		i;
	int		j;
	int		x0;
	int		y0;

	col_id = 0;
	i = 0;
	map->rays.ray_angle = map->player.rotation_angle - (map->player.vue_angle / 2);
	draw_player(map, x, y);
	while (i < map->rays.num_rays)
	{
		j = 0;
		while (j < 100)
		{
			y0 = cos(map->rays.ray_angle) * j;
			x0 = sin(map->rays.ray_angle) * j;
			mlx_pixel_put(map->win.mlx, map->win.mlx_win, y + y0, x + x0, 0xFF);
			j++;
		}
		map->rays.ray_angle += map->player.vue_angle / map->rays.num_rays;
		col_id++;
		i++;
	}
}