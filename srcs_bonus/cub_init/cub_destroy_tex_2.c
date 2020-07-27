/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_destroy_tex_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 09:53:45 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 09:57:20 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	cub_textures_destroy_spr_go(t_tx_spr_go *tx_spr_go, void *mlx_ptr)
{
	if (tx_spr_go->dropped_wand)
		cub_img_destroy(tx_spr_go->dropped_wand, mlx_ptr);
	if (tx_spr_go->trap)
		cub_img_destroy(tx_spr_go->trap, mlx_ptr);
	if (tx_spr_go->life)
		cub_img_destroy(tx_spr_go->life, mlx_ptr);
	if (tx_spr_go->ludo_beaten)
		cub_img_destroy(tx_spr_go->ludo_beaten, mlx_ptr);
	if (tx_spr_go->buffrog_beaten)
		cub_img_destroy(tx_spr_go->buffrog_beaten, mlx_ptr);
	if (tx_spr_go->secret)
		cub_img_destroy(tx_spr_go->secret, mlx_ptr);
	if (tx_spr_go->ludo_portal)
		cub_img_destroy(tx_spr_go->ludo_portal, mlx_ptr);
	if (tx_spr_go->rick_portal)
		cub_img_destroy(tx_spr_go->rick_portal, mlx_ptr);
	if (tx_spr_go->tutorial)
		cub_img_destroy(tx_spr_go->tutorial, mlx_ptr);
	if (tx_spr_go->lud_s_go)
		cub_img_destroy(tx_spr_go->lud_s_go, mlx_ptr);
	if (tx_spr_go->ric_s_go)
		cub_img_destroy(tx_spr_go->ric_s_go, mlx_ptr);
	if (tx_spr_go->mew_s_go)
		cub_img_destroy(tx_spr_go->mew_s_go, mlx_ptr);
	free(tx_spr_go);
}

void	cub_textures_destroy_spr_ngo(t_tx_spr_ngo *tx_spr_ngo, void *mlx_ptr)
{
	if (tx_spr_ngo->rick)
		cub_img_destroy(tx_spr_ngo->rick, mlx_ptr);
	if (tx_spr_ngo->ludo)
		cub_img_destroy(tx_spr_ngo->ludo, mlx_ptr);
	if (tx_spr_ngo->but_mom)
		cub_img_destroy(tx_spr_ngo->but_mom, mlx_ptr);
	if (tx_spr_ngo->but_dad)
		cub_img_destroy(tx_spr_ngo->but_dad, mlx_ptr);
	if (tx_spr_ngo->buffrog)
		cub_img_destroy(tx_spr_ngo->buffrog, mlx_ptr);
	if (tx_spr_ngo->motry)
		cub_img_destroy(tx_spr_ngo->motry, mlx_ptr);
	if (tx_spr_ngo->pony)
		cub_img_destroy(tx_spr_ngo->pony, mlx_ptr);
	if (tx_spr_ngo->lud_s_ngo_1)
		cub_img_destroy(tx_spr_ngo->lud_s_ngo_1, mlx_ptr);
	if (tx_spr_ngo->lud_s_ngo_2)
		cub_img_destroy(tx_spr_ngo->lud_s_ngo_2, mlx_ptr);
	if (tx_spr_ngo->mew_s_ngo_1)
		cub_img_destroy(tx_spr_ngo->mew_s_ngo_1, mlx_ptr);
	if (tx_spr_ngo->mew_s_ngo_2)
		cub_img_destroy(tx_spr_ngo->mew_s_ngo_2, mlx_ptr);
	free(tx_spr_ngo);
}

void	cub_textures_destroy_screens(t_tx_screens *tx_screens, void *mlx_ptr)
{
	if (tx_screens->end)
		cub_img_destroy(tx_screens->end, mlx_ptr);
	if (tx_screens->die)
		cub_img_destroy(tx_screens->die, mlx_ptr);
	if (tx_screens->res)
		cub_img_destroy(tx_screens->res, mlx_ptr);
	free(tx_screens);
}

void	cub_textures_destroy_skybox(t_tx_skybox *tx_skybox, void *mlx_ptr)
{
	if (tx_skybox->to)
		cub_img_destroy(tx_skybox->to, mlx_ptr);
	if (tx_skybox->so)
		cub_img_destroy(tx_skybox->so, mlx_ptr);
	if (tx_skybox->no)
		cub_img_destroy(tx_skybox->no, mlx_ptr);
	if (tx_skybox->ea)
		cub_img_destroy(tx_skybox->ea, mlx_ptr);
	if (tx_skybox->we)
		cub_img_destroy(tx_skybox->we, mlx_ptr);
	free(tx_skybox);
}
