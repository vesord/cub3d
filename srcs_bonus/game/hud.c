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

void	update_hud(t_cub *cub)
{

	add_hud_face(cub);
	add_hud_wand(cub);
	cub->hud->need_update = 0;
}

void	add_hud_face(t_cub *cub)
{
	static int	face_added;

	if (!face_added)
	{
		put_tex_to_img(cub->hud->tx_face, cub->frm_0, HUD_TRANSP_MASK);
		put_tex_to_img(cub->hud->tx_face, cub->frm_1, HUD_TRANSP_MASK);
	}
	if (!face_added)
		face_added = 1;
}

void	add_hud_wand(t_cub *cub)
{
	if (cub->hud->need_update_weap)
	{
		put_tex_to_img(cub->hud->tx_wand, cub->frm_0, HUD_TRANSP_MASK);
		put_tex_to_img(cub->hud->tx_wand, cub->frm_1, HUD_TRANSP_MASK);
	}
	cub->hud->need_update_weap = 0;
}

unsigned int	get_pixel_texture(float off_x, float off_y, t_img *img);

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
			pixel = get_pixel_texture((float)(x) / img->width, (float)(y) / img->height, tex);
			if (pixel)
				((unsigned int*)(img->data))[img->width * y + x] = pixel | transp;
		}
	}
}

unsigned int	get_pixel_texture(float off_x, float off_y, t_img *img)
{
	return (((int*)(img->data))[img->width * (int)(img->height * off_y) + (int)(img->width * off_x)]);
}