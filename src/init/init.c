/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:36:17 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/18 11:19:56 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_wall	*init_wall(t_data *data)
{
	t_wall	*wall;

	wall = malloc(sizeof(t_map));
	if (!wall)
		return (printf("Error while allocating wall.\n"), \
			ft_free_data(data), exit(EXIT_FAILURE), NULL);
	wall->perpwalldist = 0;
	wall->lineheight = 0;
	wall->drawend = 0;
	wall->drawstart = 0;
	wall->color = 0;
	wall->width_xpm = 0;
	wall->height_xpm = 0;
	wall->face = -1;
	return (wall);
}

void	init_imgs(t_img *tab_img)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		tab_img[i].img = NULL;
		tab_img[i].addr = NULL;
		tab_img[i].bits_per_pixel = 0;
		tab_img[i].line_length = 0;
		tab_img[i].endian = 0;
		tab_img[i].width = 0;
		tab_img[i].height = 0;
		i++;
	}
}

void	init_data(t_data *data)
{
	data->str = NULL;
	data->width = 0;
	data->height = 0;
	data->map = init_map();
	data->player = init_player(data);
	data->wall = init_wall(data);
	init_imgs(data->tab_img);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_free_data(data);
	mlx_get_screen_size(data->mlx, &data->width, &data->height);
	data->win = mlx_new_window(data->mlx, data->width, data->height, "Cub3D");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (ft_free_data(data), exit(EXIT_FAILURE));
	}
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img)
		c_handler(data);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
					&data->line_length, &data->endian);
	if (!data->addr)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_free_data(data);
		exit(EXIT_FAILURE);
	}
}
