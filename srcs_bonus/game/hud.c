/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:05:15 by matrus            #+#    #+#             */
/*   Updated: 2020/07/25 23:05:17 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	add_hud(t_cub *cub)
{
	//add_hud_face(cub);
	add_hud_wand(cub);
}

void	add_hud_face(t_cub *cub)
{
//	mlx_put_image_to_window(cub->win->mlx_ptr, cub->win->win_ptr, cub->hud->face->ptr, 0, 0);
	put_tex_to_img(cub->hud->face, cub->frm_0);
}

void	add_hud_wand(t_cub *cub)
{
	put_tex_to_img(cub->hud->wand, cub->frm_0);
}

unsigned int	get_pixel_texture(float off_x, float off_y, t_img *img);

void	put_tex_to_img(t_img *tex, t_img *img)
{
	int				x;
	int				y;
	unsigned int	pixel;

	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
		{
			pixel = get_pixel_texture((float)(x) / img->width, (float)(y) / img->height, tex);
			if (pixel)
				((unsigned int*)(img->data))[img->width * y + x] = pixel;
		}
	}
}

unsigned int	get_pixel_texture(float off_x, float off_y, t_img *img)
{
	return (((int*)(img->data))[img->width * (int)(img->height * off_y) + (int)(img->width * off_x)]);
}