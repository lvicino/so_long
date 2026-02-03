/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvicino <lvicino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:13:08 by lvicino           #+#    #+#             */
/*   Updated: 2024/06/03 18:07:29 by lvicino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_lose(t_sl *data)
{
	int	i;

	i = -1;
	while (++i < data->e_nb)
	{
		if (data->player.loc[0] >= data->enemy[i].loc[0] - 10 \
		&& data->player.loc[0] <= data->enemy[i].loc[0] + 19 \
		&& data->player.loc[1] >= data->enemy[i].loc[1] - 19 \
		&& data->player.loc[1] <= data->enemy[i].loc[1] + 19)
			(ft_printf("You Lose !\n"), destroy(data));
	}
}

void	check_win(t_sl *data)
{
	if (!data->exit.open && !data->c_nb)
	{
		draw_sprite(data->tiles[4], &data->img, data->tiles[0].width * \
		data->exit.x + 8, data->tiles[0].height * data->exit.y + 6);
		data->exit.open = 1;
	}
	if (data->exit.open && \
	data->map[data->player.loc[1] / 40][data->player.loc[0] / 40] == 'E' \
	&& (data->player.loc[1] % 40 >= 12 && data->player.loc[1] % 40 <= 28) && \
	(data->player.loc[0] % 40 >= 6 && data->player.loc[0] % 40 <= 24))
		(ft_printf("You Win !\n"), destroy(data));
}
