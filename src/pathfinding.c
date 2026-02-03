/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvicino <lvicino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:04:26 by lvicino           #+#    #+#             */
/*   Updated: 2024/06/03 15:09:48 by lvicino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_spawn(t_sl *data)
{
	data->player.y = 1;
	while (data->map && data->map[data->y_max - (data->player.y + 1)])
	{
		data->player.x = 1;
		while (data->map[data->y_max - data->player.y][data->player.x + 1])
		{
			if (data->map[data->y_max - data->player.y][data->player.x] == 'P')
				return ;
			data->player.x++;
		}
		data->player.y++;
	}
}

int	path_found(char **map, int *x, int *y, t_sl *data)
{
	*y = 0;
	while (++(*y) && map[*y + 1])
	{
		*x = 0;
		while (++(*x) && map[*y][(*x) + 1])
		{
			if (map[data->y_max - (*y)][*x] == 'X' && (\
			(map[data->y_max - (*y)][(*x) - 1] != '1' && \
			map[data->y_max - (*y)][(*x) - 1] != 'M' && \
			map[data->y_max - (*y)][(*x) - 1] != 'X') || \
			(map[data->y_max - (*y)][(*x) + 1] != '1' && \
			map[data->y_max - (*y)][(*x) + 1] != 'M' && \
			map[data->y_max - (*y)][(*x) + 1] != 'X') || \
			(map[data->y_max - (*y) - 1][*x] != '1' && \
			map[data->y_max - (*y) - 1][*x] != 'M' && \
			map[data->y_max - (*y) - 1][*x] != 'X') || \
			(map[data->y_max - (*y) + 1][*x] != '1' && \
			map[data->y_max - (*y) + 1][*x] != 'M' && \
			map[data->y_max - (*y) + 1][*x] != 'X')))
				return (1);
		}
	}
	return (0);
}

void	cross_path(t_sl *data, int x, int y, char **map)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = x;
	tmp_y = y;
	while (++x && map[data->y_max - y][x] != '1' && \
	map[data->y_max - y][x] != 'M')
		map[data->y_max - y][x] = 'X';
	x = tmp_x;
	while (--x > 0 && map[data->y_max - y][x] != '1' && \
	map[data->y_max - y][x] != 'M')
		map[data->y_max - y][x] = 'X';
	x = tmp_x;
	while (++y && map[data->y_max - y][x] != '1' && \
	map[data->y_max - y][x] != 'M')
		map[data->y_max - y][x] = 'X';
	y = tmp_y;
	while (--y > 0 && map[data->y_max - y][x] != '1' && \
	map[data->y_max - y][x] != 'M')
		map[data->y_max - y][x] = 'X';
	y = tmp_y;
}

int	pathfinder(t_sl *data, char **map)
{
	int	x;
	int	y;

	x = data->player.x;
	y = data->player.y;
	while (path_found(map, &x, &y, data))
		cross_path(data, x, y, map);
	y = 0;
	while (map[++y + 1])
	{
		x = 0;
		while (map[y][++x + 1])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
			{
				return (ft_free(&map), write(2, "Error\n", 6), \
				write(2, PATH_ER, 30), 0);
			}
		}
	}
	return (ft_free(&map), 1);
}

int	check_path(t_sl *data)
{
	char	**map;

	find_spawn(data);
	map = ft_split(data->seed, '\n');
	if (!map)
		return (0);
	map[data->y_max - data->player.y][data->player.x] = 'X';
	return (pathfinder(data, map));
}
