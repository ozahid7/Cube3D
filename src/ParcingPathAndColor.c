#include "../inc/cube.h"

int	check_extention(char *av1)
{
	int		i;
	char	*ext;

	i = 0;
	if (av1 == 0)
		return (0);
	ext = ft_strrchr(av1, '.');
	if (ft_strncmp(ext, ".cube", 6))
		return (1)
	return (0);
}

char	**get_data(int fd)
{
	char	**data;
	int		i;
	int		j;

	i = 0;

}