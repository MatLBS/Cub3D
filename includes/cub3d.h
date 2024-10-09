/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:50:09 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/09 17:14:58 by matle-br         ###   ########.fr       */
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
	char	**map;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	t_map	*map;
}	t_data;

/* get_next_line.c */
char	*fill_stash(int fd, char *stash);
char	*fill_line(char *stash);
char	*clean_stash(char *stash);
char	*get_next_line(int fd);

/* check_input.c */
void	check_av1(char	**av, t_data *data);
void	parse_map(t_data *data, int fd, char *str);
void	parse_args(t_data *data, int fd, char *str);
void	remove_endl(char *str);
int		check_input(char **av, t_data *data);

/* parsing_utils.c */
char	*ft_strcpy_cub(char *dest, char *src, int size, int j);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int		ft_isspace(char *str);
char	*check_xpm(t_data *data, char *str, int i);
int		check_whitespace(char *str);
int		check_rgb(t_data *data, char *str, int i);

/* free.c */
void	ft_free_data(t_data *data);


#endif
