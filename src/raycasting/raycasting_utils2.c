/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:55:31 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/18 11:20:33 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	get_texture_color(t_data *data, int pixelX)
{
	int		texX;
	double	step;
	int		y = data->wall->drawstart;
	int		texY;
	double	wallX;
	if (data->wall->side == 0)
	{
		if (data->player->raydirx > 0)
			data->wall->face = EAST;
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
		wallX = data->player->posy + data->wall->perpwalldist * data->player->raydiry;
	else
		wallX = data->player->posx + data->wall->perpwalldist * data->player->raydirx;
	wallX -= floor(wallX);
	texX = (int)(wallX * (double)(data->tab_img[data->wall->face].width));
	if (data->wall->side == 0 && data->player->raydirx > 0)
		texX = data->tab_img[data->wall->face].width - texX - 1;
	if (texX < 0)
		texX = 0;
	if (data->wall->side == 1 && data->player->raydiry)
		texX = data->tab_img[data->wall->face].width - texX - 1;
	step = 1.0 * data->tab_img[data->wall->face].height / data->wall->lineheight;
	double texPos = (data->wall->drawstart - data->height / 2 + data->wall->lineheight / 2) * step;
	while (y < data->wall->drawend)
	{
		texY = (int)texPos & (data->tab_img[data->wall->face].height - 1);
		if (texY >= data->tab_img[data->wall->face].height)
			texY = data->tab_img[data->wall->face].height - 1;
		if (texY < 0)
			texY = 0;
		texPos += step;
		data->wall->color = get_pixel_color(&data->tab_img[data->wall->face], texX, texY, data);
		my_mlx_pixel_put_data(data, pixelX, y, data->wall->color);
		y++;
	}
}
