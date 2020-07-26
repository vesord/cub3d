/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:57:13 by matrus            #+#    #+#             */
/*   Updated: 2020/07/25 19:57:14 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

unsigned int	add_shadow(unsigned int color, float len, t_cub *cub)
{
	static float	len_no_shadow;
	static float	len_full_shadow;
	float			off_shadow;

	if (!len_no_shadow)
		len_no_shadow = (float)cub->map->blk_x * NO_SHADOW_DST;
	if (!len_full_shadow)
		len_full_shadow = (float)cub->map->blk_x * (FULL_SHADOW_DST - NO_SHADOW_DST);
	if ((off_shadow = len - len_no_shadow) < 0)
		return (color);
	if (off_shadow > len_full_shadow)
		return (0);
	return (decrease_color(color, 1.f - off_shadow / len_full_shadow));

}

unsigned int	decrease_color(unsigned int color, float scaler)
{
	unsigned int	new_color;

	new_color = 0;
	new_color += (unsigned int)((color >> 24) * scaler) << 24;
	new_color += (unsigned int)((color >> 16 & 0xff) * scaler) << 16;
	new_color += (unsigned int)((color >> 8 & 0xff) * scaler) << 8;
	new_color += (unsigned int)((color & 0xff) * scaler);
	return (new_color);
}
