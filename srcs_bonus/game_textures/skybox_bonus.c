/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:13:46 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:36 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "includes/cub_game_bonus.h"
#include "includes/cub_textures_bonus.h"

unsigned int	get_skybox_pixel(float p_angle, t_tx_skybox *sky, t_cub *cub)
{
	float			off_angle_yaw;
	int				dir;
	unsigned int	pixel;

	dir = 0;
	pixel = 0;
	off_angle_yaw = skybox_get_off_angle_yaw(cub->ray->angle, &dir);
	if (dir == DIR_TOP)
		pixel = get_skybox_pixel_tex(off_angle_yaw,
		(M_PI / 6 - p_angle) / (M_PI / 3), sky->no);
	if (dir == DIR_BOT)
		pixel = get_skybox_pixel_tex(off_angle_yaw,
		(M_PI / 6 - p_angle) / (M_PI / 3), sky->so);
	if (dir == DIR_LEFT)
		pixel = get_skybox_pixel_tex(off_angle_yaw,
		(M_PI / 6 - p_angle) / (M_PI / 3), sky->we);
	if (dir == DIR_RIGHT)
		pixel = get_skybox_pixel_tex(off_angle_yaw,
		(M_PI / 6 - p_angle) / (M_PI / 3), sky->ea);
	return (pixel);
}

unsigned int	get_skybox_pixel_tex(float off_x, float off_y, t_img *tex)
{
	return (((unsigned int*)(tex->data))[tex->width * (int)(off_y * tex->height)
	+ (int)(off_x * tex->width)]);
}

float			skybox_get_off_angle_yaw(float angle, int *dir)
{
	float	frac;
	float	not_used;

	frac = modff(angle / (float)(M_PI * 2), &not_used);
	if (frac < 0)
		frac += 1.f;
	if (frac > 0.125f && frac <= 0.375f)
	{
		*dir = DIR_BOT;
		return ((frac - 0.125f) / 0.25f);
	}
	else if (frac > 0.375 && frac <= 0.625)
	{
		*dir = DIR_LEFT;
		return ((frac - 0.375f) / 0.25f);
	}
	else if (frac > 0.625 && frac <= 0.875)
	{
		*dir = DIR_TOP;
		return ((frac - 0.625f) / 0.25f);
	}
	*dir = DIR_RIGHT;
	return (frac > 0.875f ? (frac - 0.875f) / 0.25f : (frac + 0.125f) / 0.25f);
}
