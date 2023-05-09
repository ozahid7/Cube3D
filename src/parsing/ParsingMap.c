/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParsingMap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:17:16 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 10:32:27 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

int	is_char(char c, t_map *map, int i)
{
	if (!i)
	{
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			return (1);
	}
	if ((c == 'N' || c == 'S' || c == 'E' || c == 'W') && i)
	{
		if (c == 'N')
			map->player.rotation_angle = M_PI_2;
		if (c == 'S')
			map->player.rotation_angle = M_PI * 3 / 2;
		if (c == 'E')
			map->player.rotation_angle = 0;
		if (c == 'W')
			map->player.rotation_angle = M_PI;
		return (1);
	}
	return (0);
}

void	player_position(t_map *map, int i, int j)
{
	map->direction = map->map[i][j];
	map->player.x = j;
	map->player.y = i;
	map->player.x_screen = j * SIZE;
	map->player.y_screen = i * SIZE;
}

int	valid_chars(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0' \
			&& map->map[i][j] != ' ' && !is_char(map->map[i][j], map, 0))
				return (0);
			if (is_char(map->map[i][j], map, 1))
			{
				if (map->direction != '\0')
					return (0);
				player_position(map, i, j);
			}
			j++;
		}
		i++;
	}
	if (map->direction == '\0')
		return (0);
	return (1);
}

int	check_bords(t_map *map)
{
	int	j;
	int	len;

	len = map->size_tab - 1;
	if (!map->map)
		return (0);
	j = 0;
	while (map->map[0][j])
	{
		if (map->map[0][j] != '1' && map->map[0][j] != ' ')
			return (0);
		j++;
	}
	j = 0;
	while (map->map[len][j])
	{
		if (map->map[len][j] != '1' && map->map[len][j] != ' ')
			return (0);
		j++;
	}
	return (1);
}

int	parse_map(t_map *map)
{
	if (!valid_chars(map))
		return (print(2, "Erreur, invalide map !"), 0);
	if (!check_bords(map) || !check_map(map))
		return (print(2, "Erreur, map ouverte !"), 0);
	return (1);
}
