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
#include <math.h>
#include <stdio.h>

char **map_init();

const char map[14][14] = {
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '0', '1'},
	{'1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '0', '1', '0', '0', '1', '1', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '1', '1', '0', '0', '1', '1', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '1'},
	{'1', '0', '1', '0', '1', '1', '0', '0', '1', '1', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '0', '1', '0', '0', '1', '1', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};
const int map_max_x = 14;
const int map_max_y = 13;

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

void *img_ptr;
void *jon_ptr;
char *img_data;
char *jon_data;
void *mlx_ptr;
void *win_ptr;

int win_x = 1024;
int win_y = 760;
unsigned int color_wall = 0xcaa472;
unsigned int color_ceil = 0x87ceeb;
unsigned int color_flor = 0x7cfc00;

int j_height, j_width;

int bits_per_pixel = 0, size_line = 0, endian = 0;

void make_frame();
double throw_ray(double angle);
int is_xy_empty(double x, double y);
void frame_col_set(int frame_x, double len_to_wall);
unsigned int add_shade(unsigned int color, double len_to_wall);

int key_press(int keycode)
{
	ft_putnbr_fd(keycode, 1);
	ft_putendl_fd("", 1);
	if (keycode == 'w')
	{
		cam_x += ((double)blk_x / 3) * cos(cam_direction_yaw);
		cam_y += ((double)blk_x / 3) * sin(cam_direction_yaw);
	}
	if (keycode == 's')
	{
		cam_x -= ((double)blk_x / 3) * cos(cam_direction_yaw);
		cam_y -= ((double)blk_x / 3) * sin(cam_direction_yaw);
	}
	if (keycode == 'a')
	{
		cam_x += ((double)blk_x / 3) * cos(cam_direction_yaw + M_PI_2);
		cam_y += ((double)blk_x / 3) * sin(cam_direction_yaw + M_PI_2);
	}
	if (keycode == 'd')
	{
		cam_x += ((double)blk_x / 3) * cos(cam_direction_yaw - M_PI_2);
		cam_y += ((double)blk_x / 3) * sin(cam_direction_yaw - M_PI_2);
	}
	if (keycode == 65361 || keycode == 'q')
		cam_direction_yaw += M_PI / 72;
	if (keycode == 65363 || keycode == 'e')
		cam_direction_yaw -= M_PI / 72;
	ft_putendl_fd("Im leaving key_press()!", 1);
	return (0);
}

int expose()
{
	ft_putendl_fd("Im in expose()!", 1);
	return (0);
}

int img_update()
{
	make_frame();
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	return (0);
}

int main()
{
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, win_x, win_y, "Just vindow");
	img_ptr = mlx_new_image(mlx_ptr, win_x, win_y);
	img_data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);

	jon_ptr = mlx_xpm_file_to_image(mlx_ptr, "./imgs/Johny2.xpm", &j_width, &j_height);
	jon_data = mlx_get_data_addr(jon_ptr, &bits_per_pixel, &size_line, &endian);
	mlx_put_image_to_window(mlx_ptr, win_ptr, jon_ptr, 0, 0);


	mlx_do_key_autorepeaton(mlx_ptr);
	mlx_hook(win_ptr, 2, 1L<<0, key_press, NULL);
	mlx_key_hook(win_ptr, key_press, NULL);
	mlx_loop_hook(mlx_ptr, img_update, NULL);
	mlx_loop(mlx_ptr);

	return (0);
}

int is_edge = 0;

void make_frame()
{
	int frame_x;
	double angle = cam_direction_yaw + cam_angle_yaw / 2;
	double d_angle = cam_angle_yaw / win_x;
	frame_x = 0;
	while (frame_x < win_x)
	{
		frame_col_set(frame_x, throw_ray(angle));
		angle -= d_angle;
		frame_x++;
	}
}

double ray_x;
double ray_y;

