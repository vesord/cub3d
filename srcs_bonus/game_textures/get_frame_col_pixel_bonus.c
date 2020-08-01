/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_pixel_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 13:04:55 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:34 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_game_bonus.h"
#include "cub_textures_bonus.h"

unsigned int	get_ceil_pixel(float angle, t_cub *cub)
{
	if (cub->hud->world & WORLD_LUDO)
		return (add_shadow(cub->tex->ceil, get_len_ceil(angle, cub), cub));
	else if (cub->hud->world & WORLD_RICK)
		return (get_skybox_pixel(angle, cub->tex->tx_sky_rick, cub));
	return (get_skybox_pixel(angle, cub->tex->tx_sky_mew, cub));
}

unsigned int	get_wall_pixel(float len_to_wall, float angle, t_cub *cub)
{
	unsigned int	pixel;

	pixel = get_pixel_tex(1.f - get_x_tex(cub),
			1.f - get_y_tex(angle, len_to_wall, cub), cub->ray->wall);
	if (pixel)
		return (add_shadow(pixel,
		len_to_wall / fabsf(cosf(fabsf(cub->ray->mid_rel_angle))), cub));
	else
		return (get_ceil_pixel(angle, cub));
}

unsigned int	get_flor_pixel(float angle, t_cub *cub)
{
	return (add_shadow(cub->tex->flor, get_len_flor(angle, cub), cub));
}
