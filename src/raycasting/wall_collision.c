/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:51:28 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/06 16:05:17 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

int	check_corner(t_map *map, int i, int j)
{
	int	ip;
	int	jp;

	jp = (int)floor(map->player.x_screen / SIZE);
	ip = (int)floor(map->player.y_screen / SIZE);
	if (map->map[i][jp] == '1' && map->map[ip][j] == '1')
		return (1);
	return (0);
}

int	check_wall(double x, double y, t_map *map, int mode)
{
	int	i;
	int	j;
	int	len;

	j = (int)floor(x / SIZE);
	i = (int)floor(y / SIZE);
	if (i < 0 || i > map->size_tab)
		return (1);
	if (map->map[i])
		len = ft_strlen(map->map[i]);
	else
		return (1);
	if (j < 0 || j > len)
		return (1);
	if (map->map[i][j] == '1' || map->map[i][j] == ' ' || map->map[i][j] == 0)
		return (1);
	if (mode)
		return (check_corner(map, i, j));
	return (0);
}

int	inside_map(t_map *map, double x, double y)
{
	int	i;
	int	j;
	int	len;

	j = (int)floor(x / SIZE);
	i = (int)floor(y / SIZE);
	if (i >= 0 || i < map->size_tab)
		return (1);
	if (map->map[i])
		len = ft_strlen(map->map[i]);
	else
		return (1);
	if (j >= 0 || j < len)
		return (1);
	return (0);
}
