#include"cube.h"

int	ft_size(void)
{
	char	*s;
	int		x;
	int		fd;

	fd = open("maps/map.cub", O_RDONLY);
	s = get_next_line(fd);
	x = 0;
	while (s)
	{
		x++;
		free(s);
		s = get_next_line(fd);
	}
	free(s);
	close (fd);
	return (x);
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

char	**allocate_map(char **str, int len, int size)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	tab = malloc((size + 1) * sizeof(char *));
	if (!tab || !str)
		return (NULL);
	while (str[i])
	{
		tab[i] = malloc((len + 1));
		if (!tab[i])
			return (free2d(tab), NULL);
		j = 0;
		while (str[i][j] && str[i][j] != '\n' && j < len)
		{
			tab[i][j] = str[i][j];
			j++;
		}
		while (j < len)
			tab[i][j++] = ' ';
		tab[i][j] = '\0';
		i++;
	}
	return (free2d(str), tab);
}

t_map	*remplir_map(t_map *map)
{
	int		fd;
	int		size;
	int		i;
	char	**str;
	char	**s;

	fd = open("maps/map.cub", O_RDONLY);
	size = ft_size();
	str = malloc((size + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	str[i] = get_next_line(fd);
	while (str[i])
		str[++i] = get_next_line(fd);
	str[i] = NULL;
	close(fd);
	i = get_max_len(str);
	s = allocate_map(str, i, size);
	map = ft_lstnew(s, i, size);
	return (map);
}
