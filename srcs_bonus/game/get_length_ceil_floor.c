/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length_ceil_floor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 20:24:14 by matrus            #+#    #+#             */
/*   Updated: 2020/07/25 20:24:15 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double	get_len_ceil(double angle, t_cub *cub)
{
	return ((double)(cub->map->blk_z - cub->cam->z) / tan(angle));
}

double	get_len_flor(double angle, t_cub *cub)
{
	return ((double)(cub->cam->z) / -tan(angle));
}