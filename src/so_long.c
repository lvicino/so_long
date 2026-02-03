/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvicino <lvicino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:07:21 by lvicino           #+#    #+#             */
/*   Updated: 2024/06/04 14:24:02 by lvicino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_data(t_sl *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'C')
				data->c_nb++;
			else if (data->map[y][x] == 'M')
				data->e_nb++;
			else if (data->map[y][x] == 'E')
			{
				data->exit.x = x;
				data->exit.y = y;
			}
			else if (data->map[y][x] == 'P')
			{
				data->player.loc[0] = x * 40;
				data->player.loc[1] = y * 40 + 20;
			}
		}
	}
}

int	open_window(t_sl *data)
{
	data->w_width = data->tiles[0].width * (data->x_max + 1);
	data->w_height = data->tiles[0].height * (data->y_max + 1);
	data->win = mlx_new_window(data->mlx, data->w_width, data->w_height, \
	"so_long");
	if (!data->win)
		return (destroy_enemy(data, 2), destroy_tiles(data, 5), \
		destroy_player(data, 6), destroy_num(data, 10), free(data->enemy), 0);
	data->img.img = mlx_new_image(data->mlx, data->w_width, data->w_height);
	if (!data->img.img)
		return (destroy_enemy(data, 2), destroy_tiles(data, 5), \
		destroy_player(data, 6), destroy_num(data, 10), free(data->enemy), \
		mlx_destroy_window(data->mlx, data->win), 0);
	data->img.p_addr = (unsigned char *)mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	draw_static(data);
	data->img_dup.img = mlx_new_image(data->mlx, data->w_width, data->w_height);
	if (!data->img_dup.img)
		return (destroy_enemy(data, 2), destroy_tiles(data, 5), \
		destroy_player(data, 6), destroy_num(data, 10), free(data->enemy), \
		mlx_destroy_image(data->mlx, data->img.img), \
		mlx_destroy_window(data->mlx, data->win), 0);
	data->img_dup.p_addr = (unsigned char *)mlx_get_data_addr(\
	data->img_dup.img, &data->img_dup.bits_per_pixel, \
	&data->img_dup.line_length, &data->img_dup.endian);
	return (1);
}

void	so_long(t_sl *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		(free(data->seed), ft_free(&data->map), exit(0));
	get_map_data(data);
	if (init_image(data) && init_num(data) && init_enemy(data) \
	&& open_window(data))
	{
		mlx_hook(data->win, DestroyNotify, StructureNotifyMask, &destroy, data);
		mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
		mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release, data);
		mlx_loop_hook(data->mlx, draw, data);
		mlx_loop(data->mlx);
	}
	else
		(mlx_destroy_display(data->mlx), free(data->mlx));
}

void	init_data(t_sl *data)
{
	data->player.up = 0;
	data->player.left = 0;
	data->player.down = 0;
	data->player.right = 0;
	data->c_nb = 0;
	data->e_nb = 0;
	data->steps = 0;
	data->exit.open = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_sl	data;

	if (!envp[0] || argc != 2)
		return (0);
	if (check_map(argv[1], &data))
	{
		init_data(&data);
		so_long(&data);
	}
	if (data.seed)
		free(data.seed);
	ft_free(&data.map);
	return (0);
}
