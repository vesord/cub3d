/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:05:15 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:34 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_game_bonus.h"
#include "cub_hud_bonus.h"
#include "cub_textures_bonus.h"

void	update_hud(t_cub *cub)
{
	if (cub->hud->hp <= 0)
		cub->hud->status = GAME_STATUS_DIE;
	add_hud_face(cub);
	add_hud_wand(cub);
	add_hud_hp(cub);
	add_hud_shooting(cub);
	if (cub->hud->jumping)
		process_jumping(cub);
}

void	add_hud_face(t_cub *cub)
{
	if (!cub->hud->need_update_face)
		return ;
	put_tex_to_img(cub->hud->tx_face, cub->frm_0, HUD_TRANSP_MASK);
	put_tex_to_img(cub->hud->tx_face, cub->frm_1, HUD_TRANSP_MASK);
	cub->hud->need_update_face = 0;
}

void	add_hud_wand(t_cub *cub)
{
	if (!cub->hud->need_update_weap)
		return ;
	put_tex_to_img(cub->hud->tx_wand, cub->frm_0, HUD_TRANSP_MASK);
	put_tex_to_img(cub->hud->tx_wand, cub->frm_1, HUD_TRANSP_MASK);
	cub->hud->need_update_weap = 0;
}

void	process_jumping(t_cub *cub)
{
	static int jump_status = -36;
	static int jump_max = 36;

	cub->cam->z = ((float)cub->map->blk_z / 2) +
		((float)jump_max - (float)abs(jump_status)) / 2.f;
	jump_status += (int)sqrtf((float)abs(jump_status));
	if (jump_status == 0)
		jump_status = 1;
	if (jump_status > jump_max)
	{
		jump_status = -jump_max;
		cub->hud->jumping = 0;
	}
}
