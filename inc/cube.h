/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:52:24 by ozahid-           #+#    #+#             */
/*   Updated: 2023/02/12 20:10:40 by ozahid-          ###   ########.fr       */
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

typedef struct s_map
{
	char	**map;
	char	**paco;
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


//CloningMap
//char	**ft_realloc(char **map, int len, char *alocate);
#endif