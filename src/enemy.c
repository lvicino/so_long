/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvicino <lvicino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:48:41 by lvicino           #+#    #+#             */
/*   Updated: 2024/05/30 15:21:18 by lvicino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	locate_enemy(t_sl *data)
{
	int	x;
	int	y;
	int	n;

	n = 0;
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'M')
			{
				data->enemy[n].dir = 0;
				data->enemy[n].loc[0] = (x * 40) + 10;
				data->enemy[n].loc[1] = (y * 40) + 10;
				n++;
			}
		}
	}
}

int	init_enemy(t_sl *data)
{
	data->enemy = malloc(sizeof(t_enemy) * data->e_nb);
	if (!data->enemy)
	{
		destroy_enemy(data, 2);
		destroy_tiles(data, 5);
		destroy_player(data, 6);
		return (0);
	}
	locate_enemy(data);
	return (1);
}
