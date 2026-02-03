/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvicino <lvicino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:07:57 by lvicino           #+#    #+#             */
/*   Updated: 2024/06/04 14:12:17 by lvicino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_num(t_sl *data, int i)
{
	while (--i >= 0)
		mlx_destroy_image(data->mlx, data->num[i].img);
}

int	init_num_aux(t_sl *data, char *path, int i)
{
	data->num[i].img = mlx_xpm_file_to_image(data->mlx, \
	path, &data->num[i].width, &data->num[i].height);
	if (!data->num[i].img)
		return (destroy_enemy(data, 2), destroy_tiles(data, 5), \
		destroy_player(data, 6), destroy_num(data, i), 0);
	data->num[i].p_addr = (unsigned char *)mlx_get_data_addr(\
	data->num[i].img, &data->num[i].bits_per_pixel, \
	&data->num[i].line_length, &data->num[i].endian);
	return (1);
}

int	init_num(t_sl *data)
{
	const char	*num[] = {N0, N1, N2, N3, N4, N5, N6, N7, N8, N9};
	int			i;

	i = -1;
	while (++i < 10)
	{
		if (!init_num_aux(data, (char *)num[i], i))
			return (0);
	}
	return (1);
}
