/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:52:24 by ozahid-           #+#    #+#             */
/*   Updated: 2023/05/09 16:53:17 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"

# define WIDTH 1000
# define HEIGHT 1000
# define SIZE 64 
# define MF 0.06

//struct_texture
typedef struct s_img
{
	int				tofx;
	int				tofy;
	unsigned int	*color;
	unsigned int	*adr;
	int				height;
	int				width;
	int				endian;
	int				size_len;
	int				bitppixel;
	void			*img;
}	t_img;

//struct_walls
typedef struct s_walls
{
	double	pwh;
	double	dtp;
	int		dftop;
	double	rayd;
	int		dif;
	int		tpix;
	int		wheight;
}	t_walls;

//struct_img_data
typedef struct s_img_data {
	void	*image;
	int		bp;
	char	*adrs;
	int		line_len;
	int		endian;
}				t_img_data;

//struct_windows
typedef struct s_win
{
	void		*mlx;
	void		*mlx_win;
	int			win_width;
	int			win_height;
	t_img_data	img;
}	t_win;

//struct_point
typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

//struct_player
typedef struct s_player
{
	int		x;
	int		y;
	double	x_screen;
	double	y_screen;
	int		rotation_direction;
	int		deplacement_directionx;
	int		deplacement_directiony;
	double	rotation_angle;
	double	vue_angle;
	double	move_speed;
	double	rotation_speed;
}	t_player;

//struct_color
typedef struct s_color
{
	int	f;
	int	c;
}	t_color;

//struct_direction
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
	t_color	color;
}	t_dir;

//struct_calculate
typedef struct s_calc
{
	t_point	step;
	t_point	intercept;
	t_point	wall;
	t_point	next;
	int		is_wall_v;
	int		is_wall_h;
}	t_calc;

//struct_rays_information
typedef struct s_ray_info
{
	double				x_depart;
	double				y_depart;
	double				x_finish;
	double				y_finish;
	double				distance;
	struct s_ray_info	*next;
}	t_ray_info;

//struct_rays
typedef struct s_rays
{
	int		id_col;
	double	num_rays;
	double	wall_width;
	double	ray_angle;
	double	wall_hit_x;
	double	wall_hit_y;
	int		face_down;
	int		face_right;
	int		hit_vertical;
	double	distance;
	t_calc	calc;
}	t_rays;

//struct_map
typedef struct s_map
{
	char		**map;
	t_dir		dir;
	t_img		no;
	t_img		so;
	t_img		ea;
	t_img		we;
	t_color		color;
	int			size_tab;
	int			max_len;
	char		direction;
	t_win		win;
	t_rays		rays;
	t_ray_info	*info_ray;
	t_player	player;
	int			x;
	int			y;
	char		mode;
}	t_map;

//tmpfunctions
void		print2d(char **str);
int			len2d(char **str);

//lstnew
t_map		*ft_lstnew(t_map *map, char mode);
t_ray_info	*ft_lstnew_rays(t_map *map);

//initialisation
t_ray_info	*ft_lstmid(t_ray_info *lst);
void		ft_lstadd_back(t_ray_info **alst, t_ray_info *new);
t_player	init_player(void);

//Parcing
void		freenode(t_map *map);
t_map		*remplir_map(t_map *map);
int			check_extention(char *mapfile);
char		**clone_data(int ac, char *av);
char		**split_file(t_map *map, char **file);
char		**ft_realoc(char **str, int len, char *allocate);
char		**get_file(char **str, char *allocate);
int			parse_paco(t_map *map, char **paco);
void		get_rgb(t_map *map, char **paco);
int			parse_color(t_map *map);
int			get_max_len(char **str);
int			ft_size(char **tab);
int			check_map(t_map *map);
int			parse_map(t_map *map);

//keys
int			release_key(int key, t_map *map);
int			exec_key(int key, t_map *map);
int			ft_exit(t_map *map);

//calcule_distance
double		distance_between_points(double x_p, double y_p, double x, double y);
void		get_distance(t_map *map, int x);

//calcule_intersiction
void		get_vertical_step(t_map *map, t_calc *vertical);
t_point		intersiction_wall_vertical(t_map *map, t_calc *vertical);
void		get_horizontal_step(t_map *map, t_calc *horizontal);
t_point		intersiction_wall_horiz(t_map *map, t_calc *horizontal);

//draw_minimap
void		draw_minimap(t_map *map);
void		draw_player(t_map *map, int x, int y);
void		draw_line(t_map *map);
void		carre(t_win *t, int color, int y, int x);

//mouse.c
int			ft_mouse(int x, int y, t_map *map);

//mlx
void		my_mlx_pixel_put(t_img_data *img, int x, int y, int color);

//move_player
void		normalise_angle(t_map *map);
void		update_player(t_map *map);

//raycasting
void		draw_walls(t_map *data, int x, int h);
void		cast_rays(t_map *map);

//render_map
void		drawbackground(t_map *data);
int			ft_draw_map(t_map *map);
void		render_map(t_map *map);

//wall_collision
int			check_corner(t_map *map, int i, int j);
int			check_wall(double x, double y, t_map *map, int mode);
int			inside_map(t_map *map, double x, double y);

//texture
void		scaleimg(t_img *img, int x, int y);
int			get_tcolor(t_img *img, int wh, int dfp);
int			get_color(t_map *data, int txt, int disftop, int wh);
void		load_texture(t_map *data);

//draw_paint_wall
void		draw_walls(t_map *data, int x, int texture);

#endif