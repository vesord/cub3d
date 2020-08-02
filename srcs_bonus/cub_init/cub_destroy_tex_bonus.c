/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_destroy_tex_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 11:27:54 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:29 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "includes/cub_init_bonus.h"

void	cub_textures_destroy(t_textures *tex, void *mlx_ptr)
{
	if (tex->tx_walls)
		cub_textures_destroy_walls(tex->tx_walls, mlx_ptr);
	if (tex->tx_floors)
		cub_textures_destroy_floors(tex->tx_floors, mlx_ptr);
	if (tex->tx_spr_go)
		cub_textures_destroy_spr_go(tex->tx_spr_go, mlx_ptr);
	if (tex->tx_spr_ngo)
		cub_textures_destroy_spr_ngo(tex->tx_spr_ngo, mlx_ptr);
	if (tex->tx_screens)
		cub_textures_destroy_screens(tex->tx_screens, mlx_ptr);
	if (tex->tx_sky_mew)
		cub_textures_destroy_skybox(tex->tx_sky_mew, mlx_ptr);
	if (tex->tx_sky_rick)
		cub_textures_destroy_skybox(tex->tx_sky_rick, mlx_ptr);
	if (tex->tx_anim)
		cub_textures_destroy_animation(tex->tx_anim, mlx_ptr);
	if (tex->tx_doors)
		cub_textures_destroy_doors(tex->tx_doors, mlx_ptr);
	free(tex);
}

void	cub_img_destroy(t_img *img, void *mlx_ptr)
{
	if (img->ptr)
		mlx_destroy_image(mlx_ptr, img->ptr);
	free(img);
}

void	cub_textures_destroy_walls(t_tx_walls *tx_walls, void *mlx_ptr)
{
	if (tx_walls->rick_1)
		cub_img_destroy(tx_walls->rick_1, mlx_ptr);
	if (tx_walls->rick_2)
		cub_img_destroy(tx_walls->rick_2, mlx_ptr);
	if (tx_walls->ludo_1)
		cub_img_destroy(tx_walls->ludo_1, mlx_ptr);
	if (tx_walls->ludo_2)
		cub_img_destroy(tx_walls->ludo_2, mlx_ptr);
	if (tx_walls->ludo_3)
		cub_img_destroy(tx_walls->ludo_3, mlx_ptr);
	if (tx_walls->mewni_1)
		cub_img_destroy(tx_walls->mewni_1, mlx_ptr);
	if (tx_walls->mewni_2)
		cub_img_destroy(tx_walls->mewni_2, mlx_ptr);
	if (tx_walls->mewni_3)
		cub_img_destroy(tx_walls->mewni_3, mlx_ptr);
	free(tx_walls);
}

void	cub_textures_destroy_floors(t_tx_floors *tx_floors, void *mlx_ptr)
{
	if (tx_floors->ludo)
		cub_img_destroy(tx_floors->ludo, mlx_ptr);
	if (tx_floors->rick)
		cub_img_destroy(tx_floors->rick, mlx_ptr);
	if (tx_floors->mewni)
		cub_img_destroy(tx_floors->mewni, mlx_ptr);
	free(tx_floors);
}

void	cub_textures_destroy_skybox(t_tx_skybox *tx_skybox, void *mlx_ptr)
{
	if (tx_skybox->so)
		cub_img_destroy(tx_skybox->so, mlx_ptr);
	if (tx_skybox->no)
		cub_img_destroy(tx_skybox->no, mlx_ptr);
	if (tx_skybox->ea)
		cub_img_destroy(tx_skybox->ea, mlx_ptr);
	if (tx_skybox->we)
		cub_img_destroy(tx_skybox->we, mlx_ptr);
	free(tx_skybox);
}
