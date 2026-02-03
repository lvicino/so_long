/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvicino <lvicino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:46:49 by lvicino           #+#    #+#             */
/*   Updated: 2024/06/03 19:06:12 by lvicino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_enemy_img(t_sl *data, char *path, int i)
{
	data->e_assets[i].img = mlx_xpm_file_to_image(data->mlx, \
	path, &data->e_assets[i].width, &data->e_assets[i].height);
	if (!data->e_assets[i].img)
		return (destroy_enemy(data, i), 0);
	data->e_assets[i].p_addr = (unsigned char *)mlx_get_data_addr(\
	data->e_assets[i].img, &data->e_assets[i].bits_per_pixel, \
	&data->e_assets[i].line_length, &data->e_assets[i].endian);
	return (1);
}

int	init_tiles(t_sl *data, char *path, int i)
{
	data->tiles[i].img = mlx_xpm_file_to_image(data->mlx, \
	path, &data->tiles[i].width, &data->tiles[i].height);
	if (!data->tiles[i].img)
		return (destroy_enemy(data, 2), destroy_tiles(data, i), 0);
	data->tiles[i].p_addr = (unsigned char *)mlx_get_data_addr(\
	data->tiles[i].img, &data->tiles[i].bits_per_pixel, \
	&data->tiles[i].line_length, &data->tiles[i].endian);
	return (1);
}

int	init_player(t_sl *data, char *path, int i)
{
	data->p_assets[i].img = mlx_xpm_file_to_image(data->mlx, \
	path, &data->p_assets[i].width, &data->p_assets[i].height);
	if (!data->p_assets[i].img)
		return (destroy_enemy(data, 2), destroy_tiles(data, 5), \
		destroy_player(data, i), 0);
	data->p_assets[i].p_addr = (unsigned char *)mlx_get_data_addr(\
	data->p_assets[i].img, &data->p_assets[i].bits_per_pixel, \
	&data->p_assets[i].line_length, &data->p_assets[i].endian);
	return (1);
}

int	init_image(t_sl *data)
{
	const char	*tile[] = {WALL, BG, COIN, C_EXIT, O_EXIT};
	const char	*p_asset[] = {PI_1, PI_2, PW_L1, PW_L2, PW_R1, PW_R2};
	const char	*e_asset[] = {EW_L, EW_R};
	int			i;

	i = -1;
	while (++i < 2)
	{
		if (!init_enemy_img(data, (char *)e_asset[i], i))
			return (0);
	}
	i = -1;
	while (++i < 5)
	{
		if (!init_tiles(data, (char *)tile[i], i))
			return (0);
	}
	i = -1;
	while (++i < 6)
	{
		if (!init_player(data, (char *)p_asset[i], i))
			return (0);
	}
	return (1);
}
