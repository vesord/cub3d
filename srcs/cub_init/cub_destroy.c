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
	if (tex->no_data)
		mlx_destroy_image(mlx_ptr, tex->no_ptr);
	if (tex->no_data)
		free(tex->no_data);
	if (tex->ea_ptr)
		mlx_destroy_image(mlx_ptr, tex->ea_ptr);
	if (tex->ea_data)
		free(tex->ea_data);
	if (tex->we_ptr)
		mlx_destroy_image(mlx_ptr, tex->we_ptr);
	if (tex->we_data)
		free(tex->we_data);
	if (tex->so_ptr)
		mlx_destroy_image(mlx_ptr, tex->so_ptr);
	if (tex->so_data)
		free(tex->so_data);
	if (tex->s0_ptr)
		mlx_destroy_image(mlx_ptr, tex->s0_ptr);
	if (tex->s0_data)
		free(tex->s0_data);
	free(tex);
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
