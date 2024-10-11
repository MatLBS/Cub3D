/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   games.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:07:12 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/11 18:45:24 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	which_position(t_data *data)
{
	if (data->map->pos_player = 'N')
	{
		data->player->dirX = -1;
		data->player->dirY = 0;
	}
	else if (data->map->pos_player = 'S')
	{
		data->player->dirX = 1;
		data->player->dirY = 0;
	}
	else if (data->map->pos_player = 'E')
	{
		data->player->dirX = 0;
		data->player->dirY = 1;
	}
	else
	{
		data->player->dirX = 0;
		data->player->dirY = -1;
	}
}

void	algo_dda(t_data *data)
{
	int	steps;
	int	hit;
	int	side;

	hit = 0;
	data->player->mapX = (int)data->player->posX;
	data->player->mapY = (int)data->player->posY;
	if (abs(data->player->mapX) > abs(data->player->mapY))
		steps = abs(data->player->mapX);
	else
		steps = abs(data->player->mapY);
	data->player->deltaDistX = abs(1 / data->player->rayDirX);
	data->player->deltaDistY = abs(1 / data->player->rayDirY);
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
	while (hit == 0)
	{
		if (data->player->sideDistX < data->player->sideDistY)
		{
			data->player->sideDistX += data->player->deltaDistX;
			data->player->mapX += data->player->stepX;
			side = 0;
		}
		else
		{
			data->player->sideDistY += data->player->deltaDistY;
			data->player->mapY += data->player->stepY;
			side = 1;
		}
		if (data->map->map[data->player->mapX][data->player->mapY] == 1)
			hit  = 1;
	}
	if (side == 0)
		data->player->perpWallDist = (data->player->sideDistX - data->player->deltaDistX);
	else
		data->player->perpWallDist = (data->player->sideDistY - data->player->deltaDistY);
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
	}
}

void	create_game(t_data *data)
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
				my_mlx_pixel_put(data, y, x, data->map->c);
			else
				my_mlx_pixel_put(data, y, x, data->map->f);
			y++;
		}
		x++;
	}
	which_position(data);
	while (1)
	{
		launch_rays(data);

	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
