/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_struct_tx_doors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:52:07 by matrus            #+#    #+#             */
/*   Updated: 2020/07/28 11:52:08 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_init.h"

void	cub_init_tex_doors(t_cub *cub)
{
	cub_init_tex_doors_set_null(cub->tex->tx_doors);
	if (!(cub->tex->tx_doors->mew_open = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_doors->mew_open);
	if (!(cub->tex->tx_doors->mew_close = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_doors->mew_close);
	if (!(cub->tex->tx_doors->lud_open = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_doors->lud_open);
	if (!(cub->tex->tx_doors->lud_close = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_doors->lud_close);
	if (!(cub->tex->tx_doors->secret_clos = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_doors->secret_clos);
	if (!(cub->tex->tx_doors->secret_open = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_doors->secret_open);
}

void	cub_init_tex_doors_set_null(t_tx_doors *tx_doors)
{
	tx_doors->secret_open = NULL;
	tx_doors->secret_clos = NULL;
	tx_doors->mew_open = NULL;
	tx_doors->mew_close = NULL;
	tx_doors->lud_open = NULL;
	tx_doors->lud_close = NULL;
}
