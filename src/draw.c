/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvicino <lvicino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:35:43 by lvicino           #+#    #+#             */
/*   Updated: 2024/06/04 14:00:15 by lvicino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_sprite(t_image asset, t_image *img, int x, int y)
{
	unsigned char	*dst;
	unsigned int	color;
	int				i;
	int				j;

	i = -1;
	while (++i < asset.width)
	{
		j = -1;
		while (++j < asset.height)
		{
			color = ((int *)asset.p_addr)[j * asset.width + i];
			if (color == 0xFF00FF)
				continue ;
			dst = img->p_addr + ((y + j) * img->line_length + (x + i) \
			* (img->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
		}
	}
	return (1);
}

void	draw_enemy(t_sl *data)
{
	int	n;

	n = -1;
	while (++n < data->e_nb)
	{
		if (data->enemy[n].dir == 0 && data->map[data->enemy[n].loc[1] / \
		40][(data->enemy[n].loc[0] - 1) / 40] == '1')
			data->enemy[n].dir = 1;
		else if (data->enemy[n].dir == 1 && data->map[data->enemy[n].loc[1] / \
		40][(data->enemy[n].loc[0] + 20) / 40] == '1')
			data->enemy[n].dir = 0;
		if (data->enemy[n].dir == 0)
			data->enemy[n].loc[0] -= 1;
		else if (data->enemy[n].dir == 1)
			data->enemy[n].loc[0] += 1;
		draw_sprite(data->e_assets[data->enemy[n].dir], &data->img_dup, \
		data->enemy[n].loc[0], data->enemy[n].loc[1]);
	}
}

void	draw_player(t_sl *data)
{
	static int	i;
	int			d;

	d = 0;
	if (data->player.left)
		d = 2;
	else if (data->player.right)
		d = 4;
	if (i > 10)
	{
		draw_sprite(data->p_assets[0 + d], &data->img_dup, \
		data->player.loc[0], data->player.loc[1]);
	}
	else
		draw_sprite(data->p_assets[1 + d], &data->img_dup, \
		data->player.loc[0], data->player.loc[1]);
	i = (i + 1) % 20;
}

void	draw_static(t_sl *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			draw_sprite(data->tiles[1], &data->img, \
			data->tiles[0].width * x, data->tiles[0].height * y);
			if (data->map[y][x] == '1')
				draw_sprite(data->tiles[0], &data->img, \
				data->tiles[0].width * x, data->tiles[0].height * y);
			else if (data->map[y][x] == 'C')
				draw_sprite(data->tiles[2], &data->img, \
				data->tiles[0].width * x + 14, data->tiles[0].height * y + 12);
			else if (data->map[y][x] == 'E')
				draw_sprite(data->tiles[3], &data->img, \
				data->tiles[0].width * x + 8, data->tiles[0].height * y + 6);
		}
	}
}

int	draw(t_sl *data)
{
	static int	i;

	if (!i)
	{
		data->img_dup.p_addr = ft_memcpy(data->img_dup.p_addr, \
		data->img.p_addr, data->img.line_length * data->w_height);
		check_move(data);
		steps(data);
		draw_player(data);
		draw_enemy(data);
		get_coin(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img_dup.img, 0, 0);
		check_lose(data);
		check_win(data);
	}
	i = (i + 1) % 3000;
	return (0);
}
