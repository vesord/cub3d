/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:51:04 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:34 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_game_bonus.h"

unsigned int	get_pixel_tex(float off_x, float off_y, t_img *tex)
{
	return (((int*)tex->data)[(int)((float)tex->height * off_y) * tex->width
	+ (int)((float)tex->width * off_x)]);
}

void			put_tex_to_img(t_img *tex, t_img *img, unsigned int transp)
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
			pixel = get_pixel_tex((float)(x) / img->width,
						(float)(y) / img->height, tex);
			if (pixel)
				((unsigned int*)(img->data))[img->width * y + x] =
					pixel | transp;
		}
	}
}

float			get_x_tex(t_cub *cub)
{
	float no_use;

	if (cub->ray->dir == DIR_RIGHT)
		return (1.f - modff(cub->ray->y / (float)cub->map->blk_y, &no_use));
	else if (cub->ray->dir == DIR_BOT)
		return (modff(cub->ray->x / (float)cub->map->blk_x, &no_use));
	else if (cub->ray->dir == DIR_LEFT)
		return (modff(cub->ray->y / (float)cub->map->blk_y, &no_use));
	else
		return (1.f - modff(cub->ray->x / (float)cub->map->blk_x, &no_use));
}

float			get_y_tex(float angle, float len_to_wall, t_cub *cub)
{
	return ((cub->cam->z + len_to_wall * tanf(angle)) / cub->map->blk_z);
}
