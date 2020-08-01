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
#include "cub_init.h"

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
	cub->ray->mid_rel_angle = 0.f;
	cub->ray->len_to_wall_real = 0.f;
	cub->ray->walk_dst = 0.f;
	cub->ray->x = 0;
	cub->ray->y = 0;
	cub->ray->dir = 0;
	cub->ray->wall = NULL;
	cub->ray->spr = NULL;
}

void	cub_init_textures(t_cub *cub)
{
	cub_init_textures_null(cub->tex);
	if (!(cub->tex->tx_walls = (t_tx_walls*)malloc(sizeof(t_tx_walls))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_tex_walls(cub);
	if (!(cub->tex->tx_floors = (t_tx_floors*)malloc(sizeof(t_tx_floors))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_tex_floors(cub);
	if (!(cub->tex->tx_screens = (t_tx_screens*)malloc(sizeof(t_tx_screens))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_tex_screens(cub);
	if (!(cub->tex->tx_doors = (t_tx_doors*)malloc(sizeof(t_tx_doors))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_tex_doors(cub);
	if (!(cub->tex->tx_anim = (t_tx_anim*)malloc(sizeof(t_tx_anim))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_tex_animation(cub);
	cub_init_textures_2(cub);
}

void	cub_init_textures_2(t_cub *cub)
{
	if (!(cub->tex->tx_spr_go = (t_tx_spr_go*)malloc(sizeof(t_tx_spr_go))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_tex_spr_go(cub);
	if (!(cub->tex->tx_spr_ngo = (t_tx_spr_ngo*)malloc(sizeof(t_tx_spr_ngo))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_tex_spr_ngo(cub);
	if (!(cub->tex->tx_sky_rick = (t_tx_skybox*)malloc(sizeof(t_tx_skybox))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_tex_skybox_rick(cub);
	if (!(cub->tex->tx_sky_mew = (t_tx_skybox*)malloc(sizeof(t_tx_skybox))))
		cub_destroy(cub, ERR_NO_MEMORY);
	else
		cub_init_tex_skybox_mew(cub);
}

void	cub_init_textures_null(t_textures *tex)
{
	tex->flor = 0;
	tex->ceil = 0;
	tex->tx_floors = NULL;
	tex->tx_walls = NULL;
	tex->tx_spr_ngo = NULL;
	tex->tx_screens = NULL;
	tex->tx_sky_mew = NULL;
	tex->tx_sky_rick = NULL;
	tex->tx_spr_go = NULL;
	tex->tx_anim = NULL;
	tex->tx_doors = NULL;
}
