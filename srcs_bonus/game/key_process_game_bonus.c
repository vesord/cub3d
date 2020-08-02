/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_process_game_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:43:20 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:34 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "includes/cub_hud_bonus.h"
#include "includes/cub_game_bonus.h"

void	process_key(t_cub *cub)
{
	if (cub->key->l_arrow)
		cub->cam->cam_direction_yaw -= M_PI / TURN_SCALER;
	if (cub->key->r_arrow)
		cub->cam->cam_direction_yaw += M_PI / TURN_SCALER;
	if (cub->key->shoot && !cub->hud->shooting)
		cub->hud->shooting = 1;
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
	if (cub->key->jump && !cub->hud->jumping)
		cub->hud->jumping = 1;
	if (cub->key->action)
		process_action(cub);
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
	float		len_to_wall_dir;
	float		sin_;
	float		cos_;

	sin_ = sinf(angle);
	cos_ = cosf(angle);
	len_to_wall_y = sin_ > 0 ? get_walk_len_dir(M_PI_2, cub) :
		get_walk_len_dir(-M_PI_2, cub);
	len_to_wall_x = cos_ > 0 ? get_walk_len_dir(0, cub) :
		get_walk_len_dir(M_PI, cub);
	len_to_wall_dir = throw_ray(cub, angle, angle);
	if (len_to_wall_dir < cub->cam->step)
		return ;
	if (len_to_wall_y > fabsf(cub->cam->step * sin_))
		cub->cam->y += cub->cam->step * sin_;
	else
		cub->cam->y += len_to_wall_y * sin_;
	if (len_to_wall_x > fabsf(cub->cam->step * cos_))
		cub->cam->x += cub->cam->step * cos_;
	else
		cub->cam->x += len_to_wall_x * cos_;
}

float	get_walk_len_dir(float angle, t_cub *cub)
{
	throw_ray(cub, angle, angle);
	return (cub->ray->walk_dst - cub->cam->dst_to_wall);
}

void	process_action(t_cub *cub)
{
	float	cam_x;
	float	cam_y;
	char	cell;

	throw_ray(cub, cub->cam->cam_direction_yaw, cub->cam->cam_direction_yaw);
	modff(cub->cam->x / cub->map->blk_x, &cam_x);
	modff(cub->cam->y / cub->map->blk_y, &cam_y);
	cell = get_cell_ray((int)cam_x, (int)cam_y, cub);
	if (cub->ray->dir == DIR_TOP)
		cam_y -= 1.f;
	if (cub->ray->dir == DIR_BOT)
		cam_y += 1.f;
	if (cub->ray->dir == DIR_LEFT)
		cam_x -= 1.f;
	if (cub->ray->dir == DIR_RIGHT)
		cam_x += 1.f;
	if (is_cell_door_opened(cell))
		(cub->map->field)[(int)cam_y][(int)cam_x] = (char)ft_toupper(cell);
	if (is_cell_door_closed(cell))
		(cub->map->field)[(int)cam_y][(int)cam_x] = (char)ft_tolower(cell);
	cub->key->action = 0;
}
