/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cells.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 11:05:06 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 11:05:07 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
**	get_cell() checks x < 0 and y < 0 cos in some cases x and y came here
**	as MIN_INT value :/
*/

char	get_cell_map(int x, int y, t_cub *cub)
{
	if (x < 0 || y < 0 || x > cub->map->max_x || y > cub->map->max_y)
		return ('1');
	return (cub->map->field[y][x]);
}

char	get_cell_ray(int x, int y, t_cub *cub)
{
	if (x < 0 || y < 0)
		return ('1');
	if (cub->ray->dir == DIR_TOP)
		if (y - 1 < cub->map->max_y && x < cub->map->max_x)
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

int		is_cell_sprite(char c)
{
	if (ft_strchr("*$?wceslbgjlMDROPLBGHJK", c))
			return (1);
	return (0);
}

int		is_cell_wall(char c)
{
	if (ft_strchr("123456789", c))
		return (1);
	return (0);
}

int		is_cell_walkable(char c)
{
	if (ft_strchr("NWES0*$?wceslbgjl", c))
		return (1);
	return (0);
}
