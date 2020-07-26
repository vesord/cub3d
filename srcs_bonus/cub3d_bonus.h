/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
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

typedef struct	s_textures
{
	t_img	*no;
	t_img	*ea;
	t_img	*we;
	t_img	*so;
	t_img	*s0;
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

typedef struct	s_sprites
{
	struct s_sprites	*next;
	struct s_sprites	*prev;
	t_img				*tex_data;
	float				len_to_sp;
	float				sp_x;
}				t_sprites;

typedef struct	s_ray
{
	float		x;
	float		y;
	float		mid_rel_angle;
	float		len_to_wall_real;
	float		sin;
	float		cos;
	int			dir;
	t_sprites	*spr;
}				t_ray;

typedef struct	s_key
{
	int	w;
	int a;
	int s;
	int d;
	int l_arrow;
	int r_arrow;
	int	esc;
}				t_key;

typedef struct	s_hud
{
	int		life;
	t_img	*face;
	t_img	*wand;
	int 	mana;
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

void			cub_init(t_cub *cub);
void			cub_set_null(t_cub *cub);
void			cub_init_cam(t_cub *cub);
void			cub_init_map(t_cub *cub);
void			cub_init_ray(t_cub *cub);
void			cub_init_win(t_cub *cub);
void			cub_init_key(t_cub *cub);
void			cub_init_hud(t_cub *cub);
void			cub_init_textures(t_cub *cub);
void			cub_init_textures_null(t_textures *tex);
void			cub_init_img(t_img *img);

void			cam_init(t_cub *cub);
void			map_set_scales(t_cub *cub);
void			player_init(t_cub *cub);

/*
**	---CONFIG_PARSE_FUNCTIONS---
*/

# define PARSE_OK		0b11111111111
# define PARSE_OK_NO	0b00000000001
# define PARSE_OK_WE	0b00000000010
# define PARSE_OK_SO	0b00000000100
# define PARSE_OK_EA	0b00000001000
# define PARSE_OK_S		0b00000010000
# define PARSE_OK_F		0b00000100000
# define PARSE_OK_C		0b00001000000
# define PARSE_OK_R		0b00010000000
# define PARSE_OK_HF	0b00100000000
# define PARSE_OK_HW	0b01000000000
# define PARSE_OK_MAP	0b10000000000

void			config_parse(char *path, t_cub *cub);
void			gnl_func_parse(char *line, int *is_parse_ok, t_cub *cub);
int				parse_line(char *line, t_cub *cub);
int				parse_line_conf(char *line, t_cub *cub);

int				parse_line_texture(char *line, t_cub *cub, t_img *img);
int				parse_line_color(char *line, t_cub *cub, int *color);
int				parse_line_resolution(char *line, t_cub *cub);

void			add_line_to_map(char *line, t_cub *cub);
int				check_map(t_cub *cub);

int				check_path(char *path);
void			is_line_ok_check(char *line, int is_line_ok, t_cub *cub);
int				parse_line_texture_ret(t_cub *cub, void *data);
char			*parse_line_err_msg(t_cub *cub, void *data);
int				str_to_color(char *line, int *color);

int				is_map_chars_correct(const char *crct, t_cub *cub);
int				map_find_player(t_cub *cub);
void			map_set_player(int pl_x, int pl_y, t_cub *cub);

int				is_map_surrounded(t_cub *cub);
void			is_map_surrounded_set(int *x_start, int *y_start, t_cub *cub);
int				is_map_surrounded_recursive(int x, int y, t_cub *cub);
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
char			get_cell(int x, int y, t_cub *cub);
int				is_cell_free(char c);
void			ray_set_dir(float len_x, float len_y, t_cub *cub);

float			get_x_wall(t_cub *cub);
float			get_y_wall(float angle, float len_to_wall, t_cub *cub);
unsigned int	get_pixel_wall(float off_x, float off_y, t_cub *cub,
							   int is_sp);

void			count_sprite(char type, t_cub *cub);
t_sprites		*new_sprite(t_sprites *prev, char type, t_cub *cub);
float			count_sprite_x(float sp_x_mid, float sp_y_mid, t_cub *cub);

void			frame_add_sprite(int frame_x, t_cub *cub);
void			frame_add_sprite_one(int frame_x, float d_angle,
	t_sprites *spr, t_cub *cub);
t_sprites		*sprites_last(t_sprites *spr);

/*
**	---BONUS_FUNCTIONS---
*/

#define NO_SHADOW_DST 1.5f
#define FULL_SHADOW_DST 18.f

unsigned int	add_shadow(unsigned int color, float len, t_cub *cub);
unsigned int	decrease_color(unsigned int color, float scaler);

float	get_len_ceil(float angle, t_cub *cub);
float	get_len_flor(float angle, t_cub *cub);

void	add_hud(t_cub *cub);
void	add_hud_face(t_cub *cub);
void	add_hud_wand(t_cub *cub);

void	put_tex_to_img(t_img *tex, t_img *img);

#endif
