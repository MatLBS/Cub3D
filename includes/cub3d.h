/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:50:09 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/18 14:14:57 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "/home/matle-br/sgoinfre/minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define WIDTH 800
# define HEIGHT 800
# define WIDTH_XPM 100
# define HEIGHT_XPM 100
# define MOVE_SPEED 0.1
# define TURN_SPEED 0.05

/* ----------- Définition de mes images -------------*/

# define BACKGROUND 0
# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4

/*---------------------------------------------------*/

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

typedef struct s_wall
{
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	long	color;
	int		side;
	int		width_xpm;
	int		height_xpm;
	int		face;
}	t_wall;

typedef struct s_player
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	planex;
	double	planey;
	double	camerax;
	double	raydirx;
	double	raydiry;
}	t_player;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}	t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			fd;
	char		*str;
	int			width;
	int			height;
	t_player	*player;
	t_map		*map;
	t_wall		*wall;
	t_img		tab_img[5];
}	t_data;

/* events.c */
void		move_forward(t_data *data);
void		move_backwards(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);
int			key_handler(int key, t_data *data);

/* events2.c */
void		turn_left(t_data *data);
void		turn_right(t_data *data);
int			c_handler(t_data *data);

/* init.c */
t_wall		*init_wall(t_data *data);
void		init_imgs(t_img *tab_img);
void		init_data(t_data *data);
void		init_mlx(t_data *data);

/* init2.c */
t_map		*init_map(void);
t_player	*init_player(t_data *data);

/* free.c */
void		ft_free_cub(char **tab);
void		ft_free_images(t_data *data);
void		ft_free_data(t_data *data);

/* get_next_line.c */
char		*fill_stash(int fd, char *stash);
char		*fill_line(char *stash);
char		*clean_stash(char *stash);
char		*get_next_line(int fd, int flag);

/* images.c */
void		generate_background(t_img *img, t_data *data);
void		create_img(t_img *img, t_data *data, char *pathfile);
void		create_imgs(t_data *data);

/* check_input.c */
void		check_av1(char	**av, t_data *data);
void		parse_map(t_data *data);
void		parse_args(t_data *data);
void		remove_endl(char *str);
int			check_input(char **av, t_data *data);

/* check_map.c */
int			check_space(t_data *data, char **tab, int i, int j);
int			check_line(char *str, t_data *data, int y);
int			check_first_line(char **tab, t_data *data, int i);
int			check_last_line(char **tab, t_data *data, int i);
int			check_map(t_data *data);

/* parsing_utils.c */
int			ft_isspace(char *str);
char		*check_xpm(t_data *data, int i);
int			check_whitespace(char *str);
int			check_rgb(t_data *data, int i);

/* parsing_utils2.c */
void		ft_strcpy_cub(char *dest, char *src, int size, int j);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int			check_rgb_suite(char **tab, t_data *data, char *new_str);
int			check_number(char *str);
int			check_sides(char *str, t_data *data);

/* raycasting.c */
void		algo_dda_suite(t_data *data, int hit);
void		algo_dda(t_data *data);
void		display_wall(t_data *data, int x);
void		launch_rays(t_data *data);
void		raycasting(t_data *data);

/* raycasting_utils.c */
void		which_fov(t_data *data);
void		which_position(t_data *data);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		my_mlx_pixel_put_data(t_data *data, int x, int y, int color);

/* raycasting_utils2.c */
int			get_pixel_color(t_img *img, int pixelX, int pixelY, t_data *data);
void		get_texture_color(t_data *data, int pixelX);


#endif
