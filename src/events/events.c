/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:57:45 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/18 11:21:38 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward(t_data *data)
{
	int	tmpx;
	int	tmpy;

	tmpx = data->player->posx + data->player->dirx;
	tmpy = data->player->posy + data->player->diry;
	if (data->map->map[tmpy][tmpx] != '1')
	{
		data->player->posx += data->player->dirx * MOVE_SPEED;
		data->player->posy += data->player->diry * MOVE_SPEED;
	}
	raycasting(data);
}

void	move_backwards(t_data *data)
{
	int	tmpx;
	int	tmpy;

	tmpx = data->player->posx - (data->player->dirx * MOVE_SPEED);
	tmpy = data->player->posy - (data->player->diry * MOVE_SPEED);
	if (data->map->map[tmpy][tmpx] != '1')
	{
		data->player->posx -= data->player->dirx * MOVE_SPEED;
		data->player->posy -= data->player->diry * MOVE_SPEED;
	}
	raycasting(data);
}

void	move_left(t_data *data)
{
	int	tmpx;
	int	tmpy;

	tmpx = data->player->posx - data->player->planex * MOVE_SPEED;
	tmpy = data->player->posy - data->player->planey * MOVE_SPEED;
	if (data->map->map[tmpy][tmpx] != '1')
	{
		data->player->posx -= data->player->planex * MOVE_SPEED;
		data->player->posy -= data->player->planey * MOVE_SPEED;
	}
	raycasting(data);
}

void	move_right(t_data *data)
{
	int	tmpx;
	int	tmpy;

	tmpx = data->player->posx + data->player->planex * MOVE_SPEED;
	tmpy = data->player->posy + data->player->planey * MOVE_SPEED;
	if (data->map->map[tmpy][tmpx] != '1')
	{
		data->player->posx += data->player->planex * MOVE_SPEED;
		data->player->posy += data->player->planey * MOVE_SPEED;
	}
	raycasting(data);
}

int	key_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		c_handler(data);
	else if (key == XK_w)
		move_forward(data);
	else if (key == XK_a)
		move_left(data);
	else if (key == XK_d)
		move_right(data);
	else if (key == XK_s)
		move_backwards(data);
	else if (key == 65361)
		turn_left(data);
	else if (key == 65363)
		turn_right(data);
	return (0);
}

// int	check_keys(t_data *data)
// {
// 	mlx_hook(data->win, KeyPress, KeyPressMask, key_handler, data);
// 	return (0);
// }
