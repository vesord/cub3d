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
	cub->ray->len_to_sp = 0.;
	cub->ray->sp_x = -1.;
	while (is_next_cell_free(cub) && iterations < 50)
		iterations++;
	return (sqrt(pow(cub->ray->x - cub->cam->x, 2) +
				 pow(cub->ray->y - cub->cam->y, 2)));
}

char	get_cell(int x, int y, t_cub *cub);
int		is_cell_free(char c);
void	count_sprite(t_cub *cub);

int		is_next_cell_free(t_cub *cub)
{
	double	cell_x;
	double	cell_y;
	double	off_x;
	double	off_y;
	char	cell;

	off_x = modf(cub->ray->x / cub->map->blk_x, &cell_x) * cub->map->blk_x;
	off_y = modf(cub->ray->y / cub->map->blk_y, &cell_y) * cub->map->blk_y;
	find_next_cross(off_x, off_y, cub);
	cell = get_cell((int)cell_x, (int)cell_y, cub);
	if (cell == '2')
		count_sprite(cub);
	return (is_cell_free(cell));
}

void	count_sprite_len_to_sp(double sp_x_mid, double sp_y_mid, t_cub *cub);
void	count_sprite_x(double sp_x_mid, double sp_y_mid, t_cub *cub);

void	count_sprite(t_cub *cub)
{
	double	sp_y_mid;
	double	sp_x_mid;

	modf(cub->ray->x / cub->map->blk_x, &sp_x_mid);
	modf(cub->ray->y / cub->map->blk_y, &sp_y_mid);
	sp_x_mid = (sp_x_mid + 0.5) * cub->map->blk_x;
	sp_y_mid = (sp_y_mid + 0.5) * cub->map->blk_y;
	if (!cub->ray->len_to_sp)
		count_sprite_len_to_sp(sp_x_mid, sp_y_mid, cub);
	count_sprite_x(sp_x_mid, sp_y_mid, cub);
}

void	count_sprite_x(double sp_x_mid, double sp_y_mid, t_cub *cub)
{
	double dist_to_mid;

	sp_x_mid = sp_x_mid - cub->ray->x;
	sp_y_mid = sp_y_mid - cub->ray->y;
	dist_to_mid = cub->ray->cos * sp_y_mid + -cub->ray->sin * sp_x_mid;
	cub->ray->sp_x = ((cub->map->blk_x / 2) + dist_to_mid) / cub->map->blk_x;
	if (cub->ray->sp_x < 0 || cub->ray->sp_x > cub->map->blk_x)
		cub->ray->sp_x = -1.;
}

void	count_sprite_len_to_sp(double sp_x_mid, double sp_y_mid, t_cub *cub)
{
	cub->ray->len_to_sp = sqrt(pow(sp_x_mid - cub->cam->x, 2) +
		pow(sp_y_mid - cub->cam->y, 2));
}

char	get_cell(int x, int y, t_cub *cub)
{
	if (cub->ray->dir == DIR_TOP)
		if (y - 1 < cub->map->max_y && x < cub->map->max_x) // TODO: check if in correct map we need checks on y - 1 < max_y
			return (cub->map->field[y - 1][x]);
	if (cub->ray->dir == DIR_BOT)
		if (y + 1 < cub->map->max_y && x < cub->map->max_x)
			return (cub->map->field[y + 1][x]);
	if (cub->ray->dir == DIR_LEFT)
		if (y < cub->map->max_y && x - 1 < cub->map->max_x)
			return (cub->map->field[y][x - 1]);
	if (cub->ray->dir == DIR_RIGHT)
		if (y < cub->map->max_y && x + 1 < cub->map->max_x)
			return (cub->map->field[y][x + 1]);
	return ('1');
}

int		is_cell_free(char c)
{
	if (c == '0' || c == '2')
		return (1);
	return (0);
}

void	find_next_cross(double off_x, double off_y, t_cub *cub)
{
	double len_x;
	double len_y;

	if (cub->ray->cos > 0)
		len_x = ((double)cub->map->blk_x - off_x) / cub->ray->cos;
	else
		len_x = -off_x / cub->ray->cos;
	if (cub->ray->sin > 0)
		len_y = ((double)cub->map->blk_y - off_y) / cub->ray->sin;
	else
		len_y = -off_y / cub->ray->sin;
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
