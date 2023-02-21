#include "cube.h"

void	draw_player(t_map *map, int x, int y)
{
	int	i;
	int	j;
	int	x0;
	int	y0;

	i = 0;
	j = 0;
	while (j < 6)
	{
		i = 0;
		while (i <= 360)
		{
			x0 = cos(i) * j;
			y0 = sin(i) * j;
			mlx_pixel_put(map->t.mlx, map->t.mlx_win, x0 + x + (SIZE / 2 - 1), y0 + y + (SIZE / 2 - 2), 0xFF);
			i++;
		}
		j++;
	}
}

void	my_mlx_pixel_put(t_win *t, int color, int x, int y)
{
	int	i;
	int	j;
	int	r;

	r = 0;
	if (color == (0xFFFF))
		r = 5;
	i = r;
	while (i < SIZE - r - 1)
	{
		j = r;
		while (j < SIZE - r - 1)
		{
			mlx_pixel_put(t->mlx, t->mlx_win, x + i, y + j, color);
			j++;
		}
		j = r;
		i++;
	}
}

void	ft_draw_map(t_map **head_map)
{
	t_map	*map;
	int		i;
	int		j;

	i = 0;
	map = *head_map;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '0' || map->map[i][j] == map->pos)
				my_mlx_pixel_put(&(map->t), (0x000000), j * SIZE, i * SIZE);
			if (map->map[i][j] == '1')
				my_mlx_pixel_put(&(map->t), (0xFFFFFF), j * SIZE, i * SIZE);
			if (map->map[i][j] == map->pos)
				draw_player(map, j * SIZE, i * SIZE);
			j++;
		}
		i++;
	}
}

void	render_map(t_map *map)
{
	map->t.mlx = mlx_init();
	map->t.mlx_win = mlx_new_window(map->t.mlx, (map->max_len * SIZE), (map->size_tab * SIZE), "Minimap");
	ft_draw_map(&map);
	mlx_hook(map->t.mlx_win, 2, 14, exec_key, map);
	mlx_loop(map->t.mlx);
}