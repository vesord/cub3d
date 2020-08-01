/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_destroy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:10:07 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:29 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_init_bonus.h"

void	cub_destroy(t_cub *cub, char *msg)
{
	if (cub->confing_fd >= 0)
		close(cub->confing_fd);
	if (cub->cam)
		free(cub->cam);
	if (cub->map)
		cub_map_destroy(cub->map);
	if (cub->ray)
		cub_ray_destroy(cub->ray);
	if (cub->key)
		free(cub->key);
	if (cub->hud)
		cub_hud_destroy(cub->hud, cub->win->mlx_ptr);
	if (cub->frm_0)
		cub_img_destroy(cub->frm_0, cub->win->mlx_ptr);
	if (cub->frm_1)
		cub_img_destroy(cub->frm_1, cub->win->mlx_ptr);
	if (cub->tex)
		cub_textures_destroy(cub->tex, cub->win->mlx_ptr);
	if (cub->win)
		cub_win_destroy(cub->win);
	free(cub);
	if (ft_strncmp(ERR_DESTROY_NO_EXIT, msg, 20))
		ft_exit(msg);
}

void	cub_win_destroy(t_win *win)
{
	if (win->win_ptr)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	if (win->mlx_ptr)
		free(win->mlx_ptr);
	free(win);
}

void	cub_map_destroy(t_map *map)
{
	int i;

	i = 0;
	while ((map->field)[i])
	{
		free((map->field)[i]);
		i++;
	}
	free(map->field);
	free(map);
}

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

void	cub_hud_destroy(t_hud *hud, void *mlx_ptr)
{
	if (hud->tx_face)
		cub_img_destroy(hud->tx_face, mlx_ptr);
	if (hud->tx_wand)
		cub_img_destroy(hud->tx_wand, mlx_ptr);
	if (hud->tx_hp)
		cub_img_destroy(hud->tx_hp, mlx_ptr);
	free(hud);
}
