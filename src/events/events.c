/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:57:45 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/23 09:22:17 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward(t_data *data)
{
	int	tmpx;
	int	tmpy;

	tmpx = data->player->posx + data->player->dirx * MOVE_SPEED * 2;
	tmpy = data->player->posy + data->player->diry * MOVE_SPEED * 2;
	if (data->map->map[tmpy][(int)data->player->posx] != '1' && \
		data->map->map[tmpy][(int)data->player->posx] != 'D')
		data->player->posy += data->player->diry * MOVE_SPEED;
	if (data->map->map[(int)data->player->posy][tmpx] != '1' && \
		data->map->map[(int)data->player->posy][tmpx] != 'D')
		data->player->posx += data->player->dirx * MOVE_SPEED;
}

void	move_backwards(t_data *data)
{
	int	tmpx;
	int	tmpy;

	tmpx = data->player->posx - data->player->dirx * MOVE_SPEED * 2;
	tmpy = data->player->posy - data->player->diry * MOVE_SPEED * 2;
	if (data->map->map[tmpy][(int)data->player->posx] != '1' && \
		data->map->map[tmpy][(int)data->player->posx] != 'D')
		data->player->posy -= data->player->diry * MOVE_SPEED;
	if (data->map->map[(int)data->player->posy][tmpx] != '1' && \
		data->map->map[(int)data->player->posy][tmpx] != 'D')
		data->player->posx -= data->player->dirx * MOVE_SPEED;
}

void	move_left(t_data *data)
{
	int	tmpx;
	int	tmpy;

	tmpx = data->player->posx - data->player->planex * MOVE_SPEED * 2;
	tmpy = data->player->posy - data->player->planey * MOVE_SPEED * 2;
	if (data->map->map[tmpy][(int)data->player->posx] != '1' && \
		data->map->map[tmpy][(int)data->player->posx] != 'D')
		data->player->posy -= data->player->planey * MOVE_SPEED;
	if (data->map->map[(int)data->player->posy][tmpx] != '1' && \
		data->map->map[(int)data->player->posy][tmpx] != 'D')
		data->player->posx -= data->player->planex * MOVE_SPEED;
}

void	move_right(t_data *data)
{
	int	tmpx;
	int	tmpy;

	tmpx = data->player->posx + data->player->planex * MOVE_SPEED * 2;
	tmpy = data->player->posy + data->player->planey * MOVE_SPEED * 2;
	if (data->map->map[tmpy][(int)data->player->posx] != '1' && \
		data->map->map[tmpy][(int)data->player->posx] != 'D')
		data->player->posy += data->player->planey * MOVE_SPEED;
	if (data->map->map[(int)data->player->posy][tmpx] != '1' && \
		data->map->map[(int)data->player->posy][tmpx] != 'D')
		data->player->posx += data->player->planex * MOVE_SPEED;
}

static void	handle_door(t_data *data)
{
	int	tmpx;
	int	tmpy;

	tmpx = data->player->posx + data->player->dirx;
	tmpy = data->player->posy + data->player->diry;
	if (data->map->map[tmpy][tmpx] == 'D')
		data->map->map[tmpy][tmpx] = '0';
	else if (data->map->cpy_map[tmpy][tmpx] == 'D' && \
		data->map->map[tmpy][tmpx] == '0')
		data->map->map[tmpy][tmpx] = 'D';
}

int	key_starter(int key, t_data *data)
{
	if (key == XK_Escape)
		c_handler(data);
	if (key == XK_w)
		data->keys->key_w = 1;
	if (key == XK_a)
		data->keys->key_a = 1;
	if (key == XK_d)
		data->keys->key_d = 1;
	if (key == XK_s)
		data->keys->key_s = 1;
	if (key == 65361)
		data->keys->left_arrow = 1;
	if (key == 65363)
		data->keys->right_arrow = 1;
	if (key == XK_e)
		handle_door(data);
	if (key == 65507 && data->mouse == 0)
	{
		mlx_mouse_hide(data->mlx, data->win);
		data->mouse = 1;
	}
	else if (key == 65507 && data->mouse == 1)
	{
		mlx_mouse_show(data->mlx, data->win);
		data->mouse = 0;
	}
	return (0);
}

int	key_closer(int key, t_data *data)
{
	if (key == XK_w)
		data->keys->key_w = 0;
	if (key == XK_a)
		data->keys->key_a = 0;
	if (key == XK_d)
		data->keys->key_d = 0;
	if (key == XK_s)
		data->keys->key_s = 0;
	if (key == 65361)
		data->keys->left_arrow = 0;
	if (key == 65363)
		data->keys->right_arrow = 0;
	return (0);
}

int	check_keys(t_data *data)
{
	if (data->keys->key_w == 1)
		move_forward(data);
	if (data->keys->key_a == 1)
		move_left(data);
	if (data->keys->key_d == 1)
		move_right(data);
	if (data->keys->key_s == 1)
		move_backwards(data);
	if (data->keys->left_arrow == 1)
		turn_left(data, TURN_SPEED);
	if (data->keys->right_arrow == 1)
		turn_right(data, TURN_SPEED);
	raycasting(data);
	return (0);
}
