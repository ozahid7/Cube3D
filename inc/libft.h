# ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "get_next_line.h"

void	free2d(char **str);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strdup(const char *s);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strrchr(const char *s, int c);

#endif
