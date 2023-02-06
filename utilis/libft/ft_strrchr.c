/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:21:16 by ozahid-           #+#    #+#             */
/*   Updated: 2023/02/06 22:21:41 by ozahid-          ###   ########.fr       */
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