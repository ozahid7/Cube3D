# include"cube.h"

int	check_wall(int x, int y, t_map *map)
{
	int	i;
	int	j;

	j = y / SIZE;
	i = x / SIZE;
	if (map->map[i][j] == '1')
		return (1);
	return (0);
}

void	player_left(t_map *map)
{
	double	move_speed;
	int		x;
	int		y;

	map->player.deplacement_direction = 1;
	move_speed = map->player.deplacement_direction * map->player.move_speed;
	y = (int) (map->player.y_screen + cos(map->player.rotation_angle + (PI * 3) / 2) * move_speed);
	x = (int) (map->player.x_screen + sin(map->player.rotation_angle + (PI * 3) / 2) * move_speed);
	if (!check_wall(x, y, map))
	{
		map->player.y_screen = y;
		map->player.x_screen = x;
	}
}

void	player_right(t_map *map)
{
	double	move_speed;
	int		x;
	int		y;

	map->player.deplacement_direction = 1;
	move_speed = map->player.deplacement_direction * map->player.move_speed;
	y = (int) (map->player.y_screen + cos(map->player.rotation_angle + (PI / 2)) * move_speed);
	x = (int) (map->player.x_screen + sin(map->player.rotation_angle + (PI / 2)) * move_speed);
	if (!check_wall(x, y, map))
	{
		map->player.y_screen = y;
		map->player.x_screen = x;
	}
}

void	player_up(t_map *map)
{
	double	move_speed;
	int		x;
	int		y;

	map->player.deplacement_direction = 1;
	move_speed = map->player.deplacement_direction * map->player.move_speed;
	y = (int) (map->player.y_screen + cos(map->player.rotation_angle) * move_speed);
	x = (int) (map->player.x_screen + sin(map->player.rotation_angle) * move_speed);
	if (!check_wall(x, y, map))
	{
		map->player.y_screen = y;
		map->player.x_screen = x;
	}
}

void	player_down(t_map *map)
{
	double	move_speed;
	int		x;
	int		y;

	map->player.deplacement_direction = -1;
	move_speed = map->player.deplacement_direction * map->player.move_speed;
	y = (int) (map->player.y_screen + cos(map->player.rotation_angle) * move_speed);
	x = (int) (map->player.x_screen + sin(map->player.rotation_angle) * move_speed);
	if (!check_wall(x, y, map))
	{
		map->player.y_screen = y;
		map->player.x_screen = x;
	}
}

void	update_player(t_map *map)
{
	if (map->player.rotation_direction != 0)
		map->player.rotation_angle += map->player.rotation_direction * map->player.rotation_speed;
	map->player.rotation_direction = 0;
	map->player.deplacement_direction = 0;
	map->player.x = map->player.x_screen / SIZE;
	map->player.y = map->player.y_screen / SIZE;
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
	if (key == 123)
			map->player.rotation_direction = -1;
	if (key == 124)
			map->player.rotation_direction = 1;
	update_player(map);
	mlx_clear_window(map->win.mlx, map->win.mlx_win);
	ft_draw_map(&map);
	return (0);
}
