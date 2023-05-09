/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prov.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:50:48 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 10:32:40 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

int	ft_size(char **tab)
{
	int	size;

	size = 0;
	if (!tab)
		return (0);
	while (tab[size])
		size++;
	return (size);
}

int	get_max_len(char **str)
{
	int		i;
	size_t	max_len;

	i = 0;
	max_len = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (max_len < ft_strlen(str[i]))
			max_len = ft_strlen(str[i]);
		i++;
	}
	return ((int) max_len);
}

char	**allocate_map(t_map *map)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	tab = malloc((map->size_tab + 1) * sizeof(char *));
	if (!tab || !map->map)
		return (NULL);
	while (map->map[i])
	{
		tab[i] = malloc((map->max_len + 1));
		if (!tab[i])
			return (free2d(tab), NULL);
		j = 0;
		while (map->map[i][j] && map->map[i][j] != '\n' && j < map->max_len)
		{
			tab[i][j] = map->map[i][j];
			j++;
		}
		while (j < map->max_len)
			tab[i][j++] = ' ';
		tab[i++][j] = '\0';
	}
	tab[i] = 0;
	return (free2d(map->map), tab);
}

t_map	*remplir_map(t_map *map)
{
	map->map = allocate_map(map);
	return (map);
}
