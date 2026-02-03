/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvicino <lvicino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:16:08 by lvicino           #+#    #+#             */
/*   Updated: 2024/06/03 15:25:22 by lvicino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_release(int key, t_sl *data)
{
	if (key == KEY_ESC)
		destroy(data);
	else if (key == KEY_W || key == KEY_ARROW_UP)
		data->player.up = 0;
	else if (key == KEY_A || key == KEY_ARROW_LEFT)
		data->player.left = 0;
	else if (key == KEY_S || key == KEY_ARROW_DOWN)
		data->player.down = 0;
	else if (key == KEY_D || key == KEY_ARROW_RIGHT)
		data->player.right = 0;
	return (0);
}

int	key_press(int key, t_sl *data)
{
	if (key == KEY_ESC)
		destroy(data);
	else if (key == KEY_W || key == KEY_ARROW_UP || key == XK_W)
	{
		data->player.down = 0;
		data->player.up = 1;
	}
	else if (key == KEY_A || key == KEY_ARROW_LEFT)
	{
		data->player.right = 0;
		data->player.left = 1;
	}
	else if (key == KEY_S || key == KEY_ARROW_DOWN)
	{
		data->player.up = 0;
		data->player.down = 1;
	}
	else if (key == KEY_D || key == KEY_ARROW_RIGHT)
	{
		data->player.left = 0;
		data->player.right = 1;
	}
	return (0);
}
