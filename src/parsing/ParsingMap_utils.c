/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParsingMap_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:17:38 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 10:32:20 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

int	go_left(char *str, int i)
{
	while (i > 0 && str[i] != '1' && str[i] != ' ')
		i--;
	if (str[i] == '1')
		return (1);
	return (0);
}

int	go_right(char *str, int i)
{
	while (str[i] && str[i] != '1' && str[i] != ' ')
		i++;
	if (str[i] == '1')
		return (1);
	return (0);
}

int	go_up(char **str, int i, int j)
{
	while (str[i][j] && str[i][j] != '1' && str[i][j] != ' ')
		i--;
	if (str[i][j] == '1')
		return (1);
	return (0);
}

int	go_down(char **str, int i, int j)
{
	while (str[i][j] && str[i][j] != '1' && str[i][j] != ' ')
		i++;
	if (str[i][j] == '1')
		return (1);
	return (0);
}

int	check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '0' || map->map[i][j] == map->direction)
			{
				if (!go_right(map->map[i], j) || !go_left(map->map[i], j))
					return (0);
				if (!go_down(map->map, i, j) || !go_up(map->map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
