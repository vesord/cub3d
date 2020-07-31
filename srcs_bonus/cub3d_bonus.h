/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:46:23 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 11:22:48 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "errors_bonus.h"
# include <math.h>
# include <fcntl.h>

# define XK_MISCELLANY
# define XK_LATIN1
# include <X11/keysymdef.h>

typedef struct	s_cam
{
	float x;
	float y;
	float z;
	float cam_angle_yaw;
	float cam_direction_yaw;
	float cam_angle_pitch;
	float cam_direction_pitch;
	float step;
	float dst_to_wall;
}				t_cam;

typedef struct	s_img
{
	void	*ptr;
	void	*data;
	int		width;
	int		height;
	int		btp;
	int		sz_ln;
	int		endian;
}				t_img;

typedef	struct	s_tx_walls
{
	t_img	*mewni_1;
	t_img	*mewni_2;
	t_img	*mewni_3;
	t_img	*ludo_1;
	t_img	*ludo_2;
	t_img	*ludo_3;
	t_img	*rick_1;
	t_img	*rick_2;
}				t_tx_walls;

typedef struct	s_tx_sprites_go
{
	t_img	*trap;
	t_img	*life;
	t_img	*dropped_wand;
	t_img	*ludo_portal;
	t_img	*rick_portal;
	t_img	*tutorial;
	t_img	*ludo_beaten;
	t_img	*buffrog_beaten;
	t_img	*mew_s_go;
	t_img	*lud_s_go;
	t_img	*ric_s_go;
}				t_tx_spr_go;

typedef struct	s_tx_sprites_ngo
{
	t_img	*but_mom;
	t_img	*but_dad;
	t_img	*rick;
	t_img	*motry;
	t_img	*pony;
	t_img	*ludo;
	t_img	*buffrog;
	t_img	*mew_s_ngo_1;
	t_img	*mew_s_ngo_2;
	t_img	*lud_s_ngo_1;
}				t_tx_spr_ngo;

typedef struct	s_tx_skybox
{
	t_img	*no;
	t_img	*we;
	t_img	*ea;
	t_img	*so;
}				t_tx_skybox;

typedef struct	s_tx_screens
{
	t_img	*end;
	t_img	*die;
	t_img	*res;
}				t_tx_screens;

typedef	struct	s_tx_floors
{
	t_img	*mewni;
	t_img	*ludo;
	t_img	*rick;
}				t_tx_floors;

typedef struct	s_tx_doors
{
	t_img	*mew_open;
	t_img	*mew_close;
	t_img	*secret_open;
	t_img	*secret_close;
	t_img	*lud_open;
	t_img	*lud_close;
}				t_tx_doors;

typedef struct	s_tx_anim
{
	t_img	*wand_1;
	t_img	*wand_2;
	t_img	*wand_3;
	t_img	*wand_4;
	t_img	*wand_5;
	t_img	*wand_6;
	t_img	*wand_7;
}				t_tx_anim;

typedef struct	s_textures
{
	t_tx_walls			*tx_walls;
	t_tx_spr_go			*tx_spr_go;
	t_tx_spr_ngo		*tx_spr_ngo;
	t_tx_skybox			*tx_sky_mew;
	t_tx_skybox			*tx_sky_rick;
	t_tx_screens		*tx_screens;
	t_tx_floors			*tx_floors;
	t_tx_doors			*tx_doors;
	t_tx_anim			*tx_anim;
	int		flor;
	int		ceil;
}				t_textures;

typedef struct	s_map
{
	char	**field;
	int		max_x;
	int		max_y;
	int		blk_x;
	int		blk_y;
	int		blk_z;
}				t_map;

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
}				t_win;

typedef struct	s_ray_sprites
{
	struct s_ray_sprites	*next;
	struct s_ray_sprites	*prev;
	t_img					*tex;
	float					len_to_sp;
	float					sp_x;
}				t_ray_sprites;

typedef struct	s_ray_enemy
{
	int		x;
	int		y;
	char	type;
	float	dst;
}				t_ray_enemy;

typedef struct	s_ray
{
	float			x;
	float			y;
	float			mid_rel_angle;
	float			len_to_wall_real;
	float			walk_dst;
	float			sin;
	float			cos;
	float			angle;
	int				dir;
	t_img			*wall;
	t_ray_sprites	*spr;
	t_ray_enemy		enemy;
}				t_ray;

typedef struct	s_key
{
	int	w;
	int a;
	int s;
	int d;
	int l_arrow;
	int r_arrow;
	int	shoot;
	int	esc;
	int action;
	int	jump;
}				t_key;

typedef struct	s_hud
{
	t_img	*tx_face;
	t_img	*tx_wand;
	t_img	*tx_hp;
	int		hp;
	int 	status;
	int 	jumping;
	int		need_update_face;
	int		need_update_weap;
	int		need_update_hp;
	int		teleported;
	int		shooting;
	int		world;
	int		has_wand;
}				t_hud;

typedef struct	s_cub
{
	t_map		*map;
	t_cam		*cam;
	t_textures	*tex;
	t_win		*win;
	t_ray		*ray;
	t_key		*key;
	t_hud		*hud;
	t_img		*frm_0;
	t_img		*frm_1;
	char 		*config_path;
	int			parse_is_map;
	int			confing_fd;
}				t_cub;

void			cube_start(char *path_to_conf);
void			ft_exit(char *msg);
void			save_frame(char *path_to_conf);

void			cub_init(t_cub *cub);
void			cub_destroy(t_cub *cub, char *err_msg);

void			cam_init(t_cub *cub);
void			map_set_scales(t_cub *cub);
void			player_init(t_cub *cub);

void			make_frame(t_cub *cub);
t_img			*frame_init(void *mlx_ptr, int x, int y);

int				process_game(t_cub *cub);
int				mouse_button_pess(int button, int x, int y, t_cub *cub);
int				mouse_button_release(int button, int x, int y, t_cub *cub);
int				mouse_move(int x, int y, t_cub *cub);
int				key_press(int keycode, t_cub *cub);
int				key_release(int keycode, t_cub *cub);
int				esc_press(t_cub *cub);

void			config_parse(char *path, t_cub *cub);

void			window_setup(t_cub *cub);
void			window_setup_save(t_cub *cub);
void			hook_initialize(t_cub *cub);

#endif
