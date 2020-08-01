/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_struct_tx_animation_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:52:38 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:30 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_init_bonus.h"

void	cub_init_tex_animation(t_cub *cub)
{
	cub_init_tex_animation_set_null(cub->tex->tx_anim);
	if (!(cub->tex->tx_anim->wand_1 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_anim->wand_1);
	if (!(cub->tex->tx_anim->wand_2 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_anim->wand_2);
	if (!(cub->tex->tx_anim->wand_3 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_anim->wand_3);
	if (!(cub->tex->tx_anim->wand_4 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_anim->wand_4);
	if (!(cub->tex->tx_anim->wand_5 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_anim->wand_5);
	cub_init_tex_animation_2(cub);
}

void	cub_init_tex_animation_2(t_cub *cub)
{
	if (!(cub->tex->tx_anim->wand_6 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_anim->wand_6);
	if (!(cub->tex->tx_anim->wand_7 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_anim->wand_7);
}

void	cub_init_tex_animation_set_null(t_tx_anim *tx_animation)
{
	tx_animation->wand_1 = NULL;
	tx_animation->wand_2 = NULL;
	tx_animation->wand_3 = NULL;
	tx_animation->wand_4 = NULL;
	tx_animation->wand_5 = NULL;
	tx_animation->wand_6 = NULL;
	tx_animation->wand_7 = NULL;
}