double throw_ray(double angle)
{
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

int ray_x_prev = 1; // default player position
int ray_y_prev = 1;
int ray_grid_dir = 0; // 0 - right, 1 - top, 2 - left, 3 - bot.
void count_ray_dir(int x_prev, int y_prev, int x, int y);

int is_xy_empty(double x, double y)
{
	int int_x;
	int int_y;

	int_x = (int) x;
	int_y = (int) y;
	int_x /= blk_x;
	int_y /= blk_y;

	// for texturing ray
	if (int_x != ray_x_prev)
	{
		count_ray_dir(ray_x_prev, ray_y_prev, int_x, int_y);
		ray_x_prev = int_x;
	}
	if (int_y != ray_y_prev)
	{
		count_ray_dir(ray_x_prev, ray_y_prev, int_x, int_y);
		ray_y_prev = int_y;
	}

	if (int_x > map_max_x || int_y > map_max_y || int_y < 0 || int_x < 0)
		return (0);
	if (map[int_y][int_x] == '1')
		return (0);
	else
		return (1);
}

void count_ray_dir(int x_prev, int y_prev, int x, int y)
{
	if (y > y_prev)
		ray_grid_dir = 3;
	if (y < y_prev)
		ray_grid_dir = 1;
	if (x > x_prev)
		ray_grid_dir = 0;
	if (x < x_prev)
		ray_grid_dir = 2;
}

double get_x_texture();
unsigned int get_pixel_texture(double off_x, double off_y);

void frame_col_set(int frame_x, double len_to_wall)
{
	double angle = cam_direction_pitch + cam_angle_pitch / 2;
	double d_angle = cam_angle_pitch / win_y;
	double ceil_angle = atan((blk_z - cam_z) / len_to_wall);
	double flor_angle = atan((-cam_z) / len_to_wall);
	double wall_angle = ceil_angle - flor_angle;
	double wall_angle_cur = 0;
	int y_p = 0;

	while (y_p < win_y)
	{
		if (angle > ceil_angle)
			((unsigned int *) img_data)[y_p * win_x + frame_x] = color_ceil;
		else if (angle > flor_angle)
		{

			((unsigned int *) img_data)[y_p * win_x + frame_x] = get_pixel_texture(get_x_texture(), wall_angle_cur / wall_angle);
			wall_angle_cur += d_angle;

//			if (!is_edge)
//				((unsigned int *) img_data)[y_p * win_x + frame_x] = add_shade(color_wall, len_to_wall);
//			else
//				((unsigned int *) img_data)[y_p * win_x + frame_x] = 0;
		}
		else
			((unsigned int *) img_data)[y_p * win_x + frame_x] = color_flor;
		y_p++;
		angle -= d_angle;
	}
}

double get_x_texture()
{
	if (ray_grid_dir == 0)
		return (1. - (ray_y / (double)blk_y - (size_t)(ray_y / (double)blk_y)));
	else if (ray_grid_dir == 1)
		return (ray_x / (double)blk_x - (size_t)(ray_x / (double)blk_x));
	else if (ray_grid_dir == 2)
		return (ray_y / (double)blk_y - (size_t)(ray_y / (double)blk_y));
	else
		return (1. - (ray_x / (double)blk_x - (size_t)(ray_x / (double)blk_x)));
}

unsigned int get_pixel_texture(double off_x, double off_y)
{
	return ((unsigned int *)jon_data)[(int)((double)j_height * off_y) * j_width + (int)((double)j_width * off_x)];
}

unsigned int add_shade(unsigned int color, double len_to_wall)
{
	double shade_coef = -len_to_wall / blk_x / 6 + 1;
	unsigned int new_color = 0;

	if (shade_coef < 0.6)
		shade_coef = 0.6;
	new_color |= (unsigned int)((double)((color >> 16) & 0xff) * shade_coef) << 16;
	new_color |= (unsigned int)((double)((color >> 8) & 0xff) * shade_coef) << 8;
	new_color |= (unsigned int)((double)((color >> 0) & 0xff) * shade_coef) << 0;
	return (new_color);
}
