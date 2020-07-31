/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 22:20:05 by matrus            #+#    #+#             */
/*   Updated: 2020/07/27 22:20:06 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_game.h"

void	get_player_pos(int *x, int *y, t_cub *cub);
void	check_trap(int x, int y, t_cub *cub);
void	check_life(int x, int y, t_cub *cub);
void	check_portal(int x, int y, t_cub *cub);
void	check_wand(int x, int y, t_cub *cub);

void	check_interactions(t_cub *cub)
{
//	static int prev_x;
//	static int prev_y;
	int	cur_x;
	int	cur_y;

	cur_x = 0;
	cur_y = 0;
	get_player_pos(&cur_x, &cur_y, cub);
	if (!cub->hud->jumping)
		check_trap(cur_x, cur_y, cub);
	check_portal(cur_x, cur_y, cub);
	check_life(cur_x, cur_y, cub);
	check_wand(cur_x, cur_y, cub);
//	if (prev_x != cur_x)
//		prev_x = cur_x;
//	if (prev_y != cur_y)
//		prev_y = cur_y;
}

void	check_wand(int x, int y, t_cub *cub)
{
	char cell;

	cell = get_cell_map(x, y, cub);
	if (cell != 'w')
		return ;
	cub->map->field[y][x] = '0';
	cub->hud->has_wand = 1;
	cub->hud->need_update_weap = 1;
}

void	map_find_portal(char cell, int *x_st, int *y_st, t_cub *cub);


void	select_world(char cell, t_cub *cub);

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
				return;
			}
		}
	}
}

void	check_life(int x, int y, t_cub *cub)
{
	if (cub->hud->hp >= 3 || get_cell_map(x, y, cub) != '$')
		return ;
	cub->hud->hp++;
	cub->hud->need_update_face = 1;
	cub->hud->need_update_hp = 1;
	(cub->map->field)[y][x] = '0';
}

void	check_trap(int x, int y, t_cub *cub)
{
	if (get_cell_map(x, y, cub) != '*')
		return ;
	cub->hud->hp--;
	cub->hud->need_update_face = 1;
	cub->hud->need_update_hp = 1;
	(cub->map->field)[y][x] = '0';
}

void	get_player_pos(int *x, int *y, t_cub *cub)
{
	float f_x;
	float f_y;

	modff(cub->cam->x / cub->map->blk_x, &f_x);
	modff(cub->cam->y / cub->map->blk_x, &f_y);
	*x = (int)f_x;
	*y = (int)f_y;
}
