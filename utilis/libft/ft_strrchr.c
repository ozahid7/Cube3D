/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:54:11 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 09:54:12 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (str[i])
	{
		i++;
	}
	while (i != 0)
	{
		if (str[i] == (char)c)
			return (&str[i]);
			i--;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}
