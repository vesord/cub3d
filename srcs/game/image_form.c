/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 12:54:42 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 11:09:46 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		process_game(t_cub *cub)
{
	t_img *tmp_frm;

	if (!cub->frm_0 && !(cub->frm_0 = frame_init(cub->win->mlx_ptr,
		cub->win->x, cub->win->y)) && !(cub->frm_1 =
			frame_init(cub->win->mlx_ptr, cub->win->x, cub->win->y)))
		cub_destroy(cub, ERR_NO_MEMORY);
	process_key(cub);
	make_frame(cub);
	mlx_put_image_to_window(cub->win->mlx_ptr, cub->win->win_ptr,
							cub->frm_0->ptr, 0, 0);
	tmp_frm = cub->frm_0;
	cub->frm_0 = cub->frm_1;
	cub->frm_1 = tmp_frm;
	return (0);
}

void	make_frame(t_cub *cub)
{
	int		frame_x;
	double	angle;
	double	d_angle;

	angle = cub->cam->cam_direction_yaw - cub->cam->cam_angle_yaw / 2;
	d_angle = cub->cam->cam_angle_yaw / cub->win->x;
	frame_x = 0;
	while (frame_x < cub->win->x)
	{
		frame_col_set(frame_x, throw_ray(cub, angle,
			cub->cam->cam_direction_yaw), cub);
		angle += d_angle;
		frame_x++;
	}
}

void	frame_col_set(int f_x, double len_to_wall, t_cub *cub)
{
	int		f_y;
	double	angle;
	double	d_angle;
	double	c_angl;
	double	f_angl;

	f_angl = atan((-cub->cam->z) / len_to_wall);
	c_angl = atan((cub->map->blk_z - cub->cam->z) / len_to_wall);
	angle = cub->cam->cam_direction_pitch + cub->cam->cam_angle_pitch / 2;
	d_angle = cub->cam->cam_angle_pitch / cub->win->y;
	f_y = -1;
	while (++f_y < cub->win->y)
	{
		if (angle > c_angl)
			((int*)cub->frm_0->data)[f_y * cub->win->x + f_x] = cub->tex->ceil;
		else if (angle > f_angl)
			((unsigned int*)cub->frm_0->data)[f_y * cub->win->x + f_x] =
				get_pixel_wall(1. - get_x_wall(cub),
				1. - get_y_wall(angle, len_to_wall, cub), cub, 0);
		else
			((int*)cub->frm_0->data)[f_y * cub->win->x + f_x] = cub->tex->flor;
		angle -= d_angle;
	}
	if (cub->ray->spr)
		frame_add_sprite(f_x, cub);
}

t_img	*frame_init(void *mlx_ptr, int x, int y)
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
