/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:46:23 by matrus            #+#    #+#             */
/*   Updated: 2020/07/14 14:46:25 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CUB3D_H
# define CUB3D_CUB3D_H

#include "mlx.h"
#include "libft.h"
#include "get_next_line.h"
#include "errors.h"
#include <math.h>
#include <fcntl.h>

typedef struct	s_cam
{
	double x;
	double y;
	double z;
	double cam_angle_yaw;
	double cam_direction_yaw;
	double cam_angle_pitch;
	double cam_direction_pitch;
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

typedef struct	s_ray
{
	double x;
	double y;
	double angle;
}				t_ray;

typedef struct	s_cub
{
	t_map		*map;
	t_cam		*cam;
	t_textures	*tex;
	t_win 		*win;
	t_ray		*ray;
	int			confing_fd;
}				t_cub;

//	MAIN FUNCTIONS	//

void	cube_start(char *path_to_conf);
void	ft_exit(char *msg);
void	save_frame();

//	DESTROY FUNCTION	//

void	cub_destroy(t_cub *cub, char *err_msg);
void	cub_map_destroy(t_map *map);
void	cub_textures_destroy(t_textures *tex, void *mlx_ptr);
void	cub_img_destroy(t_img *img, void *mlx_ptr);
void	cub_win_destroy(t_win *win);

//	CUB INITIALIZATION FUNCTIONS	//

void	cub_init(t_cub *cub);
void	cub_set_null(t_cub *cub);
void	cub_init_cam(t_cub *cub);
void	cub_init_map(t_cub *cub);
void	cub_init_ray(t_cub *cub);
void	cub_init_win(t_cub *cub);
void	cub_init_textures(t_cub *cub);
void	cub_init_textures_null(t_textures *tex);
void	cub_init_img(t_img *img);

//	CONFIG PARSE FUNCTIONS	//

#define PARSE_OK		0b111111111
#define PARSE_OK_NO		0b000000001
#define PARSE_OK_WE		0b000000010
#define PARSE_OK_SO		0b000000100
#define PARSE_OK_EA		0b000001000
#define PARSE_OK_S		0b000010000
#define PARSE_OK_F		0b000100000
#define PARSE_OK_C		0b001000000
#define PARSE_OK_R		0b010000000
#define PARSE_OK_MAP	0b100000000

void	config_parse(char *path, t_cub *cub);
int		parse_line(char *line, t_cub *cub);
int		parse_line_texture(char *line, t_cub *cub, t_img *img);
int		parse_line_color(char *line, t_cub *cub, int *color);
int		parse_line_resolution(char *line, t_cub *cub);

void	add_line_to_map(char *line, t_cub *cub);
int		check_map(t_cub *cub);

void	is_line_ok_check(char *line, int is_line_ok, t_cub *cub);
int		parse_line_texture_ret(t_cub *cub, void *data);
char	*parse_line_err_msg(t_cub *cub, void *data);
int		str_to_color(char *line, int *color);

void	free_tab(void **tab);
void	**ft_realloc_tab(void **tab, int prev_size, int need_size);

#endif
