/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:08:30 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/24 18:52:02 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_sprites(t_data *data, int map_x, int map_y)
{
	// Position du sprite sur la carte
	double sprite_x = map_x + 0.5 - data->player->posx;
	double sprite_y = map_y + 0.5 - data->player->posy;

	// Inverser la matrice de transformation caméra pour transformer la position du sprite
	double inv_det = 1.0 / (data->player->planex * data->player->diry - data->player->dirx * data->player->planey);
	double transform_x = inv_det * (data->player->diry * sprite_x - data->player->dirx * sprite_y);
	double transform_y = inv_det * (-data->player->planey * sprite_x + data->player->planex * sprite_y); // Distance projetée sur l'axe Y

	// Calcul de la position x du sprite sur l'écran
	int sprite_screen_x = (int)((data->width / 2) * (1 + transform_x / transform_y));

	// Hauteur du sprite (ajustée pour la perspective)
	int sprite_height = abs((int)(data->height / transform_y));
	int draw_start_y = -sprite_height / 2 + data->height / 2;
	if (draw_start_y < 0) draw_start_y = 0;
	int draw_end_y = sprite_height / 2 + data->height / 2;
	if (draw_end_y >= data->height) draw_end_y = data->height - 1;

	// Largeur du sprite (ajustée pour la perspective)
	int sprite_width = abs((int)(data->height / transform_y));
	int draw_start_x = -sprite_width / 2 + sprite_screen_x;
	if (draw_start_x < 0) draw_start_x = 0;
	int draw_end_x = sprite_width / 2 + sprite_screen_x;
	if (draw_end_x >= data->width) draw_end_x = data->width - 1;

	// Affichage du sprite pixel par pixel
	for (int stripe = draw_start_x; stripe < draw_end_x; stripe++)
	{
		int tex_x = (int)(256 * (stripe - (-sprite_width / 2 + sprite_screen_x)) * data->tab_img[FRAME_1].width / sprite_width) / 256;
		if (transform_y > 0 && stripe > 0 && stripe < data->width)
		{
			for (int y = draw_start_y; y < draw_end_y; y++)
			{
				int d = (y) * 256 - data->height * 128 + sprite_height * 128;
				int tex_y = ((d * data->tab_img[FRAME_1].height) / sprite_height) / 256;
				int color = get_pixel_color(&data->tab_img[FRAME_1], tex_x, tex_y, data);
				if (color != 0x000000) // 0x000000 = transparent color
					my_mlx_pixel_put_data(data, stripe, y, color);
			}
		}
	}
}

void	create_sprites(t_data *data)
{
	int	x;
	int	y;

	// Parcourir la carte pour trouver les sprites
	x = 0;
	while (data->map->map[x])
	{
		y = 0;
		while (data->map->map[x][y])
		{
			if (data->map->map[x][y] == 'Z') // 'Z' représente un zombie
				draw_sprites(data, x, y);
			y++;
		}
		x++;
	}
}
