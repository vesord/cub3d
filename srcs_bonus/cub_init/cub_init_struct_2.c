/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_struct_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 09:55:31 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 09:59:38 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	cub_init_map(t_cub *cub)
{
	cub->map->blk_y = 0;
	cub->map->blk_x = 0;
	cub->map->blk_z = 0;
	cub->map->max_x = 0;
	cub->map->max_y = 0;
	if (!(cub->map->field = (char**)malloc(sizeof(char*))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		*(cub->map->field) = NULL;
}

void	cub_init_cam(t_cub *cub)
{
	cub->cam->cam_direction_yaw = 0;
	cub->cam->cam_direction_pitch = 0;
	cub->cam->cam_angle_yaw = 0;
	cub->cam->cam_angle_pitch = 0;
	cub->cam->x = 0;
	cub->cam->y = 0;
	cub->cam->z = 0;
	cub->cam->step = 0;
}

void	cub_init_key(t_cub *cub)
{
	cub->key->w = 0;
	cub->key->a = 0;
	cub->key->s = 0;
	cub->key->d = 0;
	cub->key->l_arrow = 0;
	cub->key->r_arrow = 0;
	cub->key->esc = 0;
	cub->key->action = 0;
	cub->key->jump = 0;
	cub->key->d_arrow = 0;
	cub->key->d_arrow = 0;
}

void	cub_init_hud(t_cub *cub)
{
	cub->hud->need_update_face = 0;
	cub->hud->need_update_weap = 0;
	cub->hud->need_update_hp = 0;
	cub->hud->status = 0;
	cub->hud->hp = 0;
	cub->hud->jumping = 0;
	cub->hud->tx_face = NULL;
	cub->hud->tx_wand = NULL;
	cub->hud->tx_hp = NULL;
	if (!(cub->hud->tx_face = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->hud->tx_face);
	if (!(cub->hud->tx_wand = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->hud->tx_wand);
	if (!(cub->hud->tx_hp = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->hud->tx_hp);
}

void	cub_init_img(t_img *img)
{
	img->width = 0;
	img->height = 0;
	img->btp = 0;
	img->sz_ln = 0;
	img->endian = 0;
	img->ptr = NULL;
	img->data = NULL;
}
