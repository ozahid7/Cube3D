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
	newlst->t.mlx = NULL;
	newlst->dir = map->dir;
	newlst->color = map->color;
	newlst->t.mlx_win = NULL;
	newlst->pos = '\0';
	return (newlst);
}

t_player	init_player(void)
{
	t_player	newlst;

	newlst.x = 0;
	newlst.y = 0;
	newlst.rotation_direction = 0;
	newlst.deplacement_direction = 0;
	newlst.move_speed = 0.0;
	newlst.rotation_angle = PI / 2;
	newlst.rotation_speed = 0.0;
	newlst.rotation_angle = 0.0;
	return (newlst);
}