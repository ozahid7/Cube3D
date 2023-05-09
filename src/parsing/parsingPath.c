/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingPath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:02:45 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/06 16:32:03 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	putnew(char **paco)
{
	int	i;

	i = 0;
	while (paco[i])
	{
		if (paco[i][0] == '\0')
			paco[i][0] = '\n';
		i++;
	}
}

void	init_dir(t_map *map, char **paco)
{
	if (!strcmp(paco[0], "NO"))
	{
		map->dir.n++;
		map->dir.no = ft_strdup(paco[1]);
	}
	else if (!strcmp(paco[0], "WE"))
	{
		map->dir.w++;
		map->dir.we = ft_strdup(paco[1]);
	}
	else if (!strcmp(paco[0], "EA"))
	{
		map->dir.e++;
		map->dir.ea = ft_strdup(paco[1]);
	}
	else if (!strcmp(paco[0], "SO"))
	{
		map->dir.s++;
		map->dir.so = ft_strdup(paco[1]);
	}
	else
		get_rgb(map, paco);
}

int	parse_path_utils(t_map *map, char **paco)
{
	int	fd;

	if (!paco || len2d(paco) != 2)
		return (1);
	init_dir(map, paco);
	if (paco[0][0] != '\n' && (!ft_strcmp(paco[0], "NO")
		|| !ft_strcmp(paco[0], "SO") || !ft_strcmp(paco[0], "EA")
	|| !ft_strcmp(paco[0], "WE")))
	{
		fd = open(paco[1], O_RDWR);
		if (fd == -1)
			return (1);
		close(fd);
	}
	return (0);
}

int	parse_path(t_map *map, char **ptr)
{
	int		i;
	int		j;
	char	**paco;

	i = 0;
	j = 0;
	putnew(ptr);
	while (ptr[i])
	{
		if (ptr[i][0] == '\n')
		{
			i++;
			continue ;
		}
		paco = ft_split(ptr[i], ' ');
		if (parse_path_utils(map, paco))
			return (1);
		i++;
		free2d(paco);
	}
	if (map->dir.e != 1 || map->dir.n != 1
		|| map->dir.s != 1 || map->dir.w != 1
		|| map->dir.ci != 1 || map->dir.fi != 1)
		return (1);
	return (0);
}

int	parse_paco(t_map *map, char **paco)
{
	map->dir.n = 0;
	map->dir.ci = 0;
	map->dir.fi = 0;
	map->dir.w = 0;
	map->dir.e = 0;
	map->dir.s = 0;
	if (parse_path(map, paco))
		return (print(1, "Path In Map Error\n"), 1);
	if (parse_color(map))
		return (print(1, "Color In Map Error\n"), 1);
	return (0);
}
