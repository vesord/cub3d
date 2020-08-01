/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_throw_sprites_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:58:24 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:34 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_textures_bonus.h"
#include "cub_game_bonus.h"

void			count_sprite(char type, t_cub *cub)
{
	t_ray_sprites	*spr;

	spr = cub->ray->spr;
	if (!spr)
	{
		cub->ray->spr = new_sprite(NULL, type, cub);
		return ;
	}
	else
		while (spr->next)
			spr = spr->next;
	spr->next = new_sprite(spr, type, cub);
}

t_ray_sprites	*new_sprite(t_ray_sprites *prev, char type, t_cub *cub)
{
	t_ray_sprites	*new_spr;
	float			sp_y_mid;
	float			sp_x_mid;

	if (!(new_spr = (t_ray_sprites*)malloc(sizeof(t_ray_sprites))))
		cub_destroy(cub, ERR_NO_MEMORY);
	new_spr->next = NULL;
	new_spr->prev = prev;
	new_spr->tex = select_sprite(type, cub);
	modff(cub->ray->x / cub->map->blk_x, &sp_x_mid);
	modff(cub->ray->y / cub->map->blk_y, &sp_y_mid);
	sp_x_mid = (sp_x_mid + 0.5f) * cub->map->blk_x;
	sp_y_mid = (sp_y_mid + 0.5f) * cub->map->blk_y;
	new_spr->len_to_sp = sqrtf(powf(sp_x_mid - cub->cam->x, 2) +
		pow(sp_y_mid - cub->cam->y, 2));
	new_spr->sp_x = count_sprite_x(sp_x_mid, sp_y_mid, cub);
	return (new_spr);
}

float			count_sprite_x(float sp_x_mid, float sp_y_mid, t_cub *cub)
{
	float dist_to_mid;
	float sp_x;

	sp_x_mid = sp_x_mid - cub->ray->x;
	sp_y_mid = sp_y_mid - cub->ray->y;
	dist_to_mid = cub->ray->cos * sp_y_mid + -cub->ray->sin * sp_x_mid;
	sp_x = ((cub->map->blk_x / 2) + dist_to_mid);
	if (sp_x < 0 || sp_x > cub->map->blk_x)
		sp_x = -1.f;
	return (sp_x / cub->map->blk_x);
}
