/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 11:20:38 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:40 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_INIT_BONUS_H
# define CUB_INIT_BONUS_H

# include "cub3d_bonus.h"

void			cub_init_2(t_cub *cub);
void			cub_map_destroy(t_map *map);
void			cub_textures_destroy(t_textures *tex, void *mlx_ptr);
void			cub_img_destroy(t_img *img, void *mlx_ptr);
void			cub_win_destroy(t_win *win);
void			cub_ray_destroy(t_ray *ray);
void			cub_hud_destroy(t_hud *hud, void *mlx_ptr);

void			cub_init_tex_doors_set_null(t_tx_doors *tx_doors);
void			cub_textures_destroy_walls(t_tx_walls *tx_walls,
							void *mlx_ptr);
void			cub_textures_destroy_floors(t_tx_floors *tx_floors,
							void *mlx_ptr);
void			cub_textures_destroy_spr_go(t_tx_spr_go *tx_spr_go,
							void *mlx_ptr);
void			cub_textures_destroy_spr_ngo(t_tx_spr_ngo *tx_spr_ngo,
							void *mlx_ptr);
void			cub_textures_destroy_screens(t_tx_screens *tx_screens,
							void *mlx_ptr);
void			cub_textures_destroy_skybox(t_tx_skybox *tx_skybox,
							void *mlx_ptr);
void			cub_textures_destroy_doors(t_tx_doors *tx_doors,
							void *mlx_ptr);
void			cub_textures_destroy_animation(t_tx_anim *tx_anim,
							void *mlx_ptr);

void			cub_set_null(t_cub *cub);
void			cub_init_cam(t_cub *cub);
void			cub_init_map(t_cub *cub);
void			cub_init_ray(t_cub *cub);
void			cub_init_win(t_cub *cub);
void			cub_init_key(t_cub *cub);
void			cub_init_hud(t_cub *cub);
void			cub_init_textures_null(t_textures *tex);
void			cub_init_img(t_img *img);
void			cub_init_textures(t_cub *cub);
void			cub_init_textures_2(t_cub *cub);

void			cub_init_tex_walls(t_cub *cub);
void			cub_init_tex_walls_1(t_cub *cub);
void			cub_init_tex_wall_set_null(t_tx_walls *tx_walls);

void			cub_init_tex_animation(t_cub *cub);
void			cub_init_tex_animation_2(t_cub *cub);
void			cub_init_tex_animation_set_null(t_tx_anim *tx_animation);
void			cub_init_tex_doors(t_cub *cub);

void			cub_init_tex_spr_go(t_cub *cub);
void			cub_init_tex_spr_go_2(t_cub *cub);
void			cub_init_tex_spr_go_3(t_cub *cub);
void			cub_init_tex_spr_go_set_null(t_tx_spr_go *tx_spr_go);

void			cub_init_tex_spr_ngo(t_cub *cub);
void			cub_init_tex_spr_ngo_2(t_cub *cub);
void			cub_init_tex_spr_ngo_set_null(t_tx_spr_ngo *tx_spr_ngo);

void			cub_init_tex_skybox_mew(t_cub *cub);
void			cub_init_tex_skybox_rick(t_cub *cub);
void			cub_init_tex_skybox_set_null(t_tx_skybox *tx_skybox);

void			cub_init_tex_floors(t_cub *cub);
void			cub_init_tex_floors_set_null(t_tx_floors *tx_floors);

void			cub_init_tex_screens(t_cub *cub);
void			cub_init_tex_screens_set_null(t_tx_screens *tx_screens);

#endif
