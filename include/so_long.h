/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvicino <lvicino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:07:08 by lvicino           #+#    #+#             */
/*   Updated: 2024/06/04 14:12:42 by lvicino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/ap_keysym.h>

# include <mlx.h>
# include <mlx_int.h>

# include "libft.h"

/*Data struct*/
typedef struct s_image
{
	void			*img;
	unsigned char	*p_addr;
	int				line_length;
	int				bits_per_pixel;
	int				endian;
	int				height;
	int				width;
}					t_image;

typedef struct s_player
{
	int	x;
	int	y;
	int	loc[2];
	int	up;
	int	left;
	int	down;
	int	right;
}		t_player;

typedef struct s_enemy
{
	int	dir;
	int	loc[2];
}		t_enemy;

typedef struct s_exit
{
	int	open;
	int	x;
	int	y;
}		t_exit;

typedef struct s_sl
{
	char		**map;
	char		*seed;
	int			x_max;
	int			y_max;
	int			c_nb;
	int			e_nb;
	int			steps;
	t_exit		exit;
	void		*mlx;
	void		*win;
	t_image		img;
	t_image		img_dup;
	int			w_height;
	int			w_width;
	t_image		tiles[5];
	t_image		num[10];
	t_player	player;
	t_image		p_assets[6];
	t_enemy		*enemy;
	t_image		e_assets[2];
}				t_sl;

/*Map errors*/
# define BER_ER "Map description file needs to end with the '.ber' extension\n"
# define SHAPE_ER "Map needs to be rectangular\n"
# define WALL_ER "Map must be surrounded by walls\n"
# define COMP_ER "Map can be composed of only these 6 characters: 01CEPM\n"
# define COLLECTIBLE_ER "Map must contain at least 1 collectible\n"
# define EXIT_ER "Map must contain 1 exit\n"
# define SPAWN_ER "Map must contain 1 starting position\n"
# define PATH_ER "Map is impossible to complete\n"
# define SIZE_ER "Map max size is 48x27\n"

/*keys*/
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ARROW_UP 65362
# define KEY_ARROW_LEFT 65361
# define KEY_ARROW_DOWN 65364
# define KEY_ARROW_RIGHT 65363

/*tiles*/
# define WALL "assets/wall.xpm"
# define BG "assets/background.xpm"
# define COIN "assets/coin.xpm"
# define C_EXIT "assets/closed_exit.xpm"
# define O_EXIT "assets/open_exit.xpm"
/*player assets*/
# define PI_1 "assets/p_idle_1.xpm"
# define PI_2 "assets/p_idle_2.xpm"
# define PW_L1 "assets/p_walk_l_1.xpm"
# define PW_L2 "assets/p_walk_l_2.xpm"
# define PW_R1 "assets/p_walk_r_1.xpm"
# define PW_R2 "assets/p_walk_r_2.xpm"
/*enemy assets*/
# define EW_L "assets/e_walk_l.xpm"
# define EW_R "assets/e_walk_r.xpm"

/*numbers*/
# define N0 "assets/n0.xpm"
# define N1 "assets/n1.xpm"
# define N2 "assets/n2.xpm"
# define N3 "assets/n3.xpm"
# define N4 "assets/n4.xpm"
# define N5 "assets/n5.xpm"
# define N6 "assets/n6.xpm"
# define N7 "assets/n7.xpm"
# define N8 "assets/n8.xpm"
# define N9 "assets/n9.xpm"

/*Map errors fonctions*/
int		check_map(char *map_file, t_sl *data);
int		check_components(char *str);
int		check_path(t_sl *data);

/*game fonctions*/
int		key_press(int key1, t_sl *data);
int		key_release(int key, t_sl *data);
int		check_move(t_sl *data);
void	steps(t_sl *data);
void	get_coin(t_sl *data);
void	check_win(t_sl *data);
void	check_lose(t_sl *data);

/*image*/
int		init_image(t_sl *data);
int		init_num(t_sl *data);
int		init_enemy(t_sl *data);

/*draw img*/
int		draw_sprite(t_image asset, t_image *img, int x, int y);
void	draw_static(t_sl *data);
int		draw(t_sl *data);

/*utils*/
void	ft_free(char ***str);
int		destroy(t_sl *data);
void	destroy_enemy(t_sl *data, int i);
void	destroy_tiles(t_sl *data, int i);
void	destroy_player(t_sl *data, int i);
void	destroy_num(t_sl *data, int i);

#endif
