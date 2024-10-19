/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:30:47 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/19 16:55:16 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	which_fov(t_data *data)
{
	if (data->map->pos_player == 'N' || data->map->pos_player == 'S')
	{
		data->player->planex = 0.66;
		data->player->planey = 0;
	}
	else
	{
		data->player->planex = 0;
		data->player->planey = 0.66;
	}
}

void	which_position(t_data *data)
{
	if (data->map->pos_player == 'N')
	{
		data->player->dirx = 0;
		data->player->diry = -1;
	}
	else if (data->map->pos_player == 'S')
	{
		data->player->dirx = 0;
		data->player->diry = 1;
	}
	else if (data->map->pos_player == 'E')
	{
		data->player->dirx = 1;
		data->player->diry = 0;
	}
	else
	{
		data->player->dirx = -1;
		data->player->diry = 0;
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

void	create_minimap(t_data *data)
{
	int	x;
	int	y;
	// int	new_posx;
	// int	new_posy;

	// new_posx = data->player->posx - 5;
	// new_posy = data->player->posy - 5;
	y = 200;
	while (y < 400)
	{
		x = 100;
		while (x < 350)
		{
			if (data->map->map[y / (int)data->player->posy][x / (int)data->player->posx] == '0')
			{
				// printf("blanc\n");
				my_mlx_pixel_put_data(data, x, y, 16777215);
			}
			else if (data->map->map[y / (int)data->player->posy][x / (int)data->player->posx] == '1')
			{
				// printf("rouge\n");
				my_mlx_pixel_put_data(data, x, y, 16711680);
			}
			else
			{
				// printf("rose\n");
				my_mlx_pixel_put_data(data, x, y, 16761035);
			}
			x++;
		}
		y++;
	}
}
