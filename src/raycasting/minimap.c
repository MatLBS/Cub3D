/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:17:16 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/22 15:19:24 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	display_picto_door(t_data *data, t_img *img, int x, int y)
// {
// 	int	color;

// 	color = get_pixel_color(img, x - 150, y - 100, data);
// 	my_mlx_pixel_put_data(data, x, y, data->wall->color);
// }

void	find_pixel(t_data *data, int x, int y)
{
	double	new_x;
	double	new_y;
	double	new_posx;
	double	new_posy;

	new_posx = WIDTH_MINIMAP / 2;
	new_posy = HEIGHT_MINIMAP / 2;
	new_x = (x - new_posx) / SIZE_SQUARE + data->player->posx;
	new_y = (y - new_posy) / SIZE_SQUARE + data->player->posy;
	if (new_x < 0 || new_y < 0 || new_y >= size_tab(data->map->map) || new_x > (int)ft_strlen(data->map->map[(int)new_y]))
		my_mlx_pixel_put_data(data, x + 100, y + 700, 16777215);
	// else if (x == 0 || x == 300 || y == 0 || y == 200)
	// 	my_mlx_pixel_put_data(data, x + 100, y + 700, 000000);
	else if ((x >= 145 && x <= 155) && (y >= 95 && y <= 105))
		my_mlx_pixel_put_data(data, x + 100, y + 700, 4266955);
	else if (data->map->map[(int)new_y][(int)new_x] == '1')
		my_mlx_pixel_put_data(data, x + 100, y + 700, 13882323);
	else if (data->map->map[(int)new_y][(int)new_x] == 'D' || data->map->cpy_map[(int)new_y][(int)new_x] == 'D')
		my_mlx_pixel_put_data(data, x + 100, y + 700, 16761035);
	else
		my_mlx_pixel_put_data(data, x + 100, y + 700, 16777215);
}

void	create_minimap(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT_MINIMAP)
	{
		x = -1;
		while (++x < WIDTH_MINIMAP)
			find_pixel(data, x, y);
	}
}

// // printf("blanc\n");
// 	my_mlx_pixel_put_data(data, x, y, 16777215);

// // printf("rouge\n");
// 	my_mlx_pixel_put_data(data, x, y, 16711680);

// // printf("rose\n");
// 	my_mlx_pixel_put_data(data, x, y, 16761035);
