/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_blocks_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:06:39 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:38 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "includes/cub_textures_bonus.h"

void	erase_img_in_win_blk(t_win_blk *blk, t_img *tex, t_cub *cub)
{
	int				x;
	int				y;
	unsigned int	pixel;

	y = -1;
	while (++y < blk->y_end - blk->y_start)
	{
		x = -1;
		while (++x < blk->x_end - blk->x_start)
		{
			pixel = get_pixel_tex(
				(float)(x) / (float)(blk->x_end - blk->x_start),
				(float)(y) / (float)(blk->y_end - blk->y_start), tex);
			if (pixel)
			{
				((unsigned int*)(cub->frm_0->data))[cub->win->x *
				(y + blk->y_start) + x + blk->x_start] = pixel;
				((unsigned int*)(cub->frm_1->data))[cub->win->x *
				(y + blk->y_start) + x + blk->x_start] = pixel;
			}
		}
	}
	cub->hud->need_update_weap = 1;
}

void	put_img_in_win_blk(t_win_blk *blk, t_img *tex, t_cub *cub)
{
	int				x;
	int				y;
	unsigned int	pixel;

	y = -1;
	while (++y < blk->y_end - blk->y_start)
	{
		x = -1;
		while (++x < blk->x_end - blk->x_start)
		{
			pixel = get_pixel_tex(
				(float)(x) / (float)(blk->x_end - blk->x_start),
				(float)(y) / (float)(blk->y_end - blk->y_start), tex);
			if (pixel)
			{
				((unsigned int*)(cub->frm_0->data))[
					cub->win->x * (y + blk->y_start) + x + blk->x_start] =
						pixel | HUD_TRANSP_MASK;
				((unsigned int*)(cub->frm_1->data))[
					cub->win->x * (y + blk->y_start) + x + blk->x_start] =
						pixel | HUD_TRANSP_MASK;
			}
		}
	}
}
