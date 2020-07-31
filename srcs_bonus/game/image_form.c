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

#include "cub3d_bonus.h"

void	check_interactions(t_cub *cub);

//
#include <time.h>
#include <stdio.h>

int		process_game(t_cub *cub)
{
	t_img *tmp_frm;

	//
//	time_t start, end;

//	start = clock();
	if (!cub->frm_0
		&& (!(cub->frm_0 = frame_init(cub->win->mlx_ptr, cub->win->x, cub->win->y))
		|| !(cub->frm_1 = frame_init(cub->win->mlx_ptr, cub->win->x, cub->win->y))))
		cub_destroy(cub, ERR_NO_MEMORY);
	process_key(cub);
	check_interactions(cub);
	update_hud(cub);
	if (!cub->hud->status)
		make_frame(cub);
	else
		set_status_screen(cub);
	mlx_put_image_to_window(cub->win->mlx_ptr, cub->win->win_ptr, cub->frm_0->ptr, 0, 0);
	tmp_frm = cub->frm_0;
	cub->frm_0 = cub->frm_1;
	cub->frm_1 = tmp_frm;
//	end = clock();
//	printf("FPS: %f\n", 1 /  ((float)(end - start) / CLOCKS_PER_SEC ));
	return (0);
}

void	make_frame(t_cub *cub)
{
	int		frame_x;
	float	angle;
	float	d_angle;

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

unsigned int	get_ceil_pixel(float angle, t_cub *cub);
unsigned int	get_wall_pixel(float len_to_wall, float angle, t_cub *cub);
unsigned int	get_flor_pixel(float angle, t_cub *cub);

void	frame_col_set(int f_x, float len_to_wall, t_cub *cub)
{
	int		f_y;
	float	angle;
	float	d_angle;
	float	c_angl;
	float	f_angl;

	len_to_wall *= cosf(cub->cam->cam_direction_pitch);
	f_angl = atanf((-cub->cam->z) / len_to_wall);
	c_angl = atanf((cub->map->blk_z - cub->cam->z) / len_to_wall);
	angle = cub->cam->cam_direction_pitch + cub->cam->cam_angle_pitch / 2;
	d_angle = cub->cam->cam_angle_pitch / cub->win->y;
	f_y = -1;

	while (++f_y < cub->win->y)
	{
		if ((((unsigned int*)cub->frm_0->data)[f_y * cub->win->x + f_x] & 0xff000000) == HUD_TRANSP_MASK)
			;
		else if (angle > c_angl)
			((unsigned int*)cub->frm_0->data)[f_y * cub->win->x + f_x] = get_ceil_pixel(angle, cub);
		else if (angle > f_angl)
			((unsigned int *) cub->frm_0->data)[f_y * cub->win->x + f_x] = get_wall_pixel(len_to_wall, angle, cub);
//				add_shadow(get_pixel_tex(1.f - get_x_tex(cub), 1.f - get_y_tex(angle, len_to_wall, cub), cub->ray->wall),
//						   len_to_wall / fabsf(cosf(fabsf(cub->ray->mid_rel_angle))), cub)))
//				((int *) cub->frm_0->data)[f_y * cub->win->x + f_x] = get_skybox_pixel(angle, cub);
		else
			((unsigned int*)cub->frm_0->data)[f_y * cub->win->x + f_x] = get_flor_pixel(angle, cub);
		angle -= d_angle;
	}
	if (cub->ray->spr)
		frame_add_sprite(f_x, cub);
}

unsigned int	get_ceil_pixel(float angle, t_cub *cub)
{
	if (cub->hud->world & WORLD_LUDO)
		return (add_shadow(cub->tex->ceil, get_len_ceil(angle, cub), cub));
	else if (cub->hud->world & WORLD_RICK)
		return (get_skybox_pixel(angle, cub->tex->tx_sky_rick, cub));
	return (get_skybox_pixel(angle, cub->tex->tx_sky_mew, cub));
}

unsigned int	get_wall_pixel(float len_to_wall, float angle, t_cub *cub)
{
	unsigned int	pixel;

	pixel = get_pixel_tex(1.f - get_x_tex(cub), 1.f - get_y_tex(angle, len_to_wall, cub), cub->ray->wall);
	if (pixel)
		return (add_shadow(pixel,  len_to_wall / fabsf(cosf(fabsf(cub->ray->mid_rel_angle))), cub));
	return (get_ceil_pixel(angle, cub));
}

unsigned int	get_flor_pixel(float angle, t_cub *cub)
{
	return (add_shadow(cub->tex->flor, get_len_flor(angle, cub), cub));
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
