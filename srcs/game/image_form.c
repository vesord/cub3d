/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 12:54:42 by matrus            #+#    #+#             */
/*   Updated: 2020/07/17 12:54:43 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//	PROCESSING FUNCTIONS	//

#define STEP_FORWARD 1
#define STEP_BACK 2
#define STEP_RIGHT 3
#define STEP_LEFT 4

int		process_game(t_cub *cub);
t_img	*frame_init(void* mlx_ptr, int x, int y);
void	process_key(t_cub *cub);
void	process_step(t_cub *cub, int dir);
void	make_frame(t_cub *cub);

int		process_game(t_cub *cub)
{
	if (!cub->frm && !(cub->frm = frame_init(cub->win->mlx_ptr,
		cub->win->x, cub->win->y)))
		cub_destroy(cub, ERR_NO_MEMORY);
	process_key(cub);
	make_frame(cub);
	mlx_put_image_to_window(cub->win->mlx_ptr, cub->win->win_ptr, cub->frm, 0 ,0);
	return (0);
}

void	process_key(t_cub *cub)
{
	if (cub->key->l_arrow)
		cub->cam->cam_direction_yaw += M_PI / 120; // Speed of rotation
	if (cub->key->r_arrow)
		cub->cam->cam_direction_yaw -= M_PI / 120; // Speed of rotation
	if (cub->key->w)
		process_step(cub, STEP_FORWARD);
	if (cub->key->a)
		process_step(cub, STEP_LEFT);
	if (cub->key->d)
		process_step(cub, STEP_RIGHT);
	if (cub->key->s)
		process_step(cub, STEP_BACK);
}

void	process_step(t_cub *cub, int dir)
{
	if (dir == STEP_FORWARD)
	{
		cub->cam->x += ((double)cub->map->blk_x / 5) * cos(cub->cam->cam_direction_yaw);
		cub->cam->y += ((double)cub->map->blk_y / 5) * sin(cub->cam->cam_direction_yaw);
	}
	if (dir == STEP_BACK)
	{
		cub->cam->x -= ((double)cub->map->blk_x / 5) * cos(cub->cam->cam_direction_yaw);
		cub->cam->y -= ((double)cub->map->blk_y / 5) * sin(cub->cam->cam_direction_yaw);
	}
	if (dir == STEP_LEFT)
	{
		cub->cam->x += ((double)cub->map->blk_x / 5) * cos(cub->cam->cam_direction_yaw + M_PI_2);
		cub->cam->y += ((double)cub->map->blk_y / 5) * sin(cub->cam->cam_direction_yaw + M_PI_2);
	}
	if (dir == STEP_RIGHT)
	{
		cub->cam->x += ((double)cub->map->blk_x / 5) * cos(cub->cam->cam_direction_yaw - M_PI_2);
		cub->cam->y += ((double)cub->map->blk_y / 5) * sin(cub->cam->cam_direction_yaw - M_PI_2);
	}
}

void	make_frame(t_cub *cub)
{
	int frame_x;
	double angle;
	double d_angle;

	angle = cub->cam->cam_direction_yaw + cub->cam->cam_angle_yaw / 2;
	d_angle = cub->cam->cam_angle_yaw / cub->win->x;
	frame_x = 0;
	while (frame_x < cub->win->x)
	{
		frame_col_set(frame_x, throw_ray(cub, angle));
		angle -= d_angle;
		frame_x++;
	}
}

double	throw_ray(t_cub *cub, double angle)
{
	int		iterations;

	cub->ray->x = cub->cam->x;
	cub->ray->y = cub->cam->y;
	while (is_next_cross_empty(cub) && )
}

//double ray_x;
//double ray_y;
//
//double throw_ray(double angle)
//{
//	int iterations = 0;
//
//	is_edge = 0;
//	ray_x = cam_x;
//	ray_y = cam_y;
//	while (is_xy_empty(ray_x, ray_y) && iterations < 1000000)
//	{
//		ray_x += cos(angle);
//		ray_y += sin(angle);
//		iterations++;
//	}
//	if (!((int)ray_x % blk_x) && !((int)ray_y % blk_y))
//		is_edge = 1;
//	return (sqrt(pow(ray_x - cam_x, 2) + pow(ray_y - cam_y, 2)));
//}

t_img	*frame_init(void* mlx_ptr, int x, int y)
{
	t_img *new_frame;

	if (!(new_frame = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	if (!(new_frame->ptr = mlx_new_image(mlx_ptr, x, y)))
	{
		free(new_frame);
		return (NULL);
	}
	new_frame->width = x;
	new_frame->height = y;
	if (!(new_frame->data = mlx_get_data_addr(new_frame->ptr,
		&(new_frame->btp), &(new_frame->sz_ln), &(new_frame->endian))))
	{
		mlx_destroy_image(mlx_ptr, new_frame->ptr);
		free(new_frame);
		return (NULL);
	}
	return (new_frame);
}