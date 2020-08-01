/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_textures_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:13:29 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:42 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_TEXTURES_BONUS_H
# define CUB_TEXTURES_BONUS_H

# include "cub3d_bonus.h"

# define HUD_TRANSP_MASK 0x99000000

typedef struct	s_win_blk
{
	int	x_start;
	int	y_start;
	int	x_end;
	int	y_end;

}				t_win_blk;

void			put_img_in_win_blk(t_win_blk *blk, t_img *tex, t_cub *cub);
void			erase_img_in_win_blk(t_win_blk *blk, t_img *tex, t_cub *cub);

unsigned int	get_ceil_pixel(float angle, t_cub *cub);
unsigned int	get_wall_pixel(float len_to_wall, float angle, t_cub *cub);
unsigned int	get_flor_pixel(float angle, t_cub *cub);

unsigned int	add_shadow(unsigned int color, float len, t_cub *cub);
unsigned int	decrease_color(unsigned int color, float scaler);

unsigned int	get_pixel_tex(float off_x, float off_y, t_img *tex);
void			put_tex_to_img(t_img *tex, t_img *img, unsigned int transp);
float			get_x_tex(t_cub *cub);
float			get_y_tex(float angle, float len_to_wall, t_cub *cub);

t_img			*select_sprite(char type, t_cub *cub);
t_img			*select_sprite_2(char type, t_cub *cub);
t_img			*select_wall(char type, t_cub *cub);
t_img			*select_door(char type, t_cub *cub);

unsigned int	get_skybox_pixel(float p_angle, t_tx_skybox *sky, t_cub *cub);
unsigned int	get_skybox_pixel_tex(float off_x, float off_y, t_img *tex);
float			skybox_get_off_angle_yaw(float angle, int *dir);

#endif
