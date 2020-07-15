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

typedef struct	s_textures
{
	void	*no_ptr;
	char	*no_data;
	void	*ea_ptr;
	char	*ea_data;
	void	*so_ptr;
	char	*so_data;
	void	*we_ptr;
	char	*we_data;
	void	*s0_ptr;
	char	*s0_data;
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
void	cub_win_destroy(t_win *win);

//	CUB INITIALIZATION FUNCTIONS	//

void	cub_init(t_cub *cub);
void	cub_set_null(t_cub *cub);
void	cub_init_cam(t_cub *cub);
void	cub_init_map(t_cub *cub);
void	cub_init_ray(t_cub *cub);
void	cub_init_win(t_cub *cub);
void	cub_init_textures(t_cub *cub);

//	CONFIG PARSE FUNCTIONS	//

#define


#endif
