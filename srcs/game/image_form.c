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

int		process_game(t_cub *cub)
{
	if (!cub->frm && !(cub->frm = frame_init(cub->win->mlx_ptr,
		cub->win->x, cub->win->y)))
		cub_destroy(cub, ERR_NO_MEMORY);
	process_key(cub);
	make_frame(cub);
	mlx_put_image_to_window(cub->win->mlx_ptr, cub->win->win_ptr, cub->frm->ptr, 0 ,0);
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
		cub->cam->x += ((double)cub->map->blk_x / 128) * cos(cub->cam->cam_direction_yaw);
		cub->cam->y += ((double)cub->map->blk_y / 128) * sin(cub->cam->cam_direction_yaw);
	}
	if (dir == STEP_BACK)
	{
		cub->cam->x -= ((double)cub->map->blk_x / 128) * cos(cub->cam->cam_direction_yaw);
		cub->cam->y -= ((double)cub->map->blk_y / 128) * sin(cub->cam->cam_direction_yaw);
	}
	if (dir == STEP_LEFT)
	{
		cub->cam->x += ((double)cub->map->blk_x / 128) * cos(cub->cam->cam_direction_yaw + M_PI_2);
		cub->cam->y += ((double)cub->map->blk_y / 128) * sin(cub->cam->cam_direction_yaw + M_PI_2);
	}
	if (dir == STEP_RIGHT)
	{
		cub->cam->x += ((double)cub->map->blk_x / 128) * cos(cub->cam->cam_direction_yaw - M_PI_2);
		cub->cam->y += ((double)cub->map->blk_y / 128) * sin(cub->cam->cam_direction_yaw - M_PI_2);
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
		frame_col_set(frame_x, throw_ray(cub, angle), cub);
		angle -= d_angle;
		frame_x++;
	}
}

void	frame_col_set(int frame_x, double len_to_wall, t_cub *cub)
{
	int frame_y;

	double angle = cub->cam->cam_direction_pitch + cub->cam->cam_angle_pitch / 2;
	double d_angle = cub->cam->cam_angle_pitch / cub->win->y;
	double ceil_angle = atan((cub->map->blk_z - cub->cam->z) / len_to_wall);
	double flor_angle = atan((-cub->cam->z) / len_to_wall);
//	double wall_angle = ceil_angle - flor_angle;
//	double wall_angle_cur = 0;

	frame_y = 0;
	while (frame_y < cub->win->y)
	{

		if (angle > ceil_angle)
			((unsigned int *) cub->frm->data)[frame_y * cub->win->x + frame_x] = cub->tex->ceil;
		else if (angle > flor_angle)
		{

//			((unsigned int *) cub->frm->data)[frame_y * cub->win->x + frame_x] = get_pixel_texture(get_x_texture(), wall_angle_cur / wall_angle);
//			wall_angle_cur += d_angle;

			if (1)
				((unsigned int *) cub->frm->data)[frame_y * cub->win->x + frame_x] = cub->tex->flor + 50050;
//			else
//				((unsigned int *) img_data)[y_p * win_x + frame_x] = 0;
		}
		else
			((unsigned int *) cub->frm->data)[frame_y * cub->win->x + frame_x] = cub->tex->flor;

		frame_y++;
		angle -= d_angle;
	}
}

double	throw_ray(t_cub *cub, double angle)
{
	int		iterations;

	cub->ray->x = cub->cam->x;
	cub->ray->y = cub->cam->y;
	cub->ray->sin = sin(angle);
	cub->ray->cos = cos(angle);
	while (is_next_cell_free(cub) && iterations < 1000)
		iterations++;
	return (sqrt(pow(cub->ray->x - cub->cam->x, 2) + pow(cub->ray->y - cub->cam->y, 2)));
}

int		is_next_cell_free(t_cub *cub)
{
	double	cell_x;
	double	cell_y;
	double	off_x;
	double	off_y;

	off_x = modf(cub->ray->x / cub->map->blk_x, &cell_x) * cub->map->blk_x;
	off_y = modf(cub->ray->y / cub->map->blk_y, &cell_y) * cub->map->blk_y;
	find_next_cross(off_x, off_y, cub);
	if (cub->ray->dir == DIR_TOP)
		if (cub->map->field[(int)cell_y - 1][(int)cell_x] == '1')
			return (0);
	if (cub->ray->dir == DIR_BOT)
		if (cub->map->field[(int)cell_y + 1][(int)cell_x] == '1')
			return (0);
	if (cub->ray->dir == DIR_LEFT)
		if (cub->map->field[(int)cell_y][(int)cell_x - 1] == '1')
			return (0);
	if (cub->ray->dir == DIR_RIGHT)
		if (cub->map->field[(int)cell_y][(int)cell_x - 1] == '1')
			return (0);
	return (1);
}

void	find_next_cross(double off_x, double off_y, t_cub *cub)
{
	double ln_x;
	double ln_y;

	if (cub->ray->cos > 0)
		ln_x = ((double)cub->map->blk_x - off_x) / cub->ray->cos;
	else
		ln_x = -off_x / cub->ray->cos;
	if (cub->ray->sin > 0)
		ln_y = ((double)cub->map->blk_y - off_y) / cub->ray->sin;
	else
		ln_y = -off_y / cub->ray->cos;
	if (ln_x < ln_y)
	{
		cub->ray->x += ln_x * cub->ray->cos;
		cub->ray->y += ln_x * cub->ray->sin;
		cub->ray->dir = (cub->ray->cos > 0) ? DIR_LEFT : DIR_RIGHT;
	}
	else
	{
		cub->ray->x += ln_y * cub->ray->cos;
		cub->ray->y += ln_y * cub->ray->sin;
		cub->ray->dir = (cub->ray->sin > 0) ? DIR_TOP : DIR_BOT;
	}
}

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