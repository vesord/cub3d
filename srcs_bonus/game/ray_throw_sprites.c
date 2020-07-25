/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_throw_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:58:24 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 11:10:09 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		count_sprite(char type, t_cub *cub)
{
	t_sprites	*spr;

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

t_sprites	*new_sprite(t_sprites *prev, char type, t_cub *cub)
{
	t_sprites	*new_spr;
	double		sp_y_mid;
	double		sp_x_mid;

	if (!(new_spr = (t_sprites*)malloc(sizeof(t_sprites))))
		cub_destroy(cub, ERR_NO_MEMORY);
	new_spr->next = NULL;
	new_spr->prev = prev;
	if (type == '2')
		new_spr->tex_data = cub->tex->s0->data;
	modf(cub->ray->x / cub->map->blk_x, &sp_x_mid);
	modf(cub->ray->y / cub->map->blk_y, &sp_y_mid);
	sp_x_mid = (sp_x_mid + 0.5) * cub->map->blk_x;
	sp_y_mid = (sp_y_mid + 0.5) * cub->map->blk_y;
	new_spr->len_to_sp = sqrt(pow(sp_x_mid - cub->cam->x, 2) +
		pow(sp_y_mid - cub->cam->y, 2));
	new_spr->sp_x = count_sprite_x(sp_x_mid, sp_y_mid, cub);
	return (new_spr);
}

double		count_sprite_x(double sp_x_mid, double sp_y_mid, t_cub *cub)
{
	double dist_to_mid;
	double sp_x;

	sp_x_mid = sp_x_mid - cub->ray->x;
	sp_y_mid = sp_y_mid - cub->ray->y;
	dist_to_mid = cub->ray->cos * sp_y_mid + -cub->ray->sin * sp_x_mid;
	sp_x = ((cub->map->blk_x / 2) + dist_to_mid);
	if (sp_x < 0 || sp_x > cub->map->blk_x)
		sp_x = -1.;
	return (sp_x / cub->map->blk_x);
}
