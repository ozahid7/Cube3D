#include"cube.h"

int	go_right(char *str, int i)
{
	while (i > 0 && str[i] != '1' && str[i] != ' ')
		i--;
	if (str[i] == '1')
		return (1);
	return (0);
}

int	go_left(char *str, int i)
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
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] == '0')
			{
		print(1, "hello there     (%s)\n", map->tab[i]);
				if (!go_right(map->tab[i], j) || !go_left(map->tab[i], j))
					return (0);
				if (!go_down(map->tab, i, j) || !go_up(map->tab, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
