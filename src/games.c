/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   games.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:07:12 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/12 20:45:44 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	which_position(t_data *data)
{
	if (data->map->pos_player == 'N')
	{
		data->player->dirX = -1;
		data->player->dirY = 0;
	}
	else if (data->map->pos_player == 'S')
	{
		data->player->dirX = 1;
		data->player->dirY = 0;
	}
	else if (data->map->pos_player == 'E')
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
	int	hit;
	int	side;

	hit = 0;
	printf("algo_dda\n");
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
	printf("algo_dda1\n");
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
		printf("mapX = %d\n", data->player->mapX);
		printf("mapY = %d\n", data->player->mapY);
		printf("%c\n", data->map->map[11][27]);
		if (data->map->map[data->player->mapY][data->player->mapX] == 1)
			hit  = 1;
		printf("algo_dda2\n");
	}
	printf("algo_dda2\n");
	if (side == 0)
		data->wall->perpWallDist = (data->player->sideDistX - data->player->deltaDistX);
	else
		data->wall->perpWallDist = (data->player->sideDistY - data->player->deltaDistY);
}

void	display_wall(t_data *data)
{
	printf("display_wall\n");
	data->wall->lineHeight = (int)(data->height / data->wall->perpWallDist);
	data->wall->drawStart = (data->wall->lineHeight * -1) / 2 + data->height / 2;
	if (data->wall->drawStart < 0)
		data->wall->drawStart = 0;
	data->wall->drawEnd = (data->wall->lineHeight / 2) + (data->height / 2);
	if (data->wall->drawEnd >= data->height)
		data->wall->drawEnd = data->height - 1;
	while (data->wall->drawStart < data->wall->drawEnd)
	{
		data->wall->color = get_texture_color(data, (int)data->player->cameraX, data->wall->drawStart, data->wall->width_xpm);
		my_mlx_pixel_put(data, (int)data->player->cameraX, data->wall->drawStart, data->wall->color);
		data->wall->drawStart++;
	}
}

void	launch_rays(t_data *data)
{
	int	x;

	x = 0;
	printf("launch_rays\n");
	while (x < data->width)
	{
		data->player->cameraX = ((2 * x) / (double)(data->width)) - 1;
		data->player->rayDirX = data->player->dirX + (data->player->planeX * data->player->cameraX);
		data->player->rayDirY = data->player->dirY + (data->player->planeY * data->player->cameraX);
		algo_dda(data);
		display_wall(data);
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
	data->img_ptr = mlx_xpm_file_to_image(data->mlx, "../textures/east.xpm", &data->wall->width_xpm, &data->wall->height_xpm);
	which_position(data);
	printf("bonjour\n");
	while (1)
	{
		launch_rays(data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
