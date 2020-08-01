/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hud_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:01:42 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:41 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_HUD_BONUS_H
# define CUB_HUD_BONUS_H

# include "cub3d_bonus.h"
# include "cub_textures_bonus.h"

void	add_hud_face(t_cub *cub);
void	add_hud_wand(t_cub *cub);
void	process_jumping(t_cub *cub);

void	put_hp_to_img(int off_x, int off_y, int size, t_cub *cub);
void	add_hud_hp(t_cub *cub);

void	add_hud_shooting(t_cub *cub);
void	draw_rainbow_blast(t_cub *cub);
void	check_enemies(t_cub *cub);
void	win_blk_rb_init(t_win_blk *blk, t_cub *cub);

void	process_action(t_cub *cub);
float	get_walk_len_dir(float angle, t_cub *cub);

void	get_player_pos(int *x, int *y, t_cub *cub);
void	check_trap(int x, int y, t_cub *cub);
void	check_life(int x, int y, t_cub *cub);
void	check_portal(int x, int y, t_cub *cub);
void	check_wand(int x, int y, t_cub *cub);
void	map_find_portal(char cell, int *x_st, int *y_st, t_cub *cub);
void	select_world(char cell, t_cub *cub);

#endif
