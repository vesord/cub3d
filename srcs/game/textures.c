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

#include "cub3d.h"

double			get_x_texture(t_cub *cub)
{
	double not_used;

	if (cub->ray->dir == DIR_RIGHT)
		return (1. - modf(cub->ray->y / (double)cub->map->blk_y, &not_used));
	else if (cub->ray->dir == DIR_BOT)
		return (modf(cub->ray->x / (double)cub->map->blk_x, &not_used));
	else if (cub->ray->dir == DIR_LEFT)
		return (modf(cub->ray->y / (double)cub->map->blk_y, &not_used));
	else
		return (1. - modf(cub->ray->x / (double)cub->map->blk_x, &not_used));
}

double			get_y_texture(double angle, double len_to_wall, t_cub *cub)
{
	return ((cub->cam->z + len_to_wall * tan(angle)) / cub->map->blk_z);
}

unsigned int	get_pixel_texture(double off_x, double off_y, t_cub *cub,
					int is_sp)
{
	t_img *no;
	t_img *so;
	t_img *ea;
	t_img *we;

	if (is_sp)
		return ((int*)cub->tex->s0->data)[(int)((double)cub->tex->s0->height
		* off_y) * cub->tex->s0->width +
		(int)((double)cub->tex->s0->width * off_x)];
	no = cub->tex->no;
	so = cub->tex->so;
	ea = cub->tex->ea;
	we = cub->tex->we;
	if (cub->ray->dir == DIR_TOP)
		return ((int*)no->data)[(int)((double)no->height * off_y) * no->width
		+ (int)((double)no->width * off_x)];
	else if (cub->ray->dir == DIR_BOT)
		return ((int*)so->data)[(int)((double)so->height * off_y) * so->width
		+ (int)((double)so->width * off_x)];
	else if (cub->ray->dir == DIR_LEFT)
		return ((int*)ea->data)[(int)((double)ea->height * off_y) * ea->width
		+ (int)((double)ea->width * off_x)];
	else
		return ((int*)we->data)[(int)((double)we->height * off_y) * we->width
			+ (int)((double)we->width * off_x)];
}
