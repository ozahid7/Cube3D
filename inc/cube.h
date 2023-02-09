#ifndef CUBE_H
# define CUBE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"

//struct_map
typedef struct s_map
{
	char	**tab;
	int		size_tab;
	int		max_len;
	char	pos;
}	t_map;

//tmpfunctions
void	print2d(char **str);
int		len2d(char **str);
//Parcing
int		check_extention(char *mapfile);
t_map	*remplir_map(t_map *map);
int		check_map(t_map *map);
int		parse_map(t_map *map);
t_map	*ft_lstnew(char **map, int len, int size);
char	**ft_realoc(char **str, int len, char *allocate);
char	**get_map(char **str, char *allocate);

//CloningMap
//char	**ft_realloc(char **map, int len, char *alocate);
#endif
