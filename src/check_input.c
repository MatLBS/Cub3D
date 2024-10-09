/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:02:17 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/09 17:22:34 by matle-br         ###   ########.fr       */
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

void	parse_map(t_data *data, int fd, char *str)
{
	static int	i;

	(void)fd;
	data->map->map = ft_realloc(data->map->map, sizeof(char *) * i, sizeof(char *) * (i + 1));
	data->map->map[i] = ft_strdup(str);
	i++;
}

void	parse_args(t_data *data, int fd, char *str)
{
	int		i;

	(void)fd;
	i = ft_isspace(str);
	if (str[i] == 'N' && str[i + 1] == 'O')
		data->map->no = check_xpm(data, str, i);
	else if (str[i] == 'S' && str[i + 1] == 'O')
		data->map->so = check_xpm(data, str, i);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		data->map->we = check_xpm(data, str, i);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		data->map->ea = check_xpm(data, str, i);
	else if (str[i] == 'F' && str[i + 1] == ' ')
		data->map->f = check_rgb(data, str, i);
	else if (str[i] == 'C' && str[i + 1] == ' ')
		data->map->c = check_rgb(data, str, i);
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
	int		fd;
	char	*str;

	check_av1(av, data);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error while opening the file !\n"), ft_free_data(data), exit(EXIT_FAILURE), 0);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		else if (str[0] == '\n')
		{
			free(str);
			continue ;
		}
		remove_endl(str);
		printf("%s\n", str);
		if (data->map->nb_params == 6)
			parse_map(data, fd, str);
		else
			parse_args(data, fd, str);
		free(str);
	}
	ft_free_data(data);
	return (1);
}
