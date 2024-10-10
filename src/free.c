/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:55:55 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/10 14:40:06 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_cub(char **tab)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (!tab)
		return ;
	while (tab[k])
		k++;
	while (i < k)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_data(t_data *data)
{
	if (data->map->no)
		free(data->map->no);
	if (data->map->so)
		free(data->map->so);
	if (data->map->we)
		free(data->map->we);
	if (data->map->ea)
		free(data->map->ea);
	if (data->map->map)
		ft_free_cub(data->map->map);
	if (data->map)
		free(data->map);
	if (data->str)
		free(data->str);
}
