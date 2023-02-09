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
	int	k;

	i = 0;
	k = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] != '1' || map->tab[i][j] != '0' \
			|| map->tab[i][j] != ' ' || k > 1 || !is_char(map->tab[i][j]))
				return (0);
			if (is_char(map->tab[i][j]))
			{
				map->pos = map->tab[i][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_bords(t_map *map)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	if (!map)
		return (0);
	i = 0;
	len = map->size_tab - 2;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] != '1' && map->tab[i][j] != ' ')
				return (0);
			j++;
		}
		i = len;
		i++;
		len++;
	}
	return (1);
}

int	parse_map(t_map *map)
{
	if (!check_bords(map))
		return (print(2, "Erreur, map ouverte 0!"), 0);
	if (!check_map(map))
		return (print(2, "Erreur, map ouverte 1!"), 0);
	print(1, "he\n");
	if (!valid_chars(map))
		return (print(2, "Erreur, invalide map !"), 0);
	return (1);
}
