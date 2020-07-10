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

int main(int argc, char **argv)
{
	void *mlx_ptr;
	void *win_ptr;

	if (argc || argv)
	{}

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 640, 480, "Just vindow");


	int x = 320;
	int y = 240;
	int g_offset = 0;
	int off = 0;
	int dir = 0;
	int dva = 0;
	unsigned int color = 0;

	while (win_ptr)
	{
		g_offset++;
		off = g_offset;
		dva = 2;
		while (dva--)
		{
			if (g_offset < 50)
				continue;
			while (off)
			{
				if (dir == 0)
					mlx_pixel_put(mlx_ptr, win_ptr, x++, y, color + 127000255);
				if (dir == 1)
					mlx_pixel_put(mlx_ptr, win_ptr, x, y++, color + 100100);
				if (dir == 2)
					mlx_pixel_put(mlx_ptr, win_ptr, x--, y, color + + 64000127);
				if (dir == 3)
					mlx_pixel_put(mlx_ptr, win_ptr, x, y--, color + 100100);
				off--;
			}
			off = g_offset;
			dir = (dir + 1) % 4;
			//color += rand() % 65536;
			usleep(10000);
		}
	}

	return (0);
}
