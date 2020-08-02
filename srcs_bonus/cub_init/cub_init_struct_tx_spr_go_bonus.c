/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_struct_tx_spr_go_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 10:43:34 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:34 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "includes/cub_init_bonus.h"

void	cub_init_tex_spr_go(t_cub *cub)
{
	cub_init_tex_spr_go_set_null(cub->tex->tx_spr_go);
	if (!(cub->tex->tx_spr_go->tutorial = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_go->tutorial);
	if (!(cub->tex->tx_spr_go->life = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_go->life);
	if (!(cub->tex->tx_spr_go->trap = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_go->trap);
	cub_init_tex_spr_go_2(cub);
}

void	cub_init_tex_spr_go_2(t_cub *cub)
{
	if (!(cub->tex->tx_spr_go->ric_s_go = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_go->ric_s_go);
	if (!(cub->tex->tx_spr_go->mew_s_go = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_go->mew_s_go);
	if (!(cub->tex->tx_spr_go->lud_s_go = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_go->lud_s_go);
	if (!(cub->tex->tx_spr_go->rick_portal = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_go->rick_portal);
	cub_init_tex_spr_go_3(cub);
}

void	cub_init_tex_spr_go_3(t_cub *cub)
{
	if (!(cub->tex->tx_spr_go->ludo_portal = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_go->ludo_portal);
	if (!(cub->tex->tx_spr_go->ludo_beaten = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_go->ludo_beaten);
	if (!(cub->tex->tx_spr_go->buffrog_beaten = (t_img*)malloc(
		sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_go->buffrog_beaten);
	if (!(cub->tex->tx_spr_go->dropped_wand = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_go->dropped_wand);
}

void	cub_init_tex_spr_go_set_null(t_tx_spr_go *tx_spr_go)
{
	tx_spr_go->life = NULL;
	tx_spr_go->buffrog_beaten = NULL;
	tx_spr_go->ludo_beaten = NULL;
	tx_spr_go->ludo_portal = NULL;
	tx_spr_go->rick_portal = NULL;
	tx_spr_go->dropped_wand = NULL;
	tx_spr_go->lud_s_go = NULL;
	tx_spr_go->mew_s_go = NULL;
	tx_spr_go->ric_s_go = NULL;
	tx_spr_go->trap = NULL;
	tx_spr_go->tutorial = NULL;
}
