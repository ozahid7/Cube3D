/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:39:28 by ajafy             #+#    #+#             */
/*   Updated: 2023/02/06 19:01:42 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"


char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == 0)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char) c)
		{
			return ((char *) s + i);
		}
		i++;
	}
	if (c == '\0')
		return ((char *) s + i);
	return (NULL);
}
