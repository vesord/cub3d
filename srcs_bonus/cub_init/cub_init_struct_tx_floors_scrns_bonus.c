/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_struct_tx_floors_scrns_bonus.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 20:41:33 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:30 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_init_bonus.h"

void	cub_init_tex_floors(t_cub *cub)
{
	cub_init_tex_floors_set_null(cub->tex->tx_floors);
	if (!(cub->tex->tx_floors->ludo = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_floors->ludo);
	if (!(cub->tex->tx_floors->rick = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_floors->rick);
	if (!(cub->tex->tx_floors->mewni = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_floors->mewni);
}

void	cub_init_tex_floors_set_null(t_tx_floors *tx_floors)
{
	tx_floors->mewni = NULL;
	tx_floors->rick = NULL;
	tx_floors->ludo = NULL;
}

void	cub_init_tex_screens(t_cub *cub)
{
	cub_init_tex_screens_set_null(cub->tex->tx_screens);
	if (!(cub->tex->tx_screens->res = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_screens->res);
	if (!(cub->tex->tx_screens->die = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_screens->die);
	if (!(cub->tex->tx_screens->end = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->tx_screens->end);
}

void	cub_init_tex_screens_set_null(t_tx_screens *tx_screens)
{
	tx_screens->end = NULL;
	tx_screens->die = NULL;
	tx_screens->res = NULL;
}
