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
	if (cub->key->esc)
		esc_press(cub);
//	debug_show_cam(cub);
}

void	process_step_direction(double angle, t_cub *cub);

void	process_step(t_cub *cub, int dir)
{
	if (dir == STEP_FORWARD)
		process_step_direction(cub->cam->cam_direction_yaw, cub);
	if (dir == STEP_BACK)
		process_step_direction(cub->cam->cam_direction_yaw + M_PI, cub);
	if (dir == STEP_LEFT)
		process_step_direction(cub->cam->cam_direction_yaw - M_PI_2, cub);
	if (dir == STEP_RIGHT)
		process_step_direction(cub->cam->cam_direction_yaw + M_PI_2, cub);
}

void	process_step_direction(double angle, t_cub *cub)
{
	double		len_to_wall;

	len_to_wall = throw_ray(cub, angle, angle) - cub->cam->dst_to_wall;
	if (cub->cam->step < len_to_wall)
	{
		cub->cam->x += cub->cam->step * cos(angle);
		cub->cam->y += cub->cam->step * sin(angle);
	}
	else
	{
		cub->cam->x += len_to_wall * cos(angle);
		cub->cam->y += len_to_wall * sin(angle);
	}
}
