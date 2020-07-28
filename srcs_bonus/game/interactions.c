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

void	get_player_pos(int *x, int *y, t_cub *cub);
void	check_trap(int x, int y, t_cub *cub);
void	check_life(int x, int y, t_cub *cub);

void	check_interactions(t_cub *cub)
{
	static int prev_x;
	static int prev_y;
	int	cur_x;
	int	cur_y;

	cur_x = 0;
	cur_y = 0;
	get_player_pos(&cur_x, &cur_y, cub);
	if (!cub->hud->jumping)
		check_trap(cur_x, cur_y, cub);
	check_life(cur_x, cur_y, cub);
	if (prev_x != cur_x)
		prev_x = cur_x;
	if (prev_y != cur_y)
		prev_y = cur_y;
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
