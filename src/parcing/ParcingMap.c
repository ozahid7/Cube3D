#include"cube.h"

int	is_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
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
			&& map->map[i][j] != ' ' && !is_char(map->map[i][j]))
				return (0);
			if (is_char(map->map[i][j]))
			{
				if (map->pos != '\0')
					return (0);
				map->pos = map->map[i][j];
				map->p.x = i;
				map->p.y = j;
			}
			j++;
		}
		i++;
	}
	if (map->pos == '\0')
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
