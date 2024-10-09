/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:08:18 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/09 12:31:09 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strcpy(char *dest, char *src, int size, int j)
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

int	isspace(char *str)
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

void	check_xpm(t_data *data, char *str, int i)
{
	char	*str1;

	i += 2;
	while (!ft_isascii(str[i]))
		i++;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (printf("Bad xpm input, found a whitespace.\n"), exit(0));
		i++;
	}
	str1 = ft_strrchr(str, '.');
	if (ft_strcmp(str1, ".xpm") != 0)
		return (printf("No .xpm at end of file.\n"), exit(0));
	data->map->nb_params += 1;
}

void	check_rgb(t_data *data, char *str, int i)
{
	int		nb;
	char	**tab;
	char	*new_str;

	i += 1;
	while (!ft_isalnum(str[i]))
		i++;
	new_str = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new_str)
		return ;
	new_str = ft_strcpy(new_str, str, (ft_strlen(str) - i), i);
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (printf("Bad rgb input, found a whitespace.\n"), exit(0));
		i++;
	}
	tab = ft_split(new_str, ',');
	if (!tab)
		return (free(new_str));
	i = 0;
	while (tab[i])
	{
		nb = ft_atoi(tab[i]);
		if (nb > 255 || nb < 0)
			return (printf("Invalid RGB input\n"), exit(0));
		i++;
	}
}
