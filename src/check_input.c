/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:02:17 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/09 19:04:56 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_av1(char	**av, t_data *data)
{
	char	*str;
	int		fd;

	str = ft_strrchr(av[1], '.');
	if (ft_strncmp(str, ".cub", 4) != 0)
		return (printf("Error : The input file is not a .cub\n"), ft_free_data(data), exit(EXIT_FAILURE));
	fd = open(av[1], __O_DIRECTORY);
	if (fd >= 0)
		return (printf("Error : The input file must not be a directory.\n"), ft_free_data(data), exit(EXIT_FAILURE));
}

void	parse_map(t_data *data)
{
	static int	i;

	data->map->map = ft_realloc(data->map->map, sizeof(char *) * i, sizeof(char *) * (i + 1));
	data->map->map[i] = ft_strdup(data->str);
	i++;
}

void	parse_args(t_data *data)
{
	int		i;

	i = ft_isspace(data->str);
	if (data->str[i] == 'N' && data->str[i + 1] == 'O')
		data->map->no = check_xpm(data, i);
	else if (data->str[i] == 'S' && data->str[i + 1] == 'O')
		data->map->so = check_xpm(data, i);
	else if (data->str[i] == 'W' && data->str[i + 1] == 'E')
		data->map->we = check_xpm(data, i);
	else if (data->str[i] == 'E' && data->str[i + 1] == 'A')
		data->map->ea = check_xpm(data, i);
	else if (data->str[i] == 'F' && data->str[i + 1] == ' ')
		data->map->f = check_rgb(data, i);
	else if (data->str[i] == 'C' && data->str[i + 1] == ' ')
		data->map->c = check_rgb(data, i);
	else
		return (printf("Error : Bad argument implementation.\nThe possibilities are NO, SO, WE, EA, F or C.\n"), ft_free_data(data), exit(EXIT_FAILURE));
}

void	remove_endl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		str[i] = '\0';
}

int	check_input(char **av, t_data *data)
{
	check_av1(av, data);
	data->fd = open(av[1], O_RDONLY);
	if (data->fd == -1)
		return (printf("Error while opening the file !\n"), ft_free_data(data), exit(EXIT_FAILURE), 0);
	while (1)
	{
		data->str = get_next_line(data->fd, 0);
		if (!data->str)
		{
			get_next_line(data->fd, 1);
			break ;
		}
		else if (data->str[0] == '\n')
		{
			free(data->str);
			continue ;
		}
		remove_endl(data->str);
		printf("%s\n", data->str);
		if (data->map->nb_params == 6)
			parse_map(data);
		else
			parse_args(data);
		free(data->str);
	}
	ft_free_data(data);
	close(data->fd);
	return (1);
}
