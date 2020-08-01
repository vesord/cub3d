/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 10:24:59 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:38 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "bmp_bonus.h"

int		create_bmp_img(t_img *img)
{
	t_bmp_file_header	bfh;
	t_bmp_info			bmi;

	bfh.type_1 = 'B';
	bfh.type_2 = 'M';
	bfh.reserved = 0;
	bfh.size = 40 + 14 + img->btp / 8 * img->width * img->height;
	bfh.offset_to_color_bits = 40 + 14;
	bmi.size = 40;
	bmi.width = img->width;
	bmi.height = -img->height;
	bmi.planes = 1;
	bmi.btp = (short)img->btp;
	bmi.compression = 0;
	bmi.img_size = img->width * img->height;
	bmi.ppm_x = 1000;
	bmi.ppm_y = 1000;
	bmi.color_table = 0;
	bmi.color_table_size = 0;
	return (create_bmp_img_write(&bfh, &bmi, (char*)img->data));
}

int		create_bmp_img_write(t_bmp_file_header *bfh, t_bmp_info *bmi,
		char *data)
{
	int		fd;

	fd = open("cub.bmp", O_RDWR | O_CREAT, 0755);
	if (fd < 0)
		return (0);
	write(fd, &(bfh->type_1), 1);
	write(fd, &(bfh->type_2), 1);
	write(fd, &(bfh->size), 4);
	write(fd, &(bfh->reserved), 4);
	write(fd, &(bfh->offset_to_color_bits), 4);
	write(fd, &(bmi->size), 4);
	write(fd, &(bmi->width), 4);
	write(fd, &(bmi->height), 4);
	write(fd, &(bmi->planes), 2);
	write(fd, &(bmi->btp), 2);
	write(fd, &(bmi->compression), 4);
	write(fd, &(bmi->img_size), 4);
	write(fd, &(bmi->ppm_x), 4);
	write(fd, &(bmi->ppm_y), 4);
	write(fd, &(bmi->color_table), 4);
	write(fd, &(bmi->color_table_size), 4);
	write(fd, data, bmi->img_size * bmi->btp / 8);
	close(fd);
	return (1);
}
