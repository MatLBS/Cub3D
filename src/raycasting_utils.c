/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:30:47 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/16 17:56:50 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	which_fov(t_data *data)
{
	if (data->map->pos_player == 'N' || data->map->pos_player == 'S')
	{
		data->player->planeX = 0.66;
		data->player->planeY = 0;
	}
	else
	{
		data->player->planeX = 0;
		data->player->planeY = 0.66;
	}
}

void	which_position(t_data *data)
{
	if (data->map->pos_player == 'N')
	{
		data->player->dirX = 0;
		data->player->dirY = -1;
	}
	else if (data->map->pos_player == 'S')
	{
		data->player->dirX = 0;
		data->player->dirY = 1;
	}
	else if (data->map->pos_player == 'E')
	{
		data->player->dirX = 1;
		data->player->dirY = 0;
	}
	else
	{
		data->player->dirX = -1;
		data->player->dirY = 0;
	}
	which_fov(data);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put_data(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_img *img, int pixelX, int pixelY, t_data *data)
{
	if (pixelX < 0 || pixelX >= img->width || pixelY < 0 || pixelY >= img->height)
	{
		// printf("Pixel out of bounds\n");
		return (0);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	if (!img->addr)
	{
		ft_free_data(data);
		c_handler(data);
	}
	return (*(unsigned long *)((img->addr + (pixelY * img->line_length) + (pixelX * img->bits_per_pixel / 8))));
}

void	get_texture_color(t_data *data, int pixelX, int pixelY)
{
	if (data->wall->side == 0)
	{
		if (data->player->rayDirX > 0)
		{
			// printf("east\n");
			data->wall->color = get_pixel_color(&data->tab_img[EAST], pixelX, pixelY, data);
		}
		else
		{
			// printf("west\n");
			data->wall->color = get_pixel_color(&data->tab_img[WEST], pixelX, pixelY, data);
		}
	}
	else
	{
		if (data->player->rayDirY > 0)
		{
			// printf("south\n");
			data->wall->color = get_pixel_color(&data->tab_img[SOUTH], pixelX, pixelY, data);
		}
		else
		{
			// printf("north\n");
			data->wall->color = get_pixel_color(&data->tab_img[NORTH], pixelX, pixelY, data);
		}
	}
}
