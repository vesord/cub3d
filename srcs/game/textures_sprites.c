/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:55:59 by matrus            #+#    #+#             */
/*   Updated: 2020/07/21 21:56:01 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	frame_add_sprite(int frame_x, t_cub *cub)
{
	double	d_angle;
	t_sprites *spr;

	d_angle = cub->cam->cam_angle_pitch / cub->win->y;
	spr = sprites_last(cub->ray->spr);
	while (spr)
	{
		frame_add_sprite_one(frame_x, d_angle, spr, cub);
		if (spr->prev)
		{
			spr = spr->prev;
			free(spr->next);
		}
		else
		{
			free(spr);
			spr = NULL;
		}
	}
}

void	frame_add_sprite_one(int frame_x, double d_angle, t_sprites *spr, t_cub *cub)
{
	double	f_angl;
	double	c_angl;
	double	angle;
	int		frame_y;
	unsigned int		pixel;

	f_angl = atan((-cub->cam->z) / spr->len_to_sp);
	c_angl = atan((cub->map->blk_z - cub->cam->z) / spr->len_to_sp);
	angle = cub->cam->cam_direction_pitch + cub->cam->cam_angle_pitch / 2;
	frame_y = -1;
	while (spr->sp_x >= 0 && ++frame_y < cub->win->y)
	{
		if (angle < c_angl && angle > f_angl)
		{
			pixel = get_pixel_texture(spr->sp_x,
									  1. - (angle - f_angl) / (c_angl - f_angl), cub, 1);
			if (pixel != 0)
				((unsigned int *) cub->frm->data)[frame_y * cub->win->x +
												  frame_x] = pixel;
		}
		angle -= d_angle;
	}
}

t_sprites	*sprites_last(t_sprites *spr)
{
	if (!spr)
		return (NULL);
	while (spr->next)
		spr = spr->next;
	return (spr);
}

