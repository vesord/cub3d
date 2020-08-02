/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_shooting_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 14:57:07 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:34 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "includes/cub_game_bonus.h"
#include "includes/cub_hud_bonus.h"
#include "includes/cub_textures_bonus.h"

void	add_hud_shooting(t_cub *cub)
{
	if (!cub->hud->shooting || !cub->hud->has_wand)
		return ;
	draw_rainbow_blast(cub);
}

void	draw_rainbow_blast(t_cub *cub)
{
	static int			shout_status;
	static t_win_blk	rb_blk;

	if (!rb_blk.x_end && !rb_blk.y_end)
		win_blk_rb_init(&rb_blk, cub);
	if (cub->hud->shooting == 1)
		put_img_in_win_blk(&rb_blk,
					*(&(cub->tex->tx_anim->wand_1) + shout_status), cub);
	else
		erase_img_in_win_blk(&rb_blk,
					*(&(cub->tex->tx_anim->wand_1) + shout_status), cub);
	shout_status++;
	if (shout_status == 7)
	{
		cub->hud->shooting++;
		shout_status = 0;
	}
	if (cub->hud->shooting == 3)
	{
		check_enemies(cub);
		cub->hud->shooting = 0;
	}
}

void	win_blk_rb_init(t_win_blk *blk, t_cub *cub)
{
	static float off_x = 0.5f;
	static float off_y = 0.45f;
	static float size_x = 0.205f;
	static float size_y = 0.4f;

	blk->x_start = (int)((float)cub->win->x * off_x);
	blk->y_start = (int)((float)cub->win->y * off_y);
	blk->x_end = (int)((float)cub->win->x * (off_x + size_x));
	blk->y_end = (int)((float)cub->win->y * (off_y + size_y));
}

void	check_enemies(t_cub *cub)
{
	int x;
	int y;

	throw_ray(cub, cub->cam->cam_direction_yaw, cub->cam->cam_direction_yaw);
	x = cub->ray->enemy.x;
	y = cub->ray->enemy.y;
	if (cub->ray->enemy.type && cub->ray->enemy.dst <
		cub->map->blk_x * ENEMY_KILL_DST)
	{
		if (cub->ray->enemy.type == 'L')
			cub->hud->status = GAME_STATUS_WIN;
		(cub->map->field)[y][x] = ft_tolower((cub->map->field)[y][x]);
	}
}
