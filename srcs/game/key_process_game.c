/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_process_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:43:20 by matrus            #+#    #+#             */
/*   Updated: 2020/07/20 14:43:25 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//
#include <stdio.h>
void	debug_show_cam(t_cub *cub);

void	debug_show_cam(t_cub *cub)
{
	printf("x: %.2f, y: %.2f, angle: %.2f\n", cub->cam->x, cub->cam->y, cub->cam->cam_direction_yaw);
}

void	process_key(t_cub *cub)
{
	if (cub->key->l_arrow)
		cub->cam->cam_direction_yaw -= M_PI / TURN_SCALER; // Speed of rotation
	if (cub->key->r_arrow)
		cub->cam->cam_direction_yaw += M_PI / TURN_SCALER; // Speed of rotation
	if (cub->key->w)
		process_step(cub, STEP_FORWARD);
	if (cub->key->a)
		process_step(cub, STEP_LEFT);
	if (cub->key->d)
		process_step(cub, STEP_RIGHT);
	if (cub->key->s)
		process_step(cub, STEP_BACK);
	debug_show_cam(cub);
}

void	process_step(t_cub *cub, int dir)
{
	if (dir == STEP_FORWARD)
	{
		cub->cam->x += ((double)cub->map->blk_x / STEP_SCALER) * cos(cub->cam->cam_direction_yaw);
		cub->cam->y += ((double)cub->map->blk_y / STEP_SCALER) * -sin(cub->cam->cam_direction_yaw);
	}
	if (dir == STEP_BACK)
	{
		cub->cam->x -= ((double)cub->map->blk_x / STEP_SCALER) * cos(cub->cam->cam_direction_yaw);
		cub->cam->y -= ((double)cub->map->blk_y / STEP_SCALER) * -sin(cub->cam->cam_direction_yaw);
	}
	if (dir == STEP_LEFT)
	{
		cub->cam->x += ((double)cub->map->blk_x / STEP_SCALER) * cos(cub->cam->cam_direction_yaw - M_PI_2);
		cub->cam->y += ((double)cub->map->blk_y / STEP_SCALER) * -sin(cub->cam->cam_direction_yaw - M_PI_2);
	}
	if (dir == STEP_RIGHT)
	{
		cub->cam->x += ((double)cub->map->blk_x / STEP_SCALER) * cos(cub->cam->cam_direction_yaw + M_PI_2);
		cub->cam->y += ((double)cub->map->blk_y / STEP_SCALER) * -sin(cub->cam->cam_direction_yaw + M_PI_2);
	}
}
