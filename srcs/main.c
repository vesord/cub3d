/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 18:46:02 by matrus            #+#    #+#             */
/*   Updated: 2020/07/10 18:46:03 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include <stdlib.h>
#include <math.h>

#include <X11/keysymdef.h>

char **map_init();

const char map[7][7] = {
	{'1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '1', '1'}
};
const int map_max_x = 6;
const int map_max_y = 6;

int blk_x = 256;
int blk_y = 256;
int blk_z = 256;

double cam_x = 256.0 + 128.0;
double cam_y = 256.0 + 128.0;
double cam_z = 160.0;
double cam_depth = 640.0;
double cam_angle_yaw = M_PI / 3.0;
double cam_direction_yaw = (4.0 * M_PI) + M_PI_4;
double cam_angle_pitch = M_PI / 3.0;
double cam_direction_pitch = 0.0;



int win_x = 640;
int win_y = 480;
unsigned int color_wall = 0xcaa472;
unsigned int color_ceil = 0x87ceeb;
unsigned int color_flor = 0x7cfc00;

int bits_per_pixel = 0, size_line = 0, endian = 0;

void make_frame(char *img_data);
double throw_ray(double angle);
int is_xy_empty(double x, double y);
void frame_col_set(void *img_data, int frame_x, double len_to_wall);

int main()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, win_x, win_y, "Just vindow");

	void *img_ptr;
	char *img_data;

	img_ptr = mlx_new_image(mlx_ptr, win_x, win_y);
	img_data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);

	mlx_key_hook(win_ptr, , NULL);
	while (1)
	{
		make_frame(img_data);
		mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	}
	return (0);
}

int is_edge = 0;

void make_frame(char *img_data)
{
	int frame_x;
	double angle = cam_direction_yaw + cam_angle_yaw / 2;
	double d_angle = cam_angle_yaw / win_x;
	frame_x = 0;
	while (frame_x < win_x)
	{
		frame_col_set(img_data, frame_x, throw_ray(angle));
		angle -= d_angle;
		frame_x++;
	}
}

double throw_ray(double angle)
{
	double ray_x;
	double ray_y;
	int iterations = 0;

	is_edge = 0;
	ray_x = cam_x;
	ray_y = cam_y;
	while (is_xy_empty(ray_x, ray_y) && iterations < 1000000)
	{
		ray_x += cos(angle);
		ray_y += sin(angle);
		iterations++;
	}
	if (!((int)ray_x % blk_x) && !((int)ray_y % blk_y))
		is_edge = 1;
	return (sqrt(pow(ray_x - cam_x, 2) + pow(ray_y - cam_y, 2)));
}

int is_xy_empty(double x, double y)
{
	int int_x;
	int int_y;

	int_x = (int)x;
	int_y = (int)y;
	int_x /= blk_x;
	int_y /= blk_y;
	if (int_x > map_max_x || int_y > map_max_y || int_y < 0 || int_x < 0)
		return (0);
	if (map[int_y][int_x] == '1')
		return (0);
	else
		return (1);
}

void frame_col_set(void *img_data, int frame_x, double len_to_wall)
{
	double angle = cam_direction_pitch + cam_angle_pitch / 2;
	double d_angle = cam_angle_pitch / win_y;
	double ceil_angle = atan((blk_z - cam_z) / len_to_wall);
	double flor_angle = atan((-cam_z) / len_to_wall);
	int y_p = 0;

	while (y_p < win_y)
	{
		if (angle > ceil_angle)
			((unsigned int *) img_data)[y_p * win_x + frame_x] = color_ceil;
		else if (angle > flor_angle)
		{
			if (!is_edge)
				((unsigned int *) img_data)[y_p * win_x + frame_x] = color_wall;
			else
				((unsigned int *) img_data)[y_p * win_x + frame_x] = 0;
		}
		else
			((unsigned int *) img_data)[y_p * win_x + frame_x] = color_flor;
		y_p++;
		angle -= d_angle;
	}
}