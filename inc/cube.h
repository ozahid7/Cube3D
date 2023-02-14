/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:52:24 by ozahid-           #+#    #+#             */
/*   Updated: 2023/02/14 01:33:08 by ozahid-          ###   ########.fr       */
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

typedef struct s_dir
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_dir;

typedef struct s_map
{
	char	**map;
	t_dir	*dir;
	int		f;
	int		c;
}	t_map;


//tmpfunctions
void	print2d(char **str);
int		len2d(char **str);
//Parcing
int		check_extention(char *mapfile);
char	**clone_data(int ac, char *av);
char	**split_file(t_map *map, char **file);
char	**ft_realoc(char **str, int len, char *allocate);
char	**get_file(char **str, char *allocate);
int		parse_paco(char **paco);


//CloningMap
//char	**ft_realloc(char **map, int len, char *alocate);
#endif