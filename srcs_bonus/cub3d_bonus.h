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

typedef struct	s_ray
{
	float		x;
	float		y;
	float		mid_rel_angle;
	float		len_to_wall_real;
	float		walk_dst;
	float		sin;
	float		cos;
	float		angle;
	int			dir;
	t_img		*wall;
	t_ray_sprites	*spr;
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
	int		rick_world;
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

/*
**	---MAIN_FUNCTIONS---
*/

void			cube_start(char *path_to_conf);
void			ft_exit(char *msg);
void			save_frame(char *path_to_conf);

/*
**	---INITIALIZE_AND_DESTROY_FUNCTIONS---
*/

void			cub_destroy(t_cub *cub, char *err_msg);
void			cub_map_destroy(t_map *map);
void			cub_textures_destroy(t_textures *tex, void *mlx_ptr);
void			cub_img_destroy(t_img *img, void *mlx_ptr);
void			cub_win_destroy(t_win *win);
void			cub_ray_destroy(t_ray *ray);
void			cub_hud_destroy(t_hud *hud, void *mlx_ptr);


void			cub_textures_destroy_walls(t_tx_walls *tx_walls, void *mlx_ptr);
void			cub_textures_destroy_floors(t_tx_floors *tx_floors, void *mlx_ptr);
void			cub_textures_destroy_spr_go(t_tx_spr_go *tx_spr_go, void *mlx_ptr);
void			cub_textures_destroy_spr_ngo(t_tx_spr_ngo *tx_spr_ngo, void *mlx_ptr);
void			cub_textures_destroy_screens(t_tx_screens *tx_screens, void *mlx_ptr);
void			cub_textures_destroy_skybox(t_tx_skybox *tx_skybox, void *mlx_ptr);
void			cub_textures_destroy_doors(t_tx_doors *tx_doors, void *mlx_ptr);
void			cub_textures_destroy_animation(t_tx_anim *tx_anim, void *mlx_ptr);

void			cub_init(t_cub *cub);
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

void			cub_init_tex_walls(t_cub *cub);
void			cub_init_tex_walls_1(t_cub *cub);
void			cub_init_tex_wall_set_null(t_tx_walls *tx_walls);

void			cub_init_tex_animation(t_cub *cub);
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

void			cam_init(t_cub *cub);
void			map_set_scales(t_cub *cub);
void			player_init(t_cub *cub);

/*
**	---CONFIG_PARSE_FUNCTIONS---
*/

# define PARSE_OK		0x7fffffffffffffff
# define PARSE_FAIL		0x8000000000000000

# define PARSE_OK_W1	0x0000000000000001
# define PARSE_OK_W2	0x0000000000000002
# define PARSE_OK_W3	0x0000000000000004
# define PARSE_OK_W4	0x0000000000000008
# define PARSE_OK_W5	0x0000000000000010
# define PARSE_OK_W6	0x0000000000000020
# define PARSE_OK_W7	0x0000000000000040
# define PARSE_OK_W8	0x0000000000000080

# define PARSE_OK_WI	0x0000000000000100
# define PARSE_OK_DI	0x0000000000000200
# define PARSE_OK_R0	0x0000000000000400

# define PARSE_OK_TR	0x0000000000000800
# define PARSE_OK_LI	0x0000000000001000
# define PARSE_OK_DW	0x0000000000002000
# define PARSE_OK_PL	0x0000000000004000
# define PARSE_OK_PR	0x0000000000008000
# define PARSE_OK_TU	0x0000000000010000
# define PARSE_OK_LB	0x0000000000020000
# define PARSE_OK_BB	0x0000000000040000
# define PARSE_OK_M1	0x0000000000080000
# define PARSE_OK_L1	0x0000000000100000
# define PARSE_OK_E1	0x0000000000200000

# define PARSE_OK_MO	0x0000000000400000
# define PARSE_OK_DA	0x0000000000800000
# define PARSE_OK_RS	0x0000000001000000
# define PARSE_OK_MS	0x0000000002000000
# define PARSE_OK_PH	0x0000000004000000
# define PARSE_OK_LU	0x0000000008000000
# define PARSE_OK_BF	0x0000000010000000
# define PARSE_OK_M2	0x0000000020000000
# define PARSE_OK_M3	0x0000000040000000
# define PARSE_OK_L2	0x0000000080000000

# define PARSE_OK_S0	0x0000000100000000
# define PARSE_OK_S1	0x0000000200000000
# define PARSE_OK_S2	0x0000000400000000
# define PARSE_OK_S3	0x0000000800000000

# define PARSE_OK_S5	0x0000001000000000
# define PARSE_OK_S6	0x0000002000000000
# define PARSE_OK_S7	0x0000004000000000
# define PARSE_OK_S8	0x0000008000000000

# define PARSE_OK_WA	0x0000010000000000
# define PARSE_OK_HP	0x0000020000000000
# define PARSE_OK_FL	0x0000040000000000

# define PARSE_OK_FM	0x0000080000000000
# define PARSE_OK_FE	0x0000100000000000
# define PARSE_OK_FC	0x0000200000000000

# define PARSE_OK_D1	0x0000400000000000
# define PARSE_OK_D2	0x0000800000000000
# define PARSE_OK_D3	0x0001000000000000
# define PARSE_OK_D4	0x0002000000000000
# define PARSE_OK_D5	0x0004000000000000
# define PARSE_OK_D6	0x0008000000000000

# define PARSE_OK_A1	0x0010000000000000
# define PARSE_OK_A2	0x0020000000000000
# define PARSE_OK_A3	0x0040000000000000
# define PARSE_OK_A4	0x0080000000000000
# define PARSE_OK_A5	0x0100000000000000
# define PARSE_OK_A6	0x0200000000000000
# define PARSE_OK_A7	0x0400000000000000

# define PARSE_OK_C		0x0800000000000000
# define PARSE_OK_F		0x1000000000000000
# define PARSE_OK_R		0x2000000000000000
# define PARSE_OK_MAP	0x4000000000000000


void			config_parse(char *path, t_cub *cub);
void			gnl_func_parse(char *line, size_t *is_parse_ok, t_cub *cub);
size_t parse_line(char *line, t_cub *cub);
size_t parse_line_type(char *line, t_cub *cub);

size_t			parse_line_texture(char *line, t_cub *cub, t_img *img);
size_t			parse_line_color(char *line, t_cub *cub, int *color);
size_t			parse_line_resolution(char *line, t_cub *cub);

void			add_line_to_map(char *line, t_cub *cub);
size_t			check_map(t_cub *cub);

int				check_path(char *path);
void			is_line_ok_check(char *line, int is_line_ok, t_cub *cub);
size_t			parse_line_texture_ret(t_cub *cub, void *data);
char			*parse_line_err_msg(t_cub *cub, void *data);
int				str_to_color(char *line, int *color);

int				is_map_chars_correct(const char *crct, t_cub *cub);
int				map_check_player_pos(t_cub *cub);
void			map_set_player(int pl_x, int pl_y, t_cub *cub);
int				is_map_portals_correct(t_cub *cub);

int				is_map_surrounded(t_cub *cub);
void			is_map_surrounded_set(const char *starts, t_cub *cub);
int				is_map_surrounded_recursive(int x, int y, int strt, t_cub *cub);
void			is_map_surrounded_recover(t_cub *cub);

/*
**	---WINDOW_FUNCTIONS---
*/

void			window_setup(t_cub *cub);
void			window_setup_save(t_cub *cub);
void			hook_initialize(t_cub *cub);

typedef struct	s_bmp_file_header
{
	char	type_1;
	char	type_2;
	int		size;
	int		reserved;
	int		offset_to_color_bits;
}				t_bmp_file_header;

typedef struct	s_bmp_info
{
	int		size;
	int		width;
	int		height;
	short	planes;
	short	btp;
	int		compression;
	int		img_size;
	int		ppm_x;
	int		ppm_y;
	int		color_table;
	int		color_table_size;
}				t_bmp_info;

int				create_bmp_img(t_img *img);
int				create_bmp_img_write(t_bmp_file_header *bfh, t_bmp_info *bmi,
	char *data);

/*
**	---GAME_FUNCTIONS---
*/

int				key_press(int keycode, t_cub *cub);
int				key_release(int keycode, t_cub *cub);
int				esc_press(t_cub *cub);

# define STEP_FORWARD 1
# define STEP_BACK 2
# define STEP_RIGHT 3
# define STEP_LEFT 4

# define DIR_TOP 1
# define DIR_BOT 2
# define DIR_LEFT 3
# define DIR_RIGHT 4

int				process_game(t_cub *cub);
void			make_frame(t_cub *cub);
void			frame_col_set(int f_x, float len_to_wall, t_cub *cub);
t_img			*frame_init(void *mlx_ptr, int x, int y);

# define TURN_SCALER 72
# define STEP_SCALER 10
# define WALL_SCALER 6

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
void			ray_set_dir(float len_x, float len_y, t_cub *cub);

t_img 			*select_sprite(char type, t_cub *cub);
t_img			*select_wall(char type, t_cub *cub);
t_img			*select_door(char type, t_cub *cub);

float			get_x_tex(t_cub *cub);
float			get_y_tex(float angle, float len_to_wall, t_cub *cub);
unsigned int get_pixel_tex(float off_x, float off_y, t_img *tex);

void			count_sprite(char type, t_cub *cub);
t_ray_sprites	*new_sprite(t_ray_sprites *prev, char type, t_cub *cub);
float			count_sprite_x(float sp_x_mid, float sp_y_mid, t_cub *cub);

void			frame_add_sprite(int frame_x, t_cub *cub);
void			frame_add_sprite_one(int frame_x, float d_angle,
									 t_ray_sprites *spr, t_cub *cub);
t_ray_sprites		*sprites_last(t_ray_sprites *spr);

/*
**	---BONUS_FUNCTIONS---
*/

#define NO_SHADOW_DST 1.5f
#define FULL_SHADOW_DST 18.f

unsigned int	add_shadow(unsigned int color, float len, t_cub *cub);
unsigned int	decrease_color(unsigned int color, float scaler);

float	get_len_ceil(float angle, t_cub *cub);
float	get_len_flor(float angle, t_cub *cub);

#define HUD_TRANSP_MASK 0x99000000

void	update_hud(t_cub *cub);
void	add_hud_face(t_cub *cub);
void	add_hud_wand(t_cub *cub);

void	set_status_screen(t_cub *cub);

void put_tex_to_img(t_img *tex, t_img *img, unsigned int transp);
unsigned int		get_skybox_pixel(float p_angle, t_cub *cub);


int		mouse_button_pess(int button, int x, int y, t_cub *cub);
int		mouse_button_release(int button, int x, int y, t_cub *cub);
int		mouse_move(int x, int y, t_cub *cub);

#endif
