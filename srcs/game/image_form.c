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

void	make_frame(t_cub *cub)
{
	int frame_x;
	double angle;
	double d_angle;

	angle = cub->cam->cam_direction_yaw - cub->cam->cam_angle_yaw / 2;
	d_angle = cub->cam->cam_angle_yaw / cub->win->x;
	frame_x = 0;
	while (frame_x < cub->win->x)
	{
		frame_col_set(frame_x, throw_ray(cub, angle), cub);
		angle += d_angle;
		frame_x++;
	}
}

void	frame_add_sprite(int frame_x, t_cub *cub);

void	frame_col_set(int frame_x, double len_to_wall, t_cub *cub)
{
	int frame_y;
	double angle = cub->cam->cam_direction_pitch + cub->cam->cam_angle_pitch / 2;
	double d_angle = cub->cam->cam_angle_pitch / cub->win->y;
	double ceil_angle = atan((cub->map->blk_z - cub->cam->z) / len_to_wall);
	double flor_angle = atan((-cub->cam->z) / len_to_wall);
	double wall_angle = ceil_angle - flor_angle;
	double wall_angle_cur = 0;

	frame_y = 0;
	while (frame_y < cub->win->y)
	{
		if (angle > ceil_angle)
			((unsigned int *) cub->frm->data)[frame_y * cub->win->x + frame_x] = cub->tex->ceil;
		else if (angle > flor_angle)
		{
			((unsigned int *) cub->frm->data)[frame_y * cub->win->x + frame_x] = get_pixel_texture(get_x_texture(cub), wall_angle_cur / wall_angle, cub, 0);
			wall_angle_cur += d_angle;
		}
		else
			((unsigned int *) cub->frm->data)[frame_y * cub->win->x + frame_x] = cub->tex->flor;
		frame_y++;
		angle -= d_angle;
	}
	if (cub->ray->sp_x > 0)
		frame_add_sprite(frame_x, cub);
}

void	frame_add_sprite(int frame_x, t_cub *cub)
{
	double angle = cub->cam->cam_direction_pitch + cub->cam->cam_angle_pitch / 2;
	double d_angle = cub->cam->cam_angle_pitch / cub->win->y;
	double ceil_angle = atan((cub->map->blk_z - cub->cam->z) / cub->ray->len_to_sp);
	double flor_angle = atan((-cub->cam->z) / cub->ray->len_to_sp);
	double wall_angle = ceil_angle - flor_angle;
	double wall_angle_cur = 0;
	int			frame_y = 0;
	unsigned int			pixel;

	while (frame_y < cub->win->y)
	{
		if (angle < ceil_angle && angle > flor_angle)
		{
			pixel = get_pixel_texture(cub->ray->sp_x, wall_angle_cur / wall_angle, cub, 1);
			if (pixel <= 255255255)
				((unsigned int *) cub->frm->data)[frame_y * cub->win->x + frame_x] = pixel;
			wall_angle_cur += d_angle;
		}
		frame_y++;
		angle -= d_angle;
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