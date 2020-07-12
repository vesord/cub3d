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

double cam_x = 1024.0 + 512.0;
double cam_y = 1024.0 + 512.0;
double cam_z;
double cam_depth = 640.0;
double cam_angle = M_PI / 3.0;
double cam_direction = (4.0 * M_PI) + M_PI_2;
int blk_x = 1024;
int blk_y = 1024;
int blk_z = 1024;
int win_x = 640;
int win_y = 480;
unsigned int wall_color = 0xcaa472;
unsigned int ceil_color = 0x87ceeb;
unsigned int flor_color = 0x7cfc00;

int bits_per_pixel = 0, size_line = 0, endian = 0;

void make_frame(char *img_data);
double throw_ray(double angle);
int is_xy_empty(double x, double y);

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

	while (1)
	{
		make_frame(img_data);
		mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	}



//	int col;
//	int line;
//	int col_total = size_line / (bits_per_pixel / 8);
//	for (int times = 0; times < 20; times++)
//	{
//		line = 0;
//		while (line < 240)
//		{
//			col = 0;
//			while (col < col_total)
//			{
//				((unsigned int *) img_data)[line * col_total + col] = color++;
//				col++;
//			}
//			line++;
//		}
//
//		ft_putendl_fd("step", 1);
//	}

	return (0);
}


void make_frame(char *img_data)
{
//	int col_total = size_line / (bits_per_pixel / 8); // probably to frame_col_set();
	int frame_x;

	double angle = cam_direction + cam_angle / 2;
	double d_angle = cam_angle / win_x;
	frame_x = 0;
	while (frame_x < win_x)
	{
		double test = throw_ray(angle);
		if (test || img_data)
		{}
		//frame_col_set(img_data, frame_x, throw_ray(angle));
		angle -= d_angle;
		frame_x++;
	}
}

double throw_ray(double angle)
{
	double ray_x;
	double ray_y;
	int iterations = 0;

	ray_x = cam_x;
	ray_y = cam_y;
	while (is_xy_empty(ray_x, ray_y) && iterations < 1000000)
	{
		ray_x += cos(angle);
		ray_y += sin(angle);
		iterations++;
	}
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