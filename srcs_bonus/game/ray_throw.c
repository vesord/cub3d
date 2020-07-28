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

#include "cub3d_bonus.h"

float	throw_ray(t_cub *cub, float angle, float mid_angle)
{
	int		iterations;

	iterations = 0;
	cub->ray->angle = angle;
	cub->ray->x = cub->cam->x;
	cub->ray->y = cub->cam->y;
	cub->ray->wall = NULL;
	cub->ray->mid_rel_angle = mid_angle - angle;
	cub->ray->walk_dst = 0.f;
	cub->ray->sin = sinf(angle);
	cub->ray->cos = cosf(angle);
	cub->ray->spr = NULL;
	while (is_next_cell_free(cub) && iterations < 50)
		iterations++;
	cub->ray->len_to_wall_real = sqrtf(powf(cub->ray->x - cub->cam->x, 2) +
			powf(cub->ray->y - cub->cam->y, 2));
	if (cub->ray->walk_dst == 0.f)
		cub->ray->walk_dst = cub->ray->len_to_wall_real;
	return (cub->ray->len_to_wall_real * fabsf(cosf(fabsf(cub->ray->mid_rel_angle))));
}

int		is_next_cell_free(t_cub *cub)
{
	float	cell_x;
	float	cell_y;
	float	off_x;
	float	off_y;
	char	cell;

	cell_x = -1.f;
	cell_y = -1.f;
	off_x = modff(cub->ray->x / cub->map->blk_x, &cell_x) * cub->map->blk_x;
	off_y = modff(cub->ray->y / cub->map->blk_y, &cell_y) * cub->map->blk_y;
	find_next_cross(off_x, off_y, cub);
	cell = get_cell_ray((int) cell_x, (int) cell_y, cub);
	if (is_cell_sprite(cell))
		count_sprite(cell, cub);
	if (cub->ray->walk_dst == 0.f && !is_cell_walkable(cell))
		cub->ray->walk_dst = sqrtf(powf(cub->ray->x - cub->cam->x, 2) + powf(cub->ray->y - cub->cam->y, 2));
	if (is_cell_wall(cell) || is_cell_door_closed(cell))
	{
		if (is_cell_door_closed(cell))
			cub->ray->wall = select_door(cell, cub);
		else
			cub->ray->wall = select_wall(cell, cub);
		return (0);
	}
	return (1);
}

void	find_next_cross(float off_x, float off_y, t_cub *cub)
{
	float len_x;
	float len_y;

	if (cub->ray->cos > 0)
		len_x = ((float)cub->map->blk_x - off_x) / cub->ray->cos;
	else
		len_x = fabsf(off_x / cub->ray->cos);
	if (cub->ray->sin > 0)
		len_y = ((float)cub->map->blk_y - off_y) / cub->ray->sin;
	else
		len_y = fabsf(off_y / cub->ray->sin);
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

void	ray_set_dir(float len_x, float len_y, t_cub *cub)
{
	if (len_x < len_y)
		if (cub->ray->cos > 0)
		{
			cub->ray->dir = DIR_RIGHT;
			cub->ray->x += (float)cub->map->blk_x / 10000;
		}
		else
		{
			cub->ray->dir = DIR_LEFT;
			cub->ray->x -= (float)cub->map->blk_x / 10000;
		}
	else
	{
		if (cub->ray->sin > 0)
		{
			cub->ray->dir = DIR_BOT;
			cub->ray->y += (float)cub->map->blk_y / 10000;
		}
		else
		{
			cub->ray->dir = DIR_TOP;
			cub->ray->y -= (float)cub->map->blk_y / 10000;
		}
	}
}
