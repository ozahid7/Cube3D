#include "../../inc/cube.h"

t_map	*ft_lstnew(t_map *map)
{
	t_map	*newlst;

	newlst = (t_map *) malloc(sizeof(t_map));
	if (!newlst)
		return (NULL);
	newlst->map = map->map;
	newlst->max_len = get_max_len(map->map);
	newlst->size_tab = ft_size(map->map);
	newlst->win.mlx = NULL;
	newlst->dir = map->dir;
	newlst->color = map->color;
	newlst->win.mlx_win = NULL;
	newlst->direction = '\0';
	newlst->win.win_height = 200;
	newlst->win.win_width = 360;
	newlst->rays.wall_width = 1;
	newlst->rays.num_rays = newlst->win.win_width / newlst->rays.wall_width;
	newlst->rays.ray_angle = map->player.rotation_angle - (map->player.vue_angle / 2);

	return (newlst);
}

t_player	init_player()
{
	t_player	newlst;

	newlst.x = 0;
	newlst.y = 0;
	newlst.x_screen = 0;
	newlst.y_screen = 0;
	newlst.rotation_direction = 0;
	newlst.deplacement_direction = 0;
	newlst.move_speed = 10.0;
	newlst.rotation_angle = PI / 2;
	newlst.rotation_speed = 10 * (PI / 180);
	newlst.vue_angle = 60 * (PI / 180);
	return (newlst);
}