/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:27:53 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/09 18:31:36 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		printf("Error while allocating  map.\n"), exit(EXIT_FAILURE);
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->map = NULL;
	map->f = 0;
	map->c = 0;
	map->nb_params = 0;
	return (map);
}

void	init_data(t_data *data)
{
	data->str = NULL;
	data->map = init_map();
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (printf("Error: Not enough arguments.\n"), 0);
	init_data(&data);
	check_input(av, &data);
	return (0);
}
