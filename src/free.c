/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:55:55 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/09 18:37:43 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_data(t_data *data)
{
	if (data->map)
		free(data->map);
	// get_next_line(data->fd, 1);
	if (data->str)
		free(data->str);
}
