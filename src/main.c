/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:27:53 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/11 14:36:29 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	handle_events(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, key_handler, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, c_handler, data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (printf("Error: Not enough arguments.\n"), 0);
	init_data(&data);
	init_mlx(&data);
	check_input(av, &data);
	handle_events(&data);
	create_game(&data);
	mlx_loop(data.mlx);
	// printf("no = %s\n", data.map->no);
	// printf("so = %s\n", data.map->so);
	// printf("we = %s\n", data.map->we);
	// printf("ea = %s\n", data.map->ea);
	// printf("f = %d\n", data.map->f);
	// printf("c = %d\n", data.map->c);
	// int	i = 0;
	// while(data.map->map[i])
	// {
	// 	printf("%s\n", data.map->map[i]);
	// 	i++;
	// }
	ft_free_data(&data);
	return (0);
}
