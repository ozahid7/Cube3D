/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:52:24 by ozahid-           #+#    #+#             */
/*   Updated: 2023/02/22 23:52:26 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
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

typedef struct s_color
{
	int	f;
	int	c;
}	t_color;

typedef struct s_dir
{
	char	*so;
	char	*no;
	char	*we;
	char	*ea;
	int		n;
	int		s;
	int		w;
	int		e;
	int		ci;
	int		fi;
	char	*c;
	char	*f;
	t_color color;
}	t_dir;


typedef struct s_map
{
	char		**map;
	t_dir		dir;
	t_color		color;
	int			size_tab;
	int			max_len;
	char		direction;
	t_win		win;
	t_player	player;
}	t_map;


//tmpfunctions
void		print2d(char **str);
int			len2d(char **str);
//Parcing
t_map		*remplir_map(t_map *map);
int			check_extention(char *mapfile);
char		**clone_data(int ac, char *av);
char		**split_file(t_map *map, char **file);
char		**ft_realoc(char **str, int len, char *allocate);
t_map		*ft_lstnew(t_map *map);
char		**get_file(char **str, char *allocate);
int			parse_paco(t_map *map, char **paco);
void		get_rgb(t_map *map, char **paco);
int			parse_color(t_map *map);
int			get_max_len(char **str);
int			ft_size(char **tab);
int			check_map(t_map *map);
int			parse_map(t_map *map);
//CloningMap
//char	**ft_realloc(char **map, int len, char *alocate);

t_player	init_player(void);

//render minimap
void		render_map(t_map *map);
void		ft_draw_map(t_map **head_map);

//move_player
int			exec_key(int key, t_map *map);

//CloningMap
//char	**ft_realloc(char **map, int len, char *alocate);
#endif