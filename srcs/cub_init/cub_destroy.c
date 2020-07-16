/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:10:07 by matrus            #+#    #+#             */
/*   Updated: 2020/07/15 16:10:08 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_destroy(t_cub *cub, char *msg)
{
	if (cub->confing_fd >= 0)
		close(cub->confing_fd);
	if (cub->cam)
		free(cub->cam);
	if (cub->map)
		cub_map_destroy(cub->map);
	if (cub->ray)
		free(cub->ray);
	if (cub->tex)
		cub_textures_destroy(cub->tex, cub->win->mlx_ptr);
	if (cub->win)
		cub_win_destroy(cub->win);
	free(cub);
	ft_exit(msg);
}

void	cub_win_destroy(t_win *win)
{
	if (win->win_ptr)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	if (win->mlx_ptr)
		free(win->mlx_ptr);		// ???
	free(win);
}

void	cub_textures_destroy(t_textures *tex, void *mlx_ptr)
{
	if (tex->no)
		cub_img_destroy(tex->no, mlx_ptr);
	if (tex->ea)
		cub_img_destroy(tex->ea, mlx_ptr);
	if (tex->we)
		cub_img_destroy(tex->we, mlx_ptr);
	if (tex->so)
		cub_img_destroy(tex->so, mlx_ptr);
	if (tex->s0)
		cub_img_destroy(tex->s0, mlx_ptr);
	free(tex);
}

void	cub_img_destroy(t_img *img, void *mlx_ptr)
{
	if (img->ptr)
		mlx_destroy_image(mlx_ptr, img->ptr);
//	if (img->data)
//		free(img->data);
	free(img);
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
