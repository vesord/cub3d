/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:19:49 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 09:57:48 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_init(t_cub *cub)
{
	map_set_scales(cub);
	cam_init(cub);
}

void	map_set_scales(t_cub *cub)
{
	cub->map->blk_z = 16;
	cub->map->blk_x = 16;
	cub->map->blk_y = 16;
}

void	cam_init(t_cub *cub)
{
	cub->cam->cam_angle_yaw = M_PI / 3;
	cub->cam->cam_angle_pitch = M_PI / 3;
	cub->cam->z = cub->map->blk_z * 2 / 3;
	cub->cam->cam_direction_pitch = 0.;
}
