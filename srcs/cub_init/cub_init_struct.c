/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:06:25 by matrus            #+#    #+#             */
/*   Updated: 2020/07/15 16:06:26 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_init_win(t_cub *cub)
{
	cub->win->mlx_ptr = NULL;
	cub->win->win_ptr = NULL;
	cub->win->x = 0;
	cub->win->y = 0;
}

void	cub_init_ray(t_cub *cub)
{
	cub->ray->angle = 0;
	cub->ray->x = 0;
	cub->ray->y = 0;
}

void	cub_init_textures(t_cub *cub)
{
	cub->tex->ea_data = NULL;
	cub->tex->ea_ptr = NULL;
	cub->tex->no_data = NULL;
	cub->tex->no_ptr = NULL;
	cub->tex->we_data = NULL;
	cub->tex->we_ptr = NULL;
	cub->tex->so_data = NULL;
	cub->tex->so_ptr = NULL;
	cub->tex->s0_data = NULL;
	cub->tex->s0_ptr = NULL;
}

void	cub_init_map(t_cub *cub)
{
	cub->map->blk_y = 0;
	cub->map->blk_x = 0;
	cub->map->blk_z = 0;
	cub->map->field = NULL;
	cub->map->max_x = 0;
	cub->map->max_y = 0;
}

void	cub_init_cam(t_cub *cub)
{
	cub->cam->cam_direction_yaw = 0;
	cub->cam->cam_direction_pitch = 0;
	cub->cam->cam_angle_yaw = 0;
	cub->cam->cam_angle_pitch = 0;
	cub->cam->x = 0;
	cub->cam->y = 0;
	cub->cam->z = 0;
}
