/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:27:53 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/15 12:42:08 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	handle_events(t_data *data)
{
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, c_handler, data);
	// mlx_loop_hook(data->mlx, check_keys, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_handler, data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (printf("Error: Not enough arguments.\n"), 0);
	init_data(&data);
	check_input(av, &data);
	init_mlx(&data);
	create_imgs(&data);
	raycasting(&data);
	handle_events(&data);
	mlx_loop(data.mlx);
	ft_free_data(&data);
	return (0);
}
