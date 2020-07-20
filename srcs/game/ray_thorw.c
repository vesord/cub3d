/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_thorw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:48:23 by matrus            #+#    #+#             */
/*   Updated: 2020/07/20 14:48:26 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	throw_ray(t_cub *cub, double angle)
{
	int		iterations;

	iterations = 0;
	cub->ray->x = cub->cam->x;
	cub->ray->y = cub->cam->y;
	cub->ray->sin = -sin(angle);
	cub->ray->cos = cos(angle);
	while (is_next_cell_free(cub) && iterations < 50)
		iterations++;
	return (sqrt(pow(cub->ray->x - cub->cam->x, 2) +
				 pow(cub->ray->y - cub->cam->y, 2)));
}

int		is_next_cell_free(t_cub *cub)
{
	double	cell_x;
	double	cell_y;
	double	off_x;
	double	off_y;

	off_x = modf(cub->ray->x / cub->map->blk_x, &cell_x) * cub->map->blk_x;
	off_y = modf(cub->ray->y / cub->map->blk_y, &cell_y) * cub->map->blk_y;
	find_next_cross(off_x, off_y, cub);
	if (cub->ray->dir == DIR_TOP)
		if (((int)cell_y - 1 < cub->map->max_y && (int)cell_x < cub->map->max_x)
			&& cub->map->field[(int)cell_y - 1][(int)cell_x] == '0')
			return (1);
	if (cub->ray->dir == DIR_BOT)
		if (((int)cell_y + 1 < cub->map->max_y && (int)cell_x < cub->map->max_x)
			&& cub->map->field[(int)cell_y + 1][(int)cell_x] == '0')
			return (1);
	if (cub->ray->dir == DIR_LEFT)
		if (((int)cell_y < cub->map->max_y && (int)cell_x - 1 < cub->map->max_x)
			&& cub->map->field[(int)cell_y][(int)cell_x - 1] == '0')
			return (1);
	if (cub->ray->dir == DIR_RIGHT)
		if (((int)cell_y < cub->map->max_y && (int)cell_x + 1 < cub->map->max_x)
			&& cub->map->field[(int)cell_y][(int)cell_x + 1] == '0')
			return (1);
	return (0);
}



void	find_next_cross(double off_x, double off_y, t_cub *cub)
{
	double ln_x;
	double ln_y;

	if (cub->ray->cos > 0)
		ln_x = ((double)cub->map->blk_x - off_x) / cub->ray->cos;
	else
		ln_x = -off_x / cub->ray->cos;
	if (cub->ray->sin > 0)
		ln_y = ((double)cub->map->blk_y - off_y) / cub->ray->sin;
	else
		ln_y = -off_y / cub->ray->sin;
	if (ln_x < ln_y)
	{
		cub->ray->x += ln_x * cub->ray->cos;
		cub->ray->y += ln_x * cub->ray->sin;
		ray_set_dir(ln_x, ln_y, cub);
	}
	else
	{
		cub->ray->x += ln_y * cub->ray->cos;
		cub->ray->y += ln_y * cub->ray->sin;
		ray_set_dir(ln_x, ln_y, cub);
	}
}

void	ray_set_dir(double len_x, double len_y, t_cub *cub)
{
	if (len_x < len_y)
		if (cub->ray->cos > 0)
		{
			cub->ray->dir = DIR_RIGHT;
			cub->ray->x += (double)cub->map->blk_x / 1000;
		}
		else
		{
			cub->ray->dir = DIR_LEFT;
			cub->ray->x -= (double)cub->map->blk_x / 1000;
		}
	else
	if (cub->ray->sin > 0)
	{
		cub->ray->dir = DIR_BOT;
		cub->ray->y += (double)cub->map->blk_y / 1000;
	}
	else
	{
		cub->ray->dir = DIR_TOP;
		cub->ray->y -= (double)cub->map->blk_y / 1000;
	}
}