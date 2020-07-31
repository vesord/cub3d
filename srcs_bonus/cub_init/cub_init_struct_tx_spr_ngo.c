/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_struct_tx_spr_ngo.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 10:58:23 by matrus            #+#    #+#             */
/*   Updated: 2020/07/27 10:58:24 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_init.h"

void	cub_init_tex_spr_ngo(t_cub *cub)
{
	cub_init_tex_spr_ngo_set_null(cub->tex->tx_spr_ngo);
	if (!(cub->tex->tx_spr_ngo->mew_s_ngo_1 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_ngo->mew_s_ngo_1);
	if (!(cub->tex->tx_spr_ngo->mew_s_ngo_2 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_ngo->mew_s_ngo_2);
	if (!(cub->tex->tx_spr_ngo->lud_s_ngo_1 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_ngo->lud_s_ngo_1);
	if (!(cub->tex->tx_spr_ngo->rick = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_ngo->rick);
	cub_init_tex_spr_ngo_2(cub);
}

void	cub_init_tex_spr_ngo_2(t_cub *cub)
{
	if (!(cub->tex->tx_spr_ngo->motry = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_ngo->motry);
	if (!(cub->tex->tx_spr_ngo->pony = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_ngo->pony);
	if (!(cub->tex->tx_spr_ngo->ludo = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_ngo->ludo);
	if (!(cub->tex->tx_spr_ngo->buffrog = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_ngo->buffrog);
	if (!(cub->tex->tx_spr_ngo->but_mom = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_ngo->but_mom);
	if (!(cub->tex->tx_spr_ngo->but_dad = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_spr_ngo->but_dad);
}

void	cub_init_tex_spr_ngo_set_null(t_tx_spr_ngo *tx_spr_ngo)
{
	tx_spr_ngo->ludo = NULL;
	tx_spr_ngo->rick = NULL;
	tx_spr_ngo->buffrog = NULL;
	tx_spr_ngo->but_dad = NULL;
	tx_spr_ngo->but_mom = NULL;
	tx_spr_ngo->motry = NULL;
	tx_spr_ngo->pony = NULL;
	tx_spr_ngo->lud_s_ngo_1 = NULL;
	tx_spr_ngo->mew_s_ngo_1 = NULL;
	tx_spr_ngo->mew_s_ngo_2 = NULL;
}