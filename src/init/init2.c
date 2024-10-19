/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:50:57 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/19 14:11:00 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (printf("Error while allocating map.\n"), \
			exit(EXIT_FAILURE), NULL);
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->map = NULL;
	map->cpy_map = NULL;
	map->pos_player = 0;
	map->player = 0;
	map->f = 0;
	map->c = 0;
	map->nb_params = 0;
	return (map);
}

t_player	*init_player(t_data *data)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (printf("Error while allocating player.\n"), \
			ft_free_data(data), exit(EXIT_FAILURE), NULL);
	player->posx = 0;
	player->posy = 0;
	player->dirx = 0;
	player->posy = 0;
	player->mapx = 0;
	player->mapy = 0;
	player->stepx = 0;
	player->stepy = 0;
	player->sidedistx = 0;
	player->sidedisty = 0;
	player->deltadistx = 0;
	player->deltadisty = 0;
	player->planex = 0;
	player->planey = 0;
	player->camerax = 0;
	player->raydirx = 0;
	player->raydiry = 0;
	return (player);
}
