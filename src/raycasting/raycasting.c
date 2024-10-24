/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:07:12 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/24 18:20:17 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	algo_dda_suite(t_data *data, int hit)
{
	while (hit == 0)
	{
		if (data->player->sidedistx < data->player->sidedisty)
		{
			data->player->sidedistx += data->player->deltadistx;
			data->player->mapx += data->player->stepx;
			data->wall->side = 0;
		}
		else
		{
			data->player->sidedisty += data->player->deltadisty;
			data->player->mapy += data->player->stepy;
			data->wall->side = 1;
		}
		if (data->map->map[data->player->mapy][data->player->mapx] == '1')
		{
			hit = 1;
			data->wall->hit_door = 0;
			// data->wall->hit_zombie = 0;
		}
		if (data->map->map[data->player->mapy][data->player->mapx] == 'D')
		{
			hit = 1;
			data->wall->hit_door = 1;
		}
		// if (data->map->map[data->player->mapy][data->player->mapx] == 'Z')
		// {
		// 	hit = 1;
		// 	data->wall->hit_zombie = 1;
		// }
	}
	if (data->wall->side == 0)
		data->wall->perpwalldist = (data->player->sidedistx - \
			data->player->deltadistx);
	else
		data->wall->perpwalldist = (data->player->sidedisty - \
			data->player->deltadisty);
}

void	algo_dda(t_data *data)
{
	data->player->mapx = (int)data->player->posx;
	data->player->mapy = (int)data->player->posy;
	data->player->deltadistx = fabs(1 / data->player->raydirx);
	data->player->deltadisty = fabs(1 / data->player->raydiry);
	if (data->player->raydirx < 0)
	{
		data->player->stepx = -1;
		data->player->sidedistx = (data->player->posx - data->player->mapx) * \
			data->player->deltadistx;
	}
	else
	{
		data->player->stepx = 1;
		data->player->sidedistx = (data->player->mapx + 1.0 - \
			data->player->posx) * data->player->deltadistx;
	}
	if (data->player->raydiry < 0)
	{
		data->player->stepy = -1;
		data->player->sidedisty = (data->player->posy - data->player->mapy) * \
			data->player->deltadisty;
	}
	else
	{
		data->player->stepy = 1;
		data->player->sidedisty = (data->player->mapy + 1.0 - \
			data->player->posy) * data->player->deltadisty;
	}
	algo_dda_suite(data, 0);
}

void	display_wall(t_data *data, int x)
{
	data->wall->lineheight = (int)(data->height / data->wall->perpwalldist);
	data->wall->drawstart = ((data->wall->lineheight * -1) / 2 + data->height / 2);
	if (data->wall->drawstart < 0)
		data->wall->drawstart = 0;
	data->wall->drawend = data->wall->lineheight / 2 + data->height / 2;
	if (data->wall->drawend >= data->height)
		data->wall->drawend = data->height - 1;
	get_texture_color(data, x);
}

void	launch_rays(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->width)
	{
		data->player->camerax = ((2 * x) / (double)(data->width)) - 1;
		data->player->raydirx = data->player->dirx + \
			(data->player->planex * data->player->camerax);
		data->player->raydiry = data->player->diry + \
			(data->player->planey * data->player->camerax);
		algo_dda(data);
		display_wall(data, x);
		x++;
	}
	create_sprites(data);
	create_minimap(data);
}

void	raycasting(t_data *data)
{
	long	nb;

	ft_memcpy(data->addr, data->tab_img[BACKGROUND].addr, \
		data->width * data->height * (data->bits_per_pixel / 8));
	launch_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	nb = get_time();
	if (nb - data->first_action < 20000)
	{
		mlx_string_put(data->mlx, data->win, 1400, 80, 4266955, FIRST_SENTENCE);
		mlx_string_put(data->mlx, data->win, 1400, 100, 4266955, SECOND_SENTENCE);
		mlx_string_put(data->mlx, data->win, 1400, 120, 4266955, THIRD_SENTENCE);
		mlx_string_put(data->mlx, data->win, 1400, 140, 4266955, FOURTH_SENTENCE);
		mlx_string_put(data->mlx, data->win, 1400, 160, 4266955, FIFTH_SENTENCE);
		mlx_string_put(data->mlx, data->win, 1400, 180, 4266955, SIXTH_SENTENCE);
		mlx_string_put(data->mlx, data->win, 1400, 200, 4266955, SEVENTH_SENTENCE);
	}
}
