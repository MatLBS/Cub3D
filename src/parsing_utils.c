/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:08:18 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/09 17:02:32 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strcpy_cub(char *dest, char *src, int size, int j)
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
	return (dest);
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

int	ft_isspace(char *str)
{
	int	i;

	i = 0;
	while(str[i] == ' ' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\t')
	{
		i++;
	}
	return (i);
}

char	*check_xpm(t_data *data, char *str, int i)
{
	char	*str1;
	char	*str2;

	i += 2;
	while (!ft_isalnum(str[i]))
		i++;
	str2 = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!str2)
		return (NULL);
	str2 = ft_strcpy_cub(str2, str, (ft_strlen(str) - i), i);
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (printf("Bad xpm input, found a whitespace.\n"), ft_free_data(data), exit(EXIT_FAILURE), NULL);
		i++;
	}
	str1 = ft_strrchr(str, '.');
	if (ft_strncmp(str1, ".xpm", 4) != 0)
		return (printf("No .xpm at end of file.\n"), ft_free_data(data), NULL);
	data->map->nb_params += 1;
	return (str2);
}

int	check_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (0);
		i++;
	}
	return (1);
}

int	check_rgb(t_data *data, char *str, int i)
{
	char	**tab;
	char	*new_str;

	i += 1;
	while (!ft_isalnum(str[i]))
		i++;
	new_str = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new_str)
		return (0);
	new_str = ft_strcpy_cub(new_str, str, (ft_strlen(str) - i), i);
	i = 0;
	if (check_whitespace(new_str) == 0)
		return (printf("Bad rgb input, found a whitespace.\n"), exit(EXIT_FAILURE), 0);
	tab = ft_split(new_str, ',');
	if (!tab)
		return (free(new_str), 1);
	i = -1;
	while (tab[++i])
	{
		if (ft_atoi(tab[i]) > 255 || ft_atoi(tab[i]) < 0)
			return (printf("Invalid RGB input.\n"), exit(EXIT_FAILURE), 0);
	}
	data->map->nb_params += 1;
	return (free(new_str), ft_atoi(tab[0]) << 16 | ft_atoi(tab[1]) << 8 | ft_atoi(tab[2]));
}
