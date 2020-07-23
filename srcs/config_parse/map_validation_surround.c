/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_surround.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:44:24 by matrus            #+#    #+#             */
/*   Updated: 2020/07/23 12:44:25 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_map_surrounded(t_cub *cub)
{
	int x_start;
	int y_start;

	x_start = 0;
	y_start = 0;
	is_map_surrounded_set(&x_start, &y_start, cub);
	if (!is_map_surrounded_recursive(x_start, y_start, cub))
		return (0);
	is_map_surrounded_recover(cub);
	return (1);
}

void	is_map_surrounded_set(int *x_start, int *y_start, t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (cub->map->field[i])
	{
		j = 0;
		while (cub->map->field[i][j])
		{
			if (ft_strchr("WESN", cub->map->field[i][j]))
			{
				map_set_player(j, i, cub);
				//cub->map->field[i][j] = -cub->map->field[i][j];
				*x_start = j;
				*y_start = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int		is_map_surrounded_recursive(int x, int y, t_cub *cub)
{
	int f;

	f = 0;
	if (cub->map->field[y][x] == '1' || cub->map->field[y][x] < 0)
		return (1);
	if (cub->map->field[y][x] == ' ')
		return (0);
	if (x < 1 || y < 1 || x + 1 >= cub->map->max_x || y + 1 >= cub->map->max_y)
		return (0);
	cub->map->field[y][x] = -cub->map->field[y][x];
	f = is_map_surrounded_recursive(x, y + 1, cub) &&
		is_map_surrounded_recursive(x + 1, y, cub) &&
		is_map_surrounded_recursive(x, y - 1, cub) &&
		is_map_surrounded_recursive(x - 1, y, cub);
	return (f);
}

void	is_map_surrounded_recover(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (cub->map->field[i])
	{
		j = 0;
		while (cub->map->field[i][j])
		{
			if (cub->map->field[i][j] < 0)
				cub->map->field[i][j] = -cub->map->field[i][j];
			j++;
		}
		i++;
	}
}
