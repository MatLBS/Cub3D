/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:50:09 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/10 17:32:54 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif


typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
	int		nb_params;
	char	pos_player;
	int		player;
	char	**map;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		fd;
	char	*str;
	t_map	*map;
}	t_data;

/* get_next_line.c */
char	*fill_stash(int fd, char *stash);
char	*fill_line(char *stash);
char	*clean_stash(char *stash);
char	*get_next_line(int fd, int flag);

/* check_input.c */
void	check_av1(char	**av, t_data *data);
void	parse_map(t_data *data);
void	parse_args(t_data *data);
void	remove_endl(char *str);
int		check_input(char **av, t_data *data);

/* parsing_utils.c */
void	ft_free_cub(char **tab);
int		ft_isspace(char *str);
char	*check_xpm(t_data *data, int i);
int		check_whitespace(char *str);
int		check_rgb(t_data *data, int i);

/* parsing_utils2.c */
void	ft_strcpy_cub(char *dest, char *src, int size, int j);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int		check_rgb_suite(char **tab, t_data *data, char *new_str);
int		check_number(char *str);
int		check_sides(char *str, t_data *data);

/* check_map.c */
int		check_space(t_data *data, char **tab, int i);
int		check_line(char *str, t_data *data);
int		check_first_line(char **tab, t_data *data, int i);
int		check_last_line(char **tab, t_data *data, int i);
int		check_map(t_data *data);

/* free.c */
void	ft_free_data(t_data *data);


#endif
