/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_surround.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 12:44:24 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 10:14:53 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
**	Checks if there are walls all around locations with portals
**	and player start position.
*/

int		is_map_surrounded(t_cub *cub)
{
	int y;
	int x;

	y = -1;
	is_map_surrounded_set("NWESce", cub);
	while (cub->map->field[++y])
	{
		x = -1;
		while (cub->map->field[y][++x])
		{
			if (cub->map->field[y][x] < 0)
				if (!is_map_surrounded_recursive(x, y, 1, cub)) // TODO: check x and y correction on base lvl
					return (0);
		}
	}
	is_map_surrounded_recover(cub);
	return (1);
}

/*
**	Makes preparation for recursive checking if map surrounded.
**	Any char in map from *starts string makes it negative.
**	Neg cell on map is the marker of recursive search.
*/

void	is_map_surrounded_set(const char *starts,  t_cub *cub)
{
	int y;
	int x;

	y = 0;
	while (cub->map->field[y])
	{
		x = 0;
		while (cub->map->field[y][x])
		{
			if (ft_strchr(starts, cub->map->field[y][x]))
			{
				cub->map->field[y][x] = -cub->map->field[y][x];
			}
			x++;
		}
		y++;
	}
}

int		is_map_surrounded_recursive(int x, int y, int strt, t_cub *cub)
{
	int f;

	f = 0;
	if ((is_cell_wall(cub->map->field[y][x]) || cub->map->field[y][x] < 0) && !strt)
		return (1);
	if (cub->map->field[y][x] == ' ' || !cub->map->field[y][x])
		return (0);
	if (x < 1 || y < 1 || x + 1 >= cub->map->max_x || y + 1 >= cub->map->max_y)
		return (0);
	if (cub->map->field[y][x] > 0)
		cub->map->field[y][x] = -cub->map->field[y][x];
	f = is_map_surrounded_recursive(x, y + 1, 0, cub) &&
		is_map_surrounded_recursive(x + 1, y, 0, cub) &&
		is_map_surrounded_recursive(x, y - 1, 0, cub) &&
		is_map_surrounded_recursive(x - 1, y, 0, cub);
	return (f);
}

void	is_map_surrounded_recover(t_cub *cub)
{
	int y;
	int x;

	y = 0;
	while (cub->map->field[y])
	{
		x = 0;
		while (cub->map->field[y][x])
		{
			if (cub->map->field[y][x] < 0)
				cub->map->field[y][x] = -cub->map->field[y][x];
			x++;
		}
		y++;
	}
}
