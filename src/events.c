/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:57:45 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/15 13:10:26 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_data *data)
{
	data->player->posX += data->player->dirX * MOVE_SPEED;
	data->player->posY += data->player->dirY * MOVE_SPEED;
	raycasting(data);
}

void	move_backwards(t_data *data)
{
	data->player->posX -= data->player->dirX * MOVE_SPEED;
	data->player->posY -= data->player->dirY * MOVE_SPEED;
	raycasting(data);
}

void	move_left(t_data *data)
{
	if (data->map->pos_player == 'N')
		data->player->posX -= 0.2;
	else if (data->map->pos_player == 'S')
		data->player->posX -= 0.2;
	else if (data->map->pos_player == 'E')
		data->player->posY -= 0.2;
	else
		data->player->posY -= 0.2;
	raycasting(data);
}

void	move_right(t_data *data)
{
	if (data->map->pos_player == 'N')
		data->player->posX += 0.2;
	else if (data->map->pos_player == 'S')
		data->player->posX += 0.2;
	else if (data->map->pos_player == 'E')
		data->player->posY += 0.2;
	else
		data->player->posY += 0.2;
	raycasting(data);
}

int	c_handler(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_FAILURE);
	return (0);
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
	return (0);
}

// int	check_keys(t_data *data)
// {
// 	mlx_hook(data->win, KeyPress, KeyPressMask, key_handler, data);
// 	return (0);
// }
