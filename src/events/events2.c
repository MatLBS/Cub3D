/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:48:58 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/18 11:19:52 by matle-br         ###   ########.fr       */
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
