/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvicino <lvicino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:15:23 by lvicino           #+#    #+#             */
/*   Updated: 2024/06/04 14:10:06 by lvicino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_numbers(t_sl *data, char *str, int ln, int i)
{
	while (++i < ln)
	{
		draw_sprite(data->num[(int)(str[i] - '0')], &data->img_dup, \
			10 + (15 * i), 10);
	}
}

void	steps(t_sl *data)
{
	int		i;
	int		ln;
	char	*str;

	str = ft_itoa(data->steps);
	if (!str)
		destroy(data);
	ln = ft_strlen(str);
	i = -1;
	if (7 > ln)
		draw_numbers(data, str, ln, i);
	else
	{
		while (data->x_max + 1 < ln && ++i < ln - 1)
		{
			draw_sprite(data->num[9], &data->img_dup, \
			10 + (15 * i), 10);
		}
	}
	free(str);
}
