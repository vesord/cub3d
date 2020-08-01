/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_thorw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:48:23 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 11:12:29 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	throw_ray(t_cub *cub, double angle, double mid_angle)
{
	int		iterations;
	double	len_to_wall;

	iterations = 0;
	cub->ray->x = cub->cam->x;
	cub->ray->y = cub->cam->y;
	cub->ray->sin = sin(angle);
	cub->ray->cos = cos(angle);
	cub->ray->spr = NULL;
	while (is_next_cell_free(cub) && iterations < 50)
		iterations++;
	len_to_wall = sqrt(pow(cub->ray->x - cub->cam->x, 2) +
			pow(cub->ray->y - cub->cam->y, 2));
	cub->ray->walk_dst = len_to_wall;
	return (len_to_wall * fabs(cos(fabs(mid_angle - angle))));
}

int		is_next_cell_free(t_cub *cub)
{
	double	cell_x;
	double	cell_y;
	double	off_x;
	double	off_y;
	char	cell;

	cell_x = -1.;
	cell_y = -1.;
	off_x = modf(cub->ray->x / cub->map->blk_x, &cell_x) * cub->map->blk_x;
	off_y = modf(cub->ray->y / cub->map->blk_y, &cell_y) * cub->map->blk_y;
	find_next_cross(off_x, off_y, cub);
	cell = get_cell_ray((int)cell_x, (int)cell_y, cub);
	if (cell == '2')
		count_sprite(cell, cub);
	return (is_cell_free(cell));
}

void	find_next_cross(double off_x, double off_y, t_cub *cub)
{
	double len_x;
	double len_y;

	if (cub->ray->cos > 0)
		len_x = ((double)cub->map->blk_x - off_x) / cub->ray->cos;
	else
		len_x = fabs(off_x / cub->ray->cos);
	if (cub->ray->sin > 0)
		len_y = ((double)cub->map->blk_y - off_y) / cub->ray->sin;
	else
		len_y = fabs(off_y / cub->ray->sin);
	if (len_x < len_y)
	{
		cub->ray->x += len_x * cub->ray->cos;
		cub->ray->y += len_x * cub->ray->sin;
		ray_set_dir(len_x, len_y, cub);
	}
	else
	{
		cub->ray->x += len_y * cub->ray->cos;
		cub->ray->y += len_y * cub->ray->sin;
		ray_set_dir(len_x, len_y, cub);
	}
}

void	ray_set_dir(double len_x, double len_y, t_cub *cub)
{
	if (len_x < len_y)
		if (cub->ray->cos > 0)
		{
			cub->ray->dir = DIR_RIGHT;
			cub->ray->x += (double)cub->map->blk_x / 10000;
		}
		else
		{
			cub->ray->dir = DIR_LEFT;
			cub->ray->x -= (double)cub->map->blk_x / 10000;
		}
	else
	{
		if (cub->ray->sin > 0)
		{
			cub->ray->dir = DIR_BOT;
			cub->ray->y += (double)cub->map->blk_y / 10000;
		}
		else
		{
			cub->ray->dir = DIR_TOP;
			cub->ray->y -= (double)cub->map->blk_y / 10000;
		}
	}
}
