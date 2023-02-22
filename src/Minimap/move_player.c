# include"cube.h"

void	player_left(t_map *map)
{
	int	i;
	int	j;

	i = map->player.x;
	j = map->player.y;
	if (map->map[i][j - 1] == '0')
	{
		map->map[i][j - 1] = map->map[i][j];
		map->map[i][j] = '0';
		map->player.y--;
	}
}

void	player_right(t_map *map)
{
	int	i;
	int	j;

	i = map->player.x;
	j = map->player.y;
	if (map->map[i][j + 1] == '0')
	{
		map->map[i][j + 1] = map->map[i][j];
		map->map[i][j] = '0';
		map->player.y++;
	}
}

void	player_up(t_map *map)
{
	int	i;
	int	j;

	i = map->player.x;
	j = map->player.y;
	if (map->map[i - 1][j] == '0')
	{
		map->map[i - 1][j] = map->map[i][j];
		map->map[i][j] = '0';
		map->player.x--;
	}
}

void	player_down(t_map *map)
{
	int	i;
	int	j;

	i = map->player.x;
	j = map->player.y;
	if (map->map[i + 1][j] == '0')
	{
		map->map[i + 1][j] = map->map[i][j];
		map->map[i][j] = '0';
		map->player.x++;
	}
}

int	exec_key(int key, t_map *map)
{
	if (key == 53)
		exit(0);
	if (key == 13)
		player_up(map);
	if (key == 1)
		player_down(map);
	if (key == 0)
		player_left(map);
	if (key == 2)
		player_right(map);
	mlx_clear_window(map->win.mlx, map->win.mlx_win);
	ft_draw_map(&map);
	return (0);
}
