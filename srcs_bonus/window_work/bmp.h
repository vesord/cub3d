/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 11:54:12 by matrus            #+#    #+#             */
/*   Updated: 2020/08/01 11:54:13 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include "cub3d_bonus.h"

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

#endif
