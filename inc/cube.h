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

# define SIZE 16
# define PI (3.141592653589793)

//struct_windows
typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
}	t_win;

//struct_player
typedef struct s_player
{
	int		x;
	int		y;
	int		rotation_direction;
	int		deplacement_direction;
	double	rotation_angle;
	double	move_speed;
	double	rotation_speed;
}	t_player;

//struct_map
typedef struct s_map
{
	char		**map;
	int			size_tab;
	int			max_len;
	char		pos;
	t_win		t;
	t_player	p;
}	t_map;


//tmpfunctions
void		print2d(char **str);
int			len2d(char **str);
//Parcing
int			check_extention(char *mapfile);
t_map		*remplir_map(t_map *map);
int			check_map(t_map *map);
int			parse_map(t_map *map);
t_map		*ft_lstnew(char **map, int len, int size);
char		**ft_realoc(char **str, int len, char *allocate);
char		**get_map(char **str, char *allocate);
int			get_max_len(char **str);
int			ft_size(char **tab);

//CloningMap
//char	**ft_realloc(char **map, int len, char *alocate);

t_player	init_player(void);

//render minimap
void		render_map(t_map *map);
void		ft_draw_map(t_map **head_map);

//move_player
int			exec_key(int key, t_map *map);
#endif
