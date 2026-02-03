/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvicino <lvicino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:45:00 by lvicino           #+#    #+#             */
/*   Updated: 2024/06/04 14:18:30 by lvicino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char ***str)
{
	int	i;

	i = 0;
	while ((*str) && (*str)[i])
	{
		free((*str)[i]);
		i++;
	}
	if (*str)
		free(*str);
	*str = NULL;
}

void	destroy_enemy(t_sl *data, int i)
{
	while (--i >= 0)
		mlx_destroy_image(data->mlx, data->e_assets[i].img);
}

void	destroy_tiles(t_sl *data, int i)
{
	while (--i >= 0)
		mlx_destroy_image(data->mlx, data->tiles[i].img);
}

void	destroy_player(t_sl *data, int i)
{
	while (--i >= 0)
		mlx_destroy_image(data->mlx, data->p_assets[i].img);
}

int	destroy(t_sl *data)
{
	destroy_enemy(data, 2);
	destroy_tiles(data, 5);
	destroy_player(data, 6);
	destroy_num(data, 10);
	free(data->enemy);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_image(data->mlx, data->img_dup.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	return (free(data->seed), ft_free(&data->map), free(data->mlx), exit(0), 0);
}
