/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   games_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:11:09 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/12 20:38:39 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_texture_color(t_data *data, int texX, int texY, int texWidth)
{
	int	*pixels;
	int	color;

	pixels = (int *)mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->line_length, &data->endian);
	color = pixels[texY * texWidth + texX];

	return (color);
}
