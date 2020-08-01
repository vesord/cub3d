/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 22:20:05 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:34 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_game_bonus.h"
#include "cub_hud_bonus.h"

void	check_interactions(t_cub *cub)
{
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
