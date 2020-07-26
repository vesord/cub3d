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

float			get_x_wall(t_cub *cub)
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

float			get_y_wall(float angle, float len_to_wall, t_cub *cub)
{
	return ((cub->cam->z + len_to_wall * tanf(angle)) / cub->map->blk_z);
}

unsigned int	get_pixel_wall(float off_x, float off_y, t_cub *cub,
							   int is_sp)
{
	t_img *no;
	t_img *so;
	t_img *ea;
	t_img *we;

	if (is_sp)
		return ((int*)cub->tex->s0->data)[(int)((float)cub->tex->s0->height
		* off_y) * cub->tex->s0->width +
		(int)((float)cub->tex->s0->width * off_x)];
	no = cub->tex->no;
	so = cub->tex->so;
	ea = cub->tex->ea;
	we = cub->tex->we;
	if (cub->ray->dir == DIR_TOP)
		return ((int*)no->data)[(int)((float)no->height * off_y) * no->width
		+ (int)((float)no->width * off_x)];
	else if (cub->ray->dir == DIR_BOT)
		return ((int*)so->data)[(int)((float)so->height * off_y) * so->width
		+ (int)((float)so->width * off_x)];
	else if (cub->ray->dir == DIR_LEFT)
		return ((int*)ea->data)[(int)((float)ea->height * off_y) * ea->width
		+ (int)((float)ea->width * off_x)];
	else
		return ((int*)we->data)[(int)((float)we->height * off_y) * we->width
			+ (int)((float)we->width * off_x)];
}
