/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:02:17 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/09 12:02:35 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_av1(char	**av)
{
	char	*str;
	int		fd;

	str = ft_strrchr(av[1], '.');
	if (ft_strcmp(str, ".cub" != 0))
		return (printf("The input file is not a .cub ."), exit(0));
	fd = open(av[1], __O_DIRECTORY);
	if (fd > 0)
		return (printf("The input file must not be a directory."), exit(0));
	return (1);
}

int	parse_map(t_data *data, int fd)
{
	int		i;
	char	*str;

	i = 0;
	str = get_next_line(fd);
	data->map->map = ft_realloc(data->map->map, sizeof(char *) * i, \
	sizeof(char *) * (i + 1));
	remove_endl(str);
	data->map->map[i] = ft_strdup(str);
	free(str);
	i++;
}

void	parse_args(t_data *data, int fd)
{
	char	*str;
	int		i;

	str = get_next_line(fd);
	i = isspace(str);
	if (str[i] == 'N' && str[i + 1] == 'O')
		check_xpm(data, str, i);
	else if (str[i] == 'S' && str[i + 1] == 'O')
		check_xpm(data, str, i);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		check_xpm(data, str, i);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		check_xpm(data, str, i);
	else if (str[i] == 'F' && str[i + 1] == ' ')
		check_rgb(data, str, i);
	else if (str[i] == 'C' && str[i + 1] == ' ')
		check_rgb(data, str, i);
	else
		return (printf("Bad argument implementation.\nThe possibilities are NO, SO, WE, EA, F or C.\n"), exit(0));
}

int	check_input(char **av, t_data *data)
{
	int		fd;

	check_av1(av);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error while opening the file !\n"), 0);
	while (1)
	{
		if (data->map->nb_params == 6)
			parse_map(data, fd);
		else
			parse_args(data, fd);
	}
}
