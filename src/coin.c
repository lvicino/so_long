/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvicino <lvicino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:16:27 by lvicino           #+#    #+#             */
/*   Updated: 2024/06/03 16:42:12 by lvicino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_coin_up(t_sl *data)
{
	if (data->map[data->player.loc[1] / 40][data->player.loc[0] / 40] == 'C' \
	&& (data->player.loc[1] % 40 >= 0 && data->player.loc[1] % 40 <= 28) && \
	(data->player.loc[0] % 40 >= 4 && data->player.loc[0] % 40 <= 26))
	{
		data->map[(data->player.loc[1]) / 40][(data->player.loc[0]) / 40] = '0';
		draw_sprite(data->tiles[1], &data->img, data->tiles[0].width * \
		(data->player.loc[0] / 40), data->tiles[0].height * \
		((data->player.loc[1]) / 40));
		data->c_nb--;
	}
}

void	check_coin_down(t_sl *data)
{
	if (data->map[data->player.loc[1] / 40][data->player.loc[0] / 40] == 'C' \
	&& (data->player.loc[1] % 40 >= 0 && data->player.loc[1] % 40 <= 28) && \
	(data->player.loc[0] % 40 >= 4 && data->player.loc[0] % 40 <= 26))
	{
		data->map[(data->player.loc[1]) / 40][(data->player.loc[0]) / 40] = '0';
		draw_sprite(data->tiles[1], &data->img, data->tiles[0].width * \
		(data->player.loc[0] / 40), data->tiles[0].height * \
		((data->player.loc[1]) / 40));
		data->c_nb--;
	}
}

void	check_coin_left(t_sl *data)
{
	if (data->map[data->player.loc[1] / 40][data->player.loc[0] / 40] == 'C' \
	&& (data->player.loc[1] % 40 >= 0 && data->player.loc[1] % 40 <= 28) && \
	(data->player.loc[0] % 40 >= 4 && data->player.loc[0] % 40 <= 26))
	{
		data->map[(data->player.loc[1]) / 40][(data->player.loc[0]) / 40] = '0';
		draw_sprite(data->tiles[1], &data->img, data->tiles[0].width * \
		(data->player.loc[0] / 40), data->tiles[0].height * \
		((data->player.loc[1]) / 40));
		data->c_nb--;
	}
}

void	check_coin_right(t_sl *data)
{
	if (data->map[data->player.loc[1] / 40][data->player.loc[0] / 40] == 'C' \
	&& (data->player.loc[1] % 40 >= 0 && data->player.loc[1] % 40 <= 28) && \
	(data->player.loc[0] % 40 >= 4 && data->player.loc[0] % 40 <= 26))
	{
		data->map[(data->player.loc[1]) / 40][(data->player.loc[0]) / 40] = '0';
		draw_sprite(data->tiles[1], &data->img, data->tiles[0].width * \
		(data->player.loc[0] / 40), data->tiles[0].height * \
		((data->player.loc[1]) / 40));
		data->c_nb--;
	}
}

void	get_coin(t_sl *data)
{
	if (data->player.up == 1)
		check_coin_up(data);
	if (data->player.left == 1)
		check_coin_left(data);
	if (data->player.down == 1)
		check_coin_down(data);
	if (data->player.right == 1)
		check_coin_right(data);
}
