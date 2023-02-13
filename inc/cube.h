/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:52:24 by ozahid-           #+#    #+#             */
/*   Updated: 2023/02/13 17:04:04 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <mlx.h>
#include <fcntl.h>
#include <math.h>
#include "ft_printf.h"
#include "libft.h"
#include "get_next_line.h"

typedef struct s_color
{
	int	f;
	int	c;
}	t_color;

typedef struct s_map
{
	char	**map;
	char	**paco;
	t_color *color;
}	t_map;


//tmpfunctions
void	print2d(char **str);
int		len2d(char **str);
//Parcing
int		check_extention(char *mapfile);
char	**clone_data(int ac, char *av);
void	split_file(t_map *map, char **file);
char	**ft_realoc(char **str, int len, char *allocate);
char	**get_file(char **str, char *allocate);
int	parse_paco(char **paco);


//CloningMap
//char	**ft_realloc(char **map, int len, char *alocate);
#endif