/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:06:09 by ozahid-           #+#    #+#             */
/*   Updated: 2023/02/06 22:56:23 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlcat(char *dst, char *src);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);

#endif
