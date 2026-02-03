/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvicino <lvicino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:58:46 by lvicino           #+#    #+#             */
/*   Updated: 2024/06/04 14:51:10 by lvicino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_dot_ber(char *map_file)
{
	char	*str;

	str = ft_strrchr(map_file, '.');
	if (!str || ft_strncmp(str, ".ber", 5))
		return (write(2, "Error\n", 6), write(2, BER_ER, 60), 0);
	return (1);
}

int	get_seed(t_sl *data, char *str)
{
	char		*tmp;

	data->y_max++;
	tmp = data->seed;
	data->seed = ft_strjoin(data->seed, str);
	free(tmp);
	if (!data->seed)
		return (0);
	return (1);
}

int	is_rectangular(int fd, t_sl *data)
{
	char	*str;

	str = get_next_line(fd);
	data->x_max = ft_strlen(str) - 2;
	data->y_max = 0;
	if (data->x_max >= 0)
		data->seed = ft_strdup(str);
	while (str)
	{
		if (data->x_max != (int)(ft_strlen(str) - 2))
		{
			free(str);
			return (close(fd), write(2, "Error\n", 6), \
			write(2, SHAPE_ER, 28), 0);
		}
		free(str);
		str = get_next_line(fd);
		if (data->seed && str && !get_seed(data, str))
			return (close(fd), free(str), 0);
	}
	data->map = ft_split(data->seed, '\n');
	return (close(fd), 1);
}

int	is_closed(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (((!i || !map[i + 1]) && map[i][j] != '1') || \
			(i && map[i + 1] && (!j || !map[i][j + 1]) && map[i][j] != '1'))
				return (write(2, "Error\n", 6), write(2, WALL_ER, 32), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(char *map_file, t_sl *data)
{
	int	fd;

	data->seed = NULL;
	data->map = NULL;
	if (!is_dot_ber(map_file))
		return (0);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (perror(map_file), 0);
	if (!is_rectangular(fd, data) || !is_closed(data->map) || \
	!check_components(data->seed) || !check_path(data))
		return (0);
	if (data->x_max > 48 || data->y_max > 27)
		return (write(2, "Error\n", 6), write(2, SIZE_ER, 22), 0);
	return (1);
}
