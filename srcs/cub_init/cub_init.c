/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:08:13 by matrus            #+#    #+#             */
/*   Updated: 2020/07/15 16:08:14 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_init(t_cub *cub)
{
	cub_set_null(cub);
	if (!(cub->win = (t_win*)malloc(sizeof(t_win))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_win(cub);
	if (!(cub->ray = (t_ray*)malloc(sizeof(t_ray))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_ray(cub);
	if (!(cub->map = (t_map*)malloc(sizeof(t_map))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_map(cub);
	if (!(cub->cam = (t_cam*)malloc(sizeof(t_cam))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_cam(cub);
	if (!(cub->tex = (t_textures*)malloc(sizeof(t_textures))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_textures(cub);
}

void	cub_set_null(t_cub *cub)
{
	cub->win = NULL;
	cub->map = NULL;
	cub->cam = NULL;
	cub->tex = NULL;
	cub->ray = NULL;
	cub->confing_fd = -1;
}