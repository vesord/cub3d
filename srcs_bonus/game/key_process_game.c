/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_process_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:43:20 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 11:07:41 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	process_key(t_cub *cub)
{
	if (cub->key->l_arrow)
		cub->cam->cam_direction_yaw -= M_PI / TURN_SCALER;
	if (cub->key->r_arrow)
		cub->cam->cam_direction_yaw += M_PI / TURN_SCALER;
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
}

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

void	process_step_direction(float angle, t_cub *cub)
{
	float		len_to_wall_x;
	float		len_to_wall_y;
	float		sin_;
	float		cos_;

	sin_ = sinf(angle);
	cos_ = cosf(angle);
	if (sin_ > 0)
		len_to_wall_y = throw_ray(cub, M_PI_2, M_PI_2) - cub->cam->dst_to_wall;
	else
		len_to_wall_y = throw_ray(cub, -M_PI_2, -M_PI_2)
			- cub->cam->dst_to_wall;
	if (cos_ > 0)
		len_to_wall_x = throw_ray(cub, 0, 0) - cub->cam->dst_to_wall;
	else
		len_to_wall_x = throw_ray(cub, M_PI, M_PI) - cub->cam->dst_to_wall;
	if (len_to_wall_y > fabs(cub->cam->step * sin_))
		cub->cam->y += cub->cam->step * sin_;
	else
		cub->cam->y += len_to_wall_y * sin_;
	if (len_to_wall_x > fabs(cub->cam->step * cos_))
		cub->cam->x += cub->cam->step * cos_;
	else
		cub->cam->x += len_to_wall_x * cos_;
}
