/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:53:37 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 09:53:38 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	free2d(char **str)
{
	int	i;

	i = 0;
	if (str == 0)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	freenode(t_map *map)
{
	t_ray_info	*next;

	while ((map->info_ray))
	{
		next = map->info_ray->next;
		free(map->info_ray);
		map->info_ray = next;
	}
	map->info_ray = NULL;
}
