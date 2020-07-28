/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:05:15 by matrus            #+#    #+#             */
/*   Updated: 2020/07/25 23:05:17 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	put_hp_to_img(int off_x, int off_y, int size, t_cub *cub);
void	add_hud_hp(t_cub *cub);
void	process_jumping(t_cub *cub);

void	update_hud(t_cub *cub)
{
	if (cub->hud->hp <= 0)
		cub->hud->status = -1;
	add_hud_face(cub);
	add_hud_wand(cub);
	add_hud_hp(cub);
	if (cub->hud->jumping)
		process_jumping(cub);
}

void	add_hud_hp(t_cub *cub)
{
	int	i;

	if (!cub->hud->need_update_hp)
		return ;
	i = -1;
	while (++i < cub->hud->hp)
	{
		put_hp_to_img(cub->win->x / 20 + i * cub->win->x / 10, cub->win->y / 20, cub->win->x / 20, cub);
	}
	cub->hud->need_update_hp = 0;
}

void	add_hud_face(t_cub *cub)
{
	if (!cub->hud->need_update_face)
		return ;
	put_tex_to_img(cub->hud->tx_face, cub->frm_0, HUD_TRANSP_MASK);
	put_tex_to_img(cub->hud->tx_face, cub->frm_1, HUD_TRANSP_MASK);
	cub->hud->need_update_face = 0;
}

void	add_hud_wand(t_cub *cub)
{
	if (!cub->hud->need_update_weap)
		return ;
	put_tex_to_img(cub->hud->tx_wand, cub->frm_0, HUD_TRANSP_MASK);
	put_tex_to_img(cub->hud->tx_wand, cub->frm_1, HUD_TRANSP_MASK);
	cub->hud->need_update_weap = 0;
}

void	process_jumping(t_cub *cub)
{
	static int jump_status = -36;
	static int jump_max = 36;

	cub->cam->z = ((float)cub->map->blk_z * 2 / 3) + ((float)jump_max - (float)abs(jump_status)) / 2.f;
	jump_status += (int)sqrtf((float)abs(jump_status));
	if (jump_status == 0)
		jump_status = 1;
	if (jump_status > jump_max)
	{
		jump_status = -jump_max;
		cub->hud->jumping = 0;
	}
}



void put_tex_to_img(t_img *tex, t_img *img, unsigned int transp)
{
	int				x;
	int				y;
	unsigned int	pixel;

	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
		{
			pixel = get_pixel_tex((float)(x) / img->width, (float)(y) / img->height, tex);
			if (pixel)
				((unsigned int*)(img->data))[img->width * y + x] = pixel | transp;
		}
	}
}

void	put_hp_to_img(int off_x, int off_y, int size, t_cub *cub)
{
	int cur_x;
	int cur_y;
	unsigned int pixel;

	cur_y = -1;
	while (++cur_y < size)
	{
		cur_x = -1;
		while (++cur_x < size)
		{
			pixel = get_pixel_tex((float)cur_x / (float)size, (float)cur_y / (float)size, cub->hud->tx_hp);
			if (pixel)
			{
				((unsigned int *) (cub->frm_0->data))[cub->win->x * (cur_y + off_y) + cur_x + off_x] = pixel | HUD_TRANSP_MASK;
				((unsigned int *) (cub->frm_1->data))[cub->win->x * (cur_y + off_y) + cur_x + off_x] = pixel | HUD_TRANSP_MASK;
			}
		}
	}
}
