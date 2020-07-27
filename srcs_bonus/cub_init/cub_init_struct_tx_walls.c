/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_struct_tx_walls.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 20:40:18 by matrus            #+#    #+#             */
/*   Updated: 2020/07/26 20:40:19 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	cub_init_tex_walls(t_cub *cub)
{
	cub_init_tex_wall_set_null(cub->tex->tx_walls);
	if (!(cub->tex->tx_walls->ludo_1 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_walls->ludo_1);
	if (!(cub->tex->tx_walls->ludo_2 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_walls->ludo_2);
	if (!(cub->tex->tx_walls->ludo_3 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_walls->ludo_3);
	if (!(cub->tex->tx_walls->mewni_1 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_walls->mewni_1);
	cub_init_tex_walls_1(cub);
}

void	cub_init_tex_walls_1(t_cub *cub)
{
	if (!(cub->tex->tx_walls->mewni_2 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_walls->mewni_2);
	if (!(cub->tex->tx_walls->mewni_3 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_walls->mewni_3);
	if (!(cub->tex->tx_walls->rick_1 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_walls->rick_1);
	if (!(cub->tex->tx_walls->rick_2 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_walls->rick_2);
	if (!(cub->tex->tx_walls->wall_9 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_walls->wall_9);
}

void	cub_init_tex_wall_set_null(t_tx_walls *tx_walls)
{
	tx_walls->ludo_1 = NULL;
	tx_walls->ludo_2 = NULL;
	tx_walls->ludo_3 = NULL;
	tx_walls->mewni_1 = NULL;
	tx_walls->mewni_2 = NULL;
	tx_walls->mewni_3 = NULL;
	tx_walls->rick_1 = NULL;
	tx_walls->rick_2 = NULL;
	tx_walls->wall_9 = NULL;
	tx_walls->on_map = NULL;
}