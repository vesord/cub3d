/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_struct_tx_skybox_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 11:09:50 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:33 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_init_bonus.h"

void	cub_init_tex_skybox_mew(t_cub *cub)
{
	cub_init_tex_skybox_set_null(cub->tex->tx_sky_mew);
	if (!(cub->tex->tx_sky_mew->so = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_sky_mew->so);
	if (!(cub->tex->tx_sky_mew->ea = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_sky_mew->ea);
	if (!(cub->tex->tx_sky_mew->we = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_sky_mew->we);
	if (!(cub->tex->tx_sky_mew->no = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_sky_mew->no);
}

void	cub_init_tex_skybox_rick(t_cub *cub)
{
	cub_init_tex_skybox_set_null(cub->tex->tx_sky_rick);
	if (!(cub->tex->tx_sky_rick->so = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_sky_rick->so);
	if (!(cub->tex->tx_sky_rick->ea = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_sky_rick->ea);
	if (!(cub->tex->tx_sky_rick->we = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_sky_rick->we);
	if (!(cub->tex->tx_sky_rick->no = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_sky_rick->no);
}

void	cub_init_tex_skybox_set_null(t_tx_skybox *tx_skybox)
{
	tx_skybox->no = NULL;
	tx_skybox->ea = NULL;
	tx_skybox->we = NULL;
	tx_skybox->so = NULL;
}
