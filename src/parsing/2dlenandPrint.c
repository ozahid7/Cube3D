/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2dlenandPrint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:02:22 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 11:02:24 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	print2d(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		print(1, "%s\n", str[i]);
		i++;
	}
}

int	len2d(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
