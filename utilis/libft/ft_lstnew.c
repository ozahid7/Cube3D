#include"cube.h"

t_map	*ft_lstnew(char **map, int len, int size)
{
	t_map	*newlst;

	newlst = (t_map *) malloc(sizeof(t_map));
	if (!newlst)
		return (NULL);
	newlst->map = map;
	newlst->max_len = len;
	newlst->size_tab = size;
	newlst->t.mlx = NULL;
	newlst->t.mlx_win = NULL;
	newlst->pos = '\0';
	return (newlst);
}

t_player	init_player(void)
{
	t_player	newlst;

	// newlst = (t_player *) malloc(sizeof(t_player));
	// if (!newlst)
	// 	return (NULL);
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