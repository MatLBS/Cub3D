/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:27:01 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/18 14:59:17 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	generate_cloud(int x, int y, t_img *img, t_data *data)
{
	int cloud_color;

	// Zone définie pour les nuages
	if (y >= 200 && y <= 500 && x >= 200 && x <= 300)
	{
		cloud_color = 120 + rand() % 100;
		cloud_color = (cloud_color << 16) | (cloud_color << 8) | cloud_color;
		my_mlx_pixel_put(img, y, x, cloud_color);
	}
	else
		my_mlx_pixel_put(img, y, x, data->map->c);
}

void	generate_background(t_img *img, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->height)
	{
		y = 0;
		while (y < data->width)
		{
			if (x < data->height / 2)
				generate_cloud(x, y, img, data);
			else
				my_mlx_pixel_put(img, y, x, data->map->f);
			y++;
		}
		x++;
	}
}

void	create_img(t_img *img, t_data *data, char *pathfile)
{
	if (!pathfile)
		img->img = mlx_new_image(data->mlx, data->width, data->height);
	else
		img->img = mlx_xpm_file_to_image(data->mlx, pathfile, \
			&img->width, &img->height);
	if (!img->img)
	{
		printf("Error while loading an image.\n");
		ft_free_data(data);
		c_handler(data);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	if (!img->addr)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_free_data(data);
		exit(EXIT_FAILURE);
	}
}

void	create_imgs(t_data *data)
{
	create_img(&data->tab_img[BACKGROUND], data, NULL);
	create_img(&data->tab_img[NORTH], data, data->map->no);
	create_img(&data->tab_img[SOUTH], data, data->map->so);
	create_img(&data->tab_img[EAST], data, data->map->ea);
	create_img(&data->tab_img[WEST], data, data->map->we);
	generate_background(&data->tab_img[BACKGROUND], data);
}
