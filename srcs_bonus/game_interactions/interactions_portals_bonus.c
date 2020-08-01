/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions_portals_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:48:24 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:34 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_hud_bonus.h"
#include "cub_game_bonus.h"

void	check_portal(int x, int y, t_cub *cub)
{
	char	cell;
	int		new_x;
	int		new_y;

	new_x = 0;
	new_y = 0;
	cell = get_cell_map(x, y, cub);
	if (!is_cell_portal(cell))
	{
		cub->hud->teleported = 0;
		return ;
	}
	if (!cub->hud->teleported && is_cell_portal(cell))
	{
		cub->hud->teleported = 1;
		map_find_portal(cell, &new_x, &new_y, cub);
		if (new_x == x && new_y == y)
			map_find_portal(cell, &new_x, &new_y, cub);
		cub->cam->x = cub->map->blk_x * new_x + (float)cub->map->blk_x / 2;
		cub->cam->y = cub->map->blk_y * new_y + (float)cub->map->blk_y / 2;
		select_world(cell, cub);
	}
}

void	select_world(char cell, t_cub *cub)
{
	if (cell == 'e')
		cub->hud->world ^= WORLD_RICK;
	if (cell == 'c')
		cub->hud->world ^= WORLD_LUDO;
}

/*
**	Finds occurrence of cell different from x_st:y_st in map. New occurrence
**	writes into x_st:y_st. (Only 2 connected portals cam be).
*/

void	map_find_portal(char cell, int *x_st, int *y_st, t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	while (cub->map->field[++y])
	{
		x = -1;
		while (cub->map->field[y][++x])
		{
			if (cell == cub->map->field[y][x] && !(x == *x_st && y == *y_st))
			{
				*x_st = x;
				*y_st = y;
				return ;
			}
		}
	}
}
