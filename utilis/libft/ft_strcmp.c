/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:53:55 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 09:53:56 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((unsigned char) s1[i] == (unsigned char) s2[i])
			i++;
		else if ((unsigned char) s1[i] > (unsigned char) s2[i])
			return (1);
		else
			return (-1);
	}
	return (0);
}
