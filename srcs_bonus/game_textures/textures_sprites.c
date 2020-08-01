/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:55:59 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 11:08:54 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_game.h"
#include "cub_textures.h"

void			frame_add_sprite(int frame_x, t_cub *cub)
{
	float			d_angle;
	t_ray_sprites	*spr;

	d_angle = cub->cam->cam_angle_pitch / cub->win->y;
	spr = sprites_last(cub->ray->spr);
	while (spr)
	{
		frame_add_sprite_one(frame_x, d_angle, spr, cub);
		if (spr->prev)
		{
			spr = spr->prev;
			free(spr->next);
			spr->next = NULL;
		}
		else
		{
			free(spr);
			spr = NULL;
			cub->ray->spr = NULL;
		}
	}
}

void			frame_add_sprite_one(int frame_x, float d_angle,
								t_ray_sprites *spr, t_cub *cub)
{
	int				frame_y;
	t_frm_col		col;
	unsigned int	pixel;

	col = frame_s_col_init(spr->len_to_sp, cub);
	frame_y = -1;
	while (spr->sp_x >= 0 && ++frame_y < cub->win->y)
	{
		if ((((int*)cub->frm_0->data)[frame_y * cub->win->x + frame_x]
		& 0xff000000) == HUD_TRANSP_MASK)
			;
		else if (col.angle < col.c_angle && col.angle > col.f_angle)
		{
			pixel = get_pixel_tex(spr->sp_x, 1.f - get_y_tex(col.angle,
										spr->len_to_sp, cub), spr->tex);
			if (pixel != 0)
				((unsigned int*)cub->frm_0->data)[frame_y * cub->win->x +
				frame_x] = add_shadow(pixel, spr->len_to_sp, cub);
		}
		col.angle -= d_angle;
	}
}

t_ray_sprites	*sprites_last(t_ray_sprites *spr)
{
	if (!spr)
		return (NULL);
	while (spr->next)
		spr = spr->next;
	return (spr);
}
