/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:07:12 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/16 17:41:18 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	algo_dda_suite(t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->player->sideDistX < data->player->sideDistY)
		{
			data->player->sideDistX += data->player->deltaDistX;
			data->player->mapX += data->player->stepX;
			data->wall->side = 0;
		}
		else
		{
			data->player->sideDistY += data->player->deltaDistY;
			data->player->mapY += data->player->stepY;
			data->wall->side = 1;
		}
		if (data->map->map[data->player->mapY][data->player->mapX] == '1')
			hit = 1;
	}
	if (data->wall->side == 0)
		data->wall->perpWallDist = (data->player->sideDistX - data->player->deltaDistX);
	else
		data->wall->perpWallDist = (data->player->sideDistY - data->player->deltaDistY);
}

void	algo_dda(t_data *data)
{
	data->player->mapX = (int)data->player->posX;
	data->player->mapY = (int)data->player->posY;
	data->player->deltaDistX = fabs(1 / data->player->rayDirX);
	data->player->deltaDistY = fabs(1 / data->player->rayDirY);
	if (data->player->rayDirX < 0)
	{
		data->player->stepX = -1;
		data->player->sideDistX = (data->player->posX - data->player->mapX) * data->player->deltaDistX;
	}
	else
	{
		data->player->stepX = 1;
		data->player->sideDistX = (data->player->mapX + 1.0 - data->player->posX) * data->player->deltaDistX;
	}
	if (data->player->rayDirY < 0)
	{
		data->player->stepY = -1;
		data->player->sideDistY = (data->player->posY - data->player->mapY) * data->player->deltaDistY;
	}
	else
	{
		data->player->stepY = 1;
		data->player->sideDistY = (data->player->mapY + 1.0 - data->player->posY) * data->player->deltaDistY;
	}
	algo_dda_suite(data);
}

void	display_wall(t_data *data, int x)
{
	data->wall->lineHeight = (int)(data->height / data->wall->perpWallDist);
	data->wall->drawStart = ((data->wall->lineHeight * -1) / 2) + (data->height / 2);
	if (data->wall->drawStart < 0)
		data->wall->drawStart = 0;
	data->wall->drawEnd = (data->wall->lineHeight / 2) + (data->height / 2);
	if (data->wall->drawEnd >= data->height)
		data->wall->drawEnd = data->height - 1;
	while (data->wall->drawStart < data->wall->drawEnd)
	{
		get_texture_color(data, x, data->wall->drawStart);
		// printf("%ld\n", data->wall->color);
		// printf("bonjour\n");
		my_mlx_pixel_put_data(data, x, data->wall->drawStart, data->wall->color);
		data->wall->drawStart++;
	}
}

void	launch_rays(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->width)
	{
		data->player->cameraX = ((2 * x) / (double)(data->width)) - 1;
		data->player->rayDirX = data->player->dirX + (data->player->planeX * data->player->cameraX);
		data->player->rayDirY = data->player->dirY + (data->player->planeY * data->player->cameraX);
		algo_dda(data);
		display_wall(data, x);
		x++;
	}
}

void	raycasting(t_data *data)
{
	ft_memcpy(data->addr, data->tab_img[BACKGROUND].addr, \
		data->width * data->height * (data->bits_per_pixel / 8));
	which_position(data);
	launch_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
