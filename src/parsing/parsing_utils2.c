/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:59:36 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/18 13:12:48 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_sides(char *str, t_data *data)
{
	int	i;

	i = ft_isspace(str);
	if (str[i] != '1')
	{
		printf("Error : Map not closed on left side.\n");
		ft_free_data(data);
		return (exit(EXIT_FAILURE), 0);
	}
	while (str[i + 1] != '\0')
		i++;
	if (str[i] != '1')
	{
		printf("Error : Map not closed on right side.\n");
		ft_free_data(data);
		return (exit(EXIT_FAILURE), 0);
	}
	return (1);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && (str[i] == ',' && !ft_isdigit(str[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

void	ft_strcpy_cub(char *dest, char *src, int size, int j)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*temp;
	size_t	copy_size;

	temp = malloc(new_size);
	if (!temp)
		return (NULL);
	if (ptr)
	{
		if (old_size < new_size)
			copy_size = old_size;
		else
			copy_size = new_size;
		ft_memcpy(temp, ptr, copy_size);
		free(ptr);
	}
	return (temp);
}
