/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_paco.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:02:31 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 11:02:32 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

char	**get_paco(char **file, int len)
{
	int		i;
	char	**paco;

	i = 0;
	paco = NULL;
	paco = malloc(sizeof(char *) * len + 1);
	if (!paco)
		return (NULL);
	while (file[i] && i < len)
	{
		paco[i] = file[i];
		i++;
	}
	paco[i] = 0;
	return (paco);
}

void	get_map(t_map *map, char **file, int len, int j)
{
	int	i;

	i = 0;
	map->map = malloc(sizeof(char *) * len + 1);
	if (!map->map)
		return ;
	while (file[j])
	{
		map->map[i] = file[j];
		if (ft_strlen(map->map[i]) == 0)
		{
			print(2, "Invalid Map\n");
			exit (0);
		}
		i++;
		j++;
	}
	map->map[i] = 0;
}

int	where_ismap(char *line)
{
	int		i;
	size_t	j;
	int		one;
	int		zero;

	i = 0;
	j = 0;
	one = 0;
	zero = 0;
	while (line[i])
	{
		if (line[i] == '1')
			one = 1;
		if (line[i] == '0')
			zero = 1;
		if (line[i] == ' ' || line[i] == '1' || line[i] == '0')
		{
			j++;
		}
		i++;
	}
	if ((zero != 0 || one != 0) && j == ft_strlen (line))
		return (1);
	return (0);
}

char	**split_file(t_map *map, char **file)
{
	int		i;
	int		len;
	char	**paco;

	i = 0;
	len = 0;
	while (file[i])
	{
		if (where_ismap(file[i]))
			break ;
		i++;
	}
	len = i;
	paco = get_paco(file, len);
	while (file[i])
		i++;
	get_map(map, file, i, len);
	return (paco);
}
