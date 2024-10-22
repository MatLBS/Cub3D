/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:27:53 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/22 17:11:08 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	handle_events(t_data *data)
{
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, c_handler, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_starter, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_closer, data);
	mlx_hook(data->win, MotionNotify, PointerMotionMask, handle_mouse, data);
	mlx_loop_hook(data->mlx, check_keys, data);
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
	which_position(&data);
	handle_events(&data);
	mlx_loop(data.mlx);
	return (0);
}
