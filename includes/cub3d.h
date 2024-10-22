/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 08:50:09 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/22 17:12:32 by matle-br         ###   ########.fr       */
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
# include <sys/time.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define WIDTH 800
# define HEIGHT 800
# define WIDTH_XPM 100
# define HEIGHT_XPM 100
# define MOVE_SPEED 0.05
# define TURN_SPEED 0.05
# define SIZE_SQUARE 20
# define WIDTH_MINIMAP 300
# define HEIGHT_MINIMAP 200
# define MOUSE_SENSI 75.0

# define FIRST_SENTENCE "Welcome, this is a manual on how you can play \
with the keyboard!"

# define SECOND_SENTENCE "1 -> First, you can use the W, S, A and D to move the player."

# define THIRD_SENTENCE "2 -> Then, you can use the two arrows <- | -> to move your point of view."

# define FOURTH_SENTENCE "3 -> You can press the buuton 'e' near a door to open/close it."

# define FIFTH_SENTENCE "4 -> You can press 'Ctrl' to move your point of view with the mouse."

# define SIXTH_SENTENCE "5 -> Press again 'Ctrl' to disable this feature."

# define SEVENTH_SENTENCE "Have fun !"

/* ----------- Définition de mes images -------------*/

# define BACKGROUND 0
# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4
# define DOOR 5
# define DOOR_1 6
# define PICTO_W 7
# define PICTO_D 8

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
	char	**cpy_map;
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
	int		hit_door;
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
	int		texx;
	int		texy;
	double	wallx;
	double	texpos;
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

typedef struct s_keys
{
	int	key_w;
	int	key_a;
	int	key_s;
	int	key_d;
	int	left_arrow;
	int	right_arrow;
}	t_keys;

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
	int			mouse;
	long		first_action;
	t_player	*player;
	t_map		*map;
	t_wall		*wall;
	t_keys		*keys;
	t_img		tab_img[9];
}	t_data;

/* events.c */
void		move_forward(t_data *data);
void		move_backwards(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);
int			key_starter(int key, t_data *data);
int			key_closer(int key, t_data *data);
int			check_keys(t_data *data);

/* events2.c */
void		turn_left(t_data *data, double rotation_speed);
void		turn_right(t_data *data, double rotation_speed);
int			c_handler(t_data *data);
int			handle_mouse(int x, int y, t_data *data);

/* init.c */
t_wall		*init_wall(t_data *data);
void		init_imgs(t_img *tab_img);
t_keys		*init_keys(t_data *data);
void		init_data(t_data *data);
void		init_mlx(t_data *data);
long		get_time(void);

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

/* minimap.c */
void		find_pixel(t_data *data, int x, int y);
void		create_minimap(t_data *data);

/* raycasting_utils.c */
void		which_fov(t_data *data);
void		which_position(t_data *data);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		my_mlx_pixel_put_data(t_data *data, int x, int y, int color);
void		create_minimap(t_data *data);

/* raycasting_utils2.c */
int			get_pixel_color(t_img *img, int pixelX, int pixelY, t_data *data);
void		get_texture_color(t_data *data, int pixelX);
int			size_tab(char **tab);


#endif
