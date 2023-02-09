/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:52:24 by ozahid-           #+#    #+#             */
/*   Updated: 2023/02/09 16:03:25 by ajafy            ###   ########.fr       */
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

//struct_map
typedef struct s_map
{
	char	**tab;
	int		size_tab;
	int		max_len;
	char	pos;
}	t_map;

//Parcing
char	**get_data(int fd);
int		check_extention(char *mapfile);
t_map	*remplir_map(t_map *map);
int		check_map(t_map *map);
int		parse_map(t_map *map);
t_map	*ft_lstnew(char **map, int len, int size);

#endif