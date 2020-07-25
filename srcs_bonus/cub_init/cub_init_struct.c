/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:06:25 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 09:51:53 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	cub_init_win(t_cub *cub)
{
	cub->win->mlx_ptr = NULL;
	cub->win->win_ptr = NULL;
	cub->win->x = 0;
	cub->win->y = 0;
}

void	cub_init_ray(t_cub *cub)
{
	cub->ray->cos = 0;
	cub->ray->sin = 0;
	cub->ray->mid_rel_angle = 0.;
	cub->ray->len_to_wall_real = 0.;
	cub->ray->x = 0;
	cub->ray->y = 0;
	cub->ray->dir = 0;
	cub->ray->spr = NULL;
}

void	cub_init_textures(t_cub *cub)
{
	cub_init_textures_null(cub->tex);
	if (!(cub->tex->ea = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->ea);
	if (!(cub->tex->we = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->we);
	if (!(cub->tex->no = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->no);
	if (!(cub->tex->so = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->so);
	if (!(cub->tex->s0 = (t_img*)malloc(sizeof(t_img))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_img(cub->tex->s0);
}

void	cub_init_textures_null(t_textures *tex)
{
	tex->ea = NULL;
	tex->no = NULL;
	tex->we = NULL;
	tex->so = NULL;
	tex->s0 = NULL;
	tex->ceil = 0;
	tex->flor = 0;
}

void	cub_init_img(t_img *img)
{
	img->width = 0;
	img->height = 0;
	img->btp = 0;
	img->sz_ln = 0;
	img->endian = 0;
	img->ptr = NULL;
	img->data = NULL;
}
