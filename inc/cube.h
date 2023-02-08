/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:52:24 by ozahid-           #+#    #+#             */
/*   Updated: 2023/02/08 05:27:57 by ozahid-          ###   ########.fr       */
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
}	t_map;


//Parcing
int		check_extention(char *mapfile);

//CloningMap
char	**ft_realloc(char **map, int len, char *alocate);
char	**get_map(char **map, char *line);
#endif