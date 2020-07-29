/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:51:04 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 11:19:04 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

float			get_x_tex(t_cub *cub)
{
	float not_used;

	if (cub->ray->dir == DIR_RIGHT)
		return (1.f - modff(cub->ray->y / (float)cub->map->blk_y, &not_used));
	else if (cub->ray->dir == DIR_BOT)
		return (modff(cub->ray->x / (float)cub->map->blk_x, &not_used));
	else if (cub->ray->dir == DIR_LEFT)
		return (modff(cub->ray->y / (float)cub->map->blk_y, &not_used));
	else
		return (1.f - modff(cub->ray->x / (float)cub->map->blk_x, &not_used));
}

float			get_y_tex(float angle, float len_to_wall, t_cub *cub)
{
	return ((cub->cam->z + len_to_wall * tanf(angle)) / cub->map->blk_z);
}

unsigned int get_pixel_tex(float off_x, float off_y, t_img *tex)
{
	return (((int*)tex->data)[(int)((float)tex->height * off_y) * tex->width + (int)((float)tex->width * off_x)]);
}
