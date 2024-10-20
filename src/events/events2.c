/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:48:58 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/21 18:31:01 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	turn_left(t_data *data)
{
	double	olddirx;
	double	oldplanex;
	int		mult;

	mult = -1;
	if (data->map->pos_player == 'S' || data->map->pos_player == 'W')
		mult = 1;
	olddirx = data->player->dirx;
	data->player->dirx = data->player->dirx * cos(TURN_SPEED * mult) - \
	data->player->diry * sin(TURN_SPEED * mult);
	data->player->diry = olddirx * sin(TURN_SPEED * mult) + \
	data->player->diry * cos(TURN_SPEED * mult);
	oldplanex = data->player->planex;
	data->player->planex = data->player->planex * cos(TURN_SPEED * mult) - \
	data->player->planey * sin(TURN_SPEED * mult);
	data->player->planey = oldplanex * sin(TURN_SPEED * mult) + \
	data->player->planey * cos(TURN_SPEED * mult);
	raycasting(data);
}

void	turn_right(t_data *data)
{
	double	olddirx;
	double	oldplanex;
	int		mult;

	mult = 1;
	if (data->map->pos_player == 'S' || data->map->pos_player == 'W')
		mult = -1;
	olddirx = data->player->dirx;
	data->player->dirx = data->player->dirx * cos(TURN_SPEED * mult) - \
	data->player->diry * sin(TURN_SPEED * mult);
	data->player->diry = olddirx * sin(TURN_SPEED * mult) + \
	data->player->diry * cos(TURN_SPEED * mult);
	oldplanex = data->player->planex;
	data->player->planex = data->player->planex * cos(TURN_SPEED * mult) - \
	data->player->planey * sin(TURN_SPEED * mult);
	data->player->planey = oldplanex * sin(TURN_SPEED * mult) + \
	data->player->planey * cos(TURN_SPEED * mult);
	raycasting(data);
}

int	c_handler(t_data *data)
{
	ft_free_data(data);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_FAILURE);
	return (0);
}

int	handle_mouse(int x, int y, t_data *data)
{
	double	olddirx;
	double	oldplanex;

	if (data->mouse == 0)
		return (0);
	olddirx = data->player->dirx;
	data->player->dirx = data->player->dirx * cos(x) - data->player->diry * sin(y);
	data->player->diry = olddirx * sin(y) + data->player->diry * cos(x);
	oldplanex = data->player->planex;
	data->player->planex = data->player->planex * cos(x) - data->player->planey * sin(y);
	data->player->planey = oldplanex * sin(y) + data->player->planey * cos(x);
	raycasting(data);
	return (0);
}
