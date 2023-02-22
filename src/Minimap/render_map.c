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
			mlx_pixel_put(map->win.mlx, map->win.mlx_win, x0 + x + (SIZE / 2 - 1), y0 + y + (SIZE / 2 - 2), 0xFF);
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

void    ft_draw_map(t_map **head_map)
{
    t_map    *map;
    int        i;
    int        j;
    int        x;
    int        y;

    map = *head_map;
    i = map->player.x - 10;
    if (i < 0)
        i = 0;
    x = 0;
    while (map->map[i] && x <= 20)
    {
        j = map->player.y - 10;
        if (j < 0)
            j = 0;
        y = 0;
        while (map->map[i][j] && y <= 20)
        {
            if (map->map[i][j] == '0' || map->map[i][j] == map->direction)
                my_mlx_pixel_put(&(map->win), (0x000000), y * SIZE, x * SIZE);
            if (map->map[i][j] == '1')
                my_mlx_pixel_put(&(map->win), (0xFFFFFF), y * SIZE, x * SIZE);
            if (map->map[i][j] == map->direction)
                draw_player(map, y * SIZE, x * SIZE);
            j++;
            y++;
        }
        i++;
        x++;
    }
}

void	render_map(t_map *map)
{
	map->win.mlx = mlx_init();
	map->win.mlx_win = mlx_new_window(map->win.mlx, (21 * SIZE), (21 * SIZE), "Minimap");
	ft_draw_map(&map);
	mlx_hook(map->win.mlx_win, 2, 14, exec_key, map);
	mlx_loop(map->win.mlx);
}