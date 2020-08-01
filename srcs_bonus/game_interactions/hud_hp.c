/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_hp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 14:54:32 by matrus            #+#    #+#             */
/*   Updated: 2020/08/01 14:54:33 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_hud.h"
#include "cub_textures.h"

void	add_hud_hp(t_cub *cub)
{
	int	i;

	if (!cub->hud->need_update_hp)
		return ;
	i = -1;
	while (++i < cub->hud->hp)
	{
		put_hp_to_img(cub->win->x / 20 + i * cub->win->x / 10,
				cub->win->y / 20, cub->win->x / 20, cub);
	}
	cub->hud->need_update_hp = 0;
}

void	put_hp_to_img(int off_x, int off_y, int size, t_cub *cub)
{
	int				cur_x;
	int				cur_y;
	unsigned int	pixel;

	cur_y = -1;
	while (++cur_y < size)
	{
		cur_x = -1;
		while (++cur_x < size)
		{
			pixel = get_pixel_tex((float)cur_x / (float)size,
						(float)cur_y / (float)size, cub->hud->tx_hp);
			if (pixel)
			{
				((unsigned int*)(cub->frm_0->data))[cub->win->x *
				(cur_y + off_y) + cur_x + off_x] = pixel | HUD_TRANSP_MASK;
				((unsigned int*)(cub->frm_1->data))[cub->win->x *
				(cur_y + off_y) + cur_x + off_x] = pixel | HUD_TRANSP_MASK;
			}
		}
	}
}
