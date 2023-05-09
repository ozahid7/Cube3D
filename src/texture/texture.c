/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:04:05 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/09 05:28:41 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

void	scaleimg(t_img *img, int x, int y)
{
	int	a;
	int	outputy;
	int	outputx;
	int	index;

	y = 0;
	a = 0;
	img->color = malloc(sizeof(unsigned int) * ((SIZE * SIZE) + 1));
	if (!img->color)
		return ;
	while (y < SIZE)
	{
		x = -1;
		outputy = ((float)img->height / SIZE) * y;
		while (++x < SIZE)
		{
			outputx = ((float)img->width / SIZE) * x;
			index = outputy * img->width + outputx;
			img->color[a++] = img->adr[index];
		}
		y++;
	}
	img->height = SIZE;
	img->width = SIZE;
}

int	get_tcolor(t_img *img, int wh, int dif)
{
	int	tcolor;

	tcolor = 0;
	img->tofy = dif * ((float)img->height / wh);
	tcolor = img->color[(img->width * img->tofy) + img->tofx];
	return (tcolor);
}

int	get_color(t_map *data, int txt, int disftop, int wh)
{
	if (txt == 1)
		return (get_tcolor(&data->no, wh, disftop));
	else if (txt == 2)
		return (get_tcolor(&data->so, wh, disftop));
	else if (txt == 3)
		return (get_tcolor(&data->ea, wh, disftop));
	else
		return (get_tcolor(&data->we, wh, disftop));
}

void	open_read_texture(t_img *img, void *mlx, char *dir)
{
	img->img = mlx_xpm_file_to_image(mlx, dir, &img->width, &img->height);
	if (!img->img)
	{
		print(2, "mlx_xpm_file_to_img FAILED\n");
		exit (0);
	}
	img->adr = (unsigned *)mlx_get_data_addr(img->img, &img->bitppixel, \
	&img->size_len, &img->endian);
	if (!img->adr)
	{
		print(2, "mlx_get_data_addr FAILED \n");
		exit (0);
	}
	scaleimg(img, 0, 0);
}

void	load_texture(t_map *data)
{
	open_read_texture(&data->no, data->win.mlx, data->dir.no);
	open_read_texture(&data->so, data->win.mlx, data->dir.so);
	open_read_texture(&data->ea, data->win.mlx, data->dir.we);
	open_read_texture(&data->we, data->win.mlx, data->dir.ea);
}
