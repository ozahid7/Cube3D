/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:46:44 by ajafy             #+#    #+#             */
/*   Updated: 2023/02/06 23:43:40 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

void	free2d(char **str);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strdup(const char *s);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlen(const char *str);





#endif
