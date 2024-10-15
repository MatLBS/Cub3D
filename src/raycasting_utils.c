/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:30:47 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/15 13:06:07 by matle-br         ###   ########.fr       */
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

// int	get_texture_color(t_data *data, int texX, int texY, int texWidth)
// {
// 	int	*pixels;
// 	int	color;

// 	pixels = (int *)mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->line_length, &data->endian);
// 	color = pixels[texY * texWidth + texX];

// 	return (color);
// }
