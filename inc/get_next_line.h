

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		check(char *tab);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
int		check(char *tab);
char	*ft_strdupg(char *s);

#endif
