/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvicino <lvicino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:15:17 by lvicino           #+#    #+#             */
/*   Updated: 2024/06/04 13:30:58 by lvicino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_sl *data, int speed)
{
	if (data->map[(data->player.loc[1] - 1) / 40][data->player.loc[0] / 40] \
	!= '1' && data->map[(data->player.loc[1] - 1) / \
	40][(data->player.loc[0] + 9) / 40] != '1')
	{
		data->player.loc[1] -= speed;
		if (data->steps < 1000000)
			data->steps++;
	}
}

void	move_left(t_sl *data, int speed)
{
	if (data->map[data->player.loc[1] / 40][(data->player.loc[0] - 1) / 40] \
	!= '1' && data->map[(data->player.loc[1] + 19) / \
	40][(data->player.loc[0] - 1) / 40] != '1')
	{
		data->player.loc[0] -= speed;
		if (data->steps < 1000000)
			data->steps++;
	}
}

void	move_down(t_sl *data, int speed)
{
	if (data->map[(data->player.loc[1] + 20) / 40][data->player.loc[0] / 40] \
	!= '1' && data->map[(data->player.loc[1] + 20) / \
	40][(data->player.loc[0] + 9) / 40] != '1')
	{
		data->player.loc[1] += speed;
		if (data->steps < 1000000)
			data->steps++;
	}
}

void	move_right(t_sl *data, int speed)
{
	if (data->map[data->player.loc[1] / 40][(data->player.loc[0] + 10) / 40] \
	!= '1' && data->map[(data->player.loc[1] + 19) / \
	40][(data->player.loc[0] + 10) / 40] != '1')
	{
		data->player.loc[0] += speed;
		if (data->steps < 1000000)
			data->steps++;
	}
}

int	check_move(t_sl *data)
{
	if (data->player.up == 1 && data->player.left == 1)
		(move_up(data, 2), move_left(data, 2));
	else if (data->player.up == 1 && data->player.right == 1)
		(move_up(data, 2), move_right(data, 2));
	else if (data->player.down == 1 && data->player.left == 1)
		(move_down(data, 2), move_left(data, 2));
	else if (data->player.down == 1 && data->player.right == 1)
		(move_down(data, 2), move_right(data, 2));
	else if (data->player.up == 1)
		move_up(data, 2);
	else if (data->player.down == 1)
		move_down(data, 2);
	else if (data->player.left == 1)
		move_left(data, 2);
	else if (data->player.right == 1)
		move_right(data, 2);
	return (0);
}
