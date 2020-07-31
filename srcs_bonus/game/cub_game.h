/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_game.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 11:40:58 by matrus            #+#    #+#             */
/*   Updated: 2020/08/01 11:41:00 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_GAME_H
# define CUB_GAME_H

# include "cub3d_bonus.h"

# define STEP_FORWARD 1
# define STEP_BACK 2
# define STEP_RIGHT 3
# define STEP_LEFT 4

# define DIR_TOP 1
# define DIR_BOT 2
# define DIR_LEFT 3
# define DIR_RIGHT 4

# define TURN_SCALER 72
# define STEP_SCALER 16
# define WALL_SCALER 6

# define NO_SHADOW_DST 1.5f
# define FULL_SHADOW_DST 18.f

# define WORLD_LUDO 0b001
# define WORLD_RICK 0b010
# define WORLD_MEWN 0b100

# define GAME_STATUS_PLAY 0
# define GAME_STATUS_WIN 1
# define GAME_STATUS_DIE 2

# define HUD_TRANSP_MASK 0x99000000

void			frame_col_set(int f_x, float len_to_wall, t_cub *cub);

void			process_key(t_cub *cub);
void			process_step(t_cub *cub, int dir);
void			process_step_direction(float angle, t_cub *cub);

float			throw_ray(t_cub *cub, float angle, float mid_angle);
void			find_next_cross(float off_x, float off_y, t_cub *cub);
int				is_next_cell_free(t_cub *cub);
char			get_cell_map(int x, int y, t_cub *cub);
char			get_cell_ray(int x, int y, t_cub *cub);
int				is_cell_wall(char c);
int				is_cell_sprite(char c);
int				is_cell_walkable(char c);
int				is_cell_door_opened(char c);
int				is_cell_door_closed(char c);
int				is_cell_portal(char c);
int				is_cell_enemy(char c);
void			ray_set_dir(float len_x, float len_y, t_cub *cub);

t_img 			*select_sprite(char type, t_cub *cub);
t_img			*select_wall(char type, t_cub *cub);
t_img			*select_door(char type, t_cub *cub);

float			get_x_tex(t_cub *cub);
float			get_y_tex(float angle, float len_to_wall, t_cub *cub);
unsigned int	get_pixel_tex(float off_x, float off_y, t_img *tex);

void			count_sprite(char type, t_cub *cub);
t_ray_sprites	*new_sprite(t_ray_sprites *prev, char type, t_cub *cub);
float			count_sprite_x(float sp_x_mid, float sp_y_mid, t_cub *cub);

void			frame_add_sprite(int frame_x, t_cub *cub);
void			frame_add_sprite_one(int frame_x, float d_angle,
									 t_ray_sprites *spr, t_cub *cub);
t_ray_sprites	*sprites_last(t_ray_sprites *spr);

unsigned int	add_shadow(unsigned int color, float len, t_cub *cub);
unsigned int	decrease_color(unsigned int color, float scaler);

float			get_len_ceil(float angle, t_cub *cub);
float			get_len_flor(float angle, t_cub *cub);

void			update_hud(t_cub *cub);
void			add_hud_face(t_cub *cub);
void			add_hud_wand(t_cub *cub);

void			set_status_screen(t_cub *cub);

void			put_tex_to_img(t_img *tex, t_img *img, unsigned int transp);
unsigned int	get_skybox_pixel(float p_angle, t_tx_skybox *sky, t_cub *cub);

#endif
