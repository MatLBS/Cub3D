/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:50:09 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/09 12:02:09 by matle-br         ###   ########.fr       */
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

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	t_map	*map;
}	t_data;

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

/* get_next_line.c */
char	*ft_free_line(char *str, char *str2);
char	*fill_stash(int fd, char *stash);
char	*fill_line(char *stash);
char	*clean_stash(char *stash);
char	*get_next_line(int fd);

#endif
