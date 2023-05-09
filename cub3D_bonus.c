/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:55:56 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/05 10:30:23 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cube.h"

int	main(int ac, char **av)
{
	t_map	mapp;
	t_map	*map;
	char	**file;
	char	**paco;

	file = clone_data(ac, av[1]);
	if (!file)
		return (1);
	paco = split_file(&mapp, file);
	if (paco && paco[1])
		if (parse_paco(&mapp, paco))
			exit(0);
	map = ft_lstnew(&mapp, 'b');
	map = remplir_map(map);
	map->player = init_player();
	if (!parse_map(map))
		exit(1);
	render_map(map);
}
