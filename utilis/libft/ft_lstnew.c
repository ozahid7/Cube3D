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
	newlst->pos = '\0';
	return (newlst);
}
