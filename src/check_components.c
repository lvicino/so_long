/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvicino <lvicino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:34:06 by lvicino           #+#    #+#             */
/*   Updated: 2024/06/04 14:51:16 by lvicino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_components(int *c_count)
{
	if (c_count[0] < 1)
		return (write(2, "Error\n", 6), write(2, COLLECTIBLE_ER, 40), 0);
	else if (c_count[1] != 1)
		return (write(2, "Error\n", 6), write(2, EXIT_ER, 24), 0);
	else if (c_count[2] != 1)
		return (write(2, "Error\n", 6), write(2, SPAWN_ER, 37), 0);
	return (1);
}

int	check_components(char *str)
{
	const char	components[] = {"CEPM01\n"};
	int			c_count[3];
	int			i;
	int			j;

	i = -1;
	while (++i < 3)
		c_count[i] = 0;
	i = -1;
	while (str && str[++i])
	{
		j = -1;
		while (components[++j])
		{
			if (str[i] == components[j])
			{
				if (j < 3)
					c_count[j]++;
				break ;
			}
			else if (!components[j + 1])
				return (write(2, "Error\n", 6), write(2, COMP_ER, 55), 0);
		}
	}
	return (count_components(c_count));
}
