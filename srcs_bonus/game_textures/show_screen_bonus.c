/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_screen_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:29:21 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:36 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_game_bonus.h"
#include "cub_textures_bonus.h"

void	set_status_screen(t_cub *cub)
{
	cub_reset_game_status(cub);
	if (cub->hud->status == GAME_STATUS_DIE)
	{
		put_tex_to_img(cub->tex->tx_screens->die, cub->frm_0, 0);
		put_tex_to_img(cub->tex->tx_screens->die, cub->frm_1, 0);
	}
	else if (cub->hud->status == GAME_STATUS_WIN)
	{
		put_tex_to_img(cub->tex->tx_screens->end, cub->frm_0, 0);
		put_tex_to_img(cub->tex->tx_screens->end, cub->frm_1, 0);
	}
}

void	cub_reset_game_status(t_cub *cub)
{
	cub->hud->shooting = 0;
	cub->hud->jumping = 0;
	cub->hud->teleported = 0;
	cub->hud->need_update_face = 0;
	cub->hud->need_update_hp = 0;
	cub->hud->need_update_weap = 0;
}
