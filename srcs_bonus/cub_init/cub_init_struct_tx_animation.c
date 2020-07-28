/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_struct_tx_animation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:52:38 by matrus            #+#    #+#             */
/*   Updated: 2020/07/28 11:52:39 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	cub_init_tex_animation_set_null(t_tx_animation *tx_animation);

void	cub_init_tex_animation(t_cub *cub)
{
	cub_init_tex_animation_set_null(cub->tex->tx_animation);
	if (!(cub->tex->tx_animation->wand_2 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_animation->wand_2);
	if (!(cub->tex->tx_animation->wand_1 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_animation->wand_1);
}

void	cub_init_tex_animation_set_null(t_tx_animation *tx_animation)
{
	tx_animation->wand_1 = NULL;
	tx_animation->wand_2 = NULL;
}
