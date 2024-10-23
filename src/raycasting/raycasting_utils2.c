/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:55:31 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/23 17:44:44 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	handle_door(t_data *data)
{
	if (data->wall->side == 0)
	{
		if (data->player->raydirx > 0)
			data->wall->face = DOOR_1;
		else
			data->wall->face = DOOR_1;
	}
	else
	{
		if (data->player->raydiry > 0)
			data->wall->face = DOOR;
		else
			data->wall->face = DOOR_1;
	}
}

// static void	handle_zombie(t_data *data)
// {
// 	data->wall->face = FRAME_1;
// }

int	size_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	get_pixel_color(t_img *img, int pixelX, int pixelY, t_data *data)
{
	if (pixelX >= img->width)
		pixelX = (pixelX * img->width) / data->width;
	if (pixelY >= img->height)
		pixelY = (pixelY * img->height) / data->height;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	if (!img->addr)
	{
		ft_free_data(data);
		c_handler(data);
	}
	return (*(unsigned long *)((img->addr + (pixelY * img->line_length) + \
		(pixelX * img->bits_per_pixel / 8))));
}

void	get_texture_color_suite(t_data *data, int pixelX, int y)
{
	double	step;

	data->player->wallx -= floor(data->player->wallx);
	data->player->texx = (int)(data->player->wallx * \
		(double)(data->tab_img[data->wall->face].width));
	if (data->wall->side == 0 && data->player->raydirx > 0)
		data->player->texx = data->tab_img[data->wall->face].width - \
			data->player->texx - 1;
	if (data->player->texx < 0)
		data->player->texx = 0;
	if (data->wall->side == 1 && data->player->raydiry)
		data->player->texx = data->tab_img[data->wall->face].width - \
			data->player->texx - 1;
	step = (1.0 * data->tab_img[data->wall->face].height) / \
		data->wall->lineheight;
	data->player->texpos = (data->wall->drawstart - data->height / 2 + \
		data->wall->lineheight / 2) * step;
	while (y < data->wall->drawend)
	{
		printf("height = %d\n", data->tab_img[FRAME_1].height);
		// printf("height = %d\n", data->tab_img[FRAME_1].height);
		data->player->texy = (int)data->player->texpos & \
			(data->tab_img[data->wall->face].height - 1);
		if (data->player->texy >= data->tab_img[data->wall->face].height)
			data->player->texy = data->tab_img[data->wall->face].height - 1;
		if (data->player->texy < 0)
			data->player->texy = 0;
		data->player->texpos += step;
		data->wall->color = get_pixel_color(&data->tab_img[data->wall->face], \
			data->player->texx, data->player->texy, data);
		my_mlx_pixel_put_data(data, pixelX, y, data->wall->color);
		y++;
	}
}

void	get_texture_color(t_data *data, int pixelX)
{
	int		y;

	y = data->wall->drawstart;
	if (data->wall->hit_door == 1)
		handle_door(data);
	// else if (data->wall->hit_zombie == 1)
	// 	handle_zombie(data);
	else if (data->wall->side == 0)
	{
		if (data->player->raydirx > 0)
			data->wall->face = FRAME_1;
		else
			data->wall->face = WEST;
	}
	else
	{
		if (data->player->raydiry > 0)
			data->wall->face = SOUTH;
		else
			data->wall->face = NORTH;
	}
	if (data->wall->side == 0)
		data->player->wallx = data->player->posy + \
			data->wall->perpwalldist * data->player->raydiry;
	else
		data->player->wallx = data->player->posx + \
			data->wall->perpwalldist * data->player->raydirx;
	get_texture_color_suite(data, pixelX, y);
}
