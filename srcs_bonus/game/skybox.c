/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:13:46 by matrus            #+#    #+#             */
/*   Updated: 2020/07/28 18:13:49 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

float	skybox_get_off_angle_yaw(float angle, int *dir);
unsigned int	get_skybox_pixel_tex(float off_x, float off_y, t_img *tex);

unsigned int	get_skybox_pixel(float p_angle, t_cub *cub)
{
	float			off_angle_yaw;
	int				dir;

	dir = 0;
	off_angle_yaw = skybox_get_off_angle_yaw(cub->ray->angle, &dir);
	if (dir == DIR_TOP)
		return (get_skybox_pixel_tex(off_angle_yaw, (M_PI / 6 - p_angle) / (M_PI / 3), cub->tex->tx_sky_mew->no));
	if (dir == DIR_BOT)
		return (get_skybox_pixel_tex(off_angle_yaw, (M_PI / 6 - p_angle) / (M_PI / 3), cub->tex->tx_sky_mew->so));
	if (dir == DIR_LEFT)
		return (get_skybox_pixel_tex(off_angle_yaw, (M_PI / 6 - p_angle) / (M_PI / 3), cub->tex->tx_sky_mew->we));
	if (dir == DIR_RIGHT)
		return (get_skybox_pixel_tex(off_angle_yaw, (M_PI / 6 - p_angle) / (M_PI / 3), cub->tex->tx_sky_mew->ea));
	return (0);
}

unsigned int	get_skybox_pixel_tex(float off_x, float off_y, t_img *tex)
{
	return (((unsigned int*)(tex->data))[tex->width * (int)(off_y * tex->height) + (int)(off_x * tex->width)]);
}

float	skybox_get_off_angle_yaw(float angle, int *dir)
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

//if (frac < -0.125f && frac >= -0.375f)
//return (1.f - (frac + 0.125f) / -0.25f);
//if (frac < -0.375f && frac >= -0.625f)
//return (1.f - (frac + 0.375f) / -0.25f);
//if (frac < -0.625f && frac >= -0.875f)
//return (1.f - (frac + 0.625f) / -0.25f);
//return (frac < 0.875f ? (1.f + frac + 0.125f) / 0.25f : (0.125f + frac) / 0.25f);