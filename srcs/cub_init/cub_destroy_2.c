/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_destroy_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 09:53:45 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 09:57:20 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_ray_destroy(t_ray *ray)
{
	t_ray_sprites *cur_spr;

	cur_spr = ray->spr;
	while (ray->spr)
	{
		cur_spr = cur_spr->next;
		free(ray->spr);
		ray->spr = cur_spr;
	}
	free(ray);
}
