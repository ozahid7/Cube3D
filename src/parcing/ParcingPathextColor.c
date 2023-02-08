#include "../../inc/cube.h"

int	check_extention(char *av1)
{
	int		i;
	char	*ext;

	i = 0;
	if (av1 == 0)
		return (0);
	ext = ft_strrchr(av1, '.');
	if (ft_strncmp(ext, ".cub", 5) == 1)
		return (1);
	return (0);
}

int	print2d(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
	{
		print(1, "%s", str[i]);
		i++;
	}
	return (i);
}

int	open_file(int fd, char *av)
{
	int		len;
	char	*path;

	len = 0;
	path = ft_strjoin(ft_strdup("maps/"), av);
	fd = open(path, O_RDWR);
	free(path);
	if (fd == -1)
		return (1);
	close(fd);
	return(0);
}