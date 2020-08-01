/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 12:06:33 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 10:42:53 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	window_setup(t_cub *cub)
{
	int scrn_sz_x;
	int scrn_sz_y;

	scrn_sz_x = 0;
	scrn_sz_y = 0;
	mlx_get_screen_size(cub->win->mlx_ptr, &scrn_sz_x, &scrn_sz_y);
	if (scrn_sz_x && scrn_sz_y)
	{
		if (scrn_sz_x < cub->win->x)
			cub->win->x = scrn_sz_x;
		if (scrn_sz_y < cub->win->y)
			cub->win->y = scrn_sz_y;
	}
	if (!(cub->win->win_ptr = mlx_new_window(cub->win->mlx_ptr,
		cub->win->x, cub->win->y, "Matrus's cool game!")))
		cub_destroy(cub, ERR_NO_MEMORY);
}

void	window_setup_save(t_cub *cub)
{
	int scrn_sz_x;
	int scrn_sz_y;

	scrn_sz_x = 0;
	scrn_sz_y = 0;
	mlx_get_screen_size(cub->win->mlx_ptr, &scrn_sz_x, &scrn_sz_y);
	if (scrn_sz_x && scrn_sz_y)
	{
		if (scrn_sz_x < cub->win->x)
			cub->win->x = scrn_sz_x;
		if (scrn_sz_y < cub->win->y)
			cub->win->y = scrn_sz_y;
	}
}

void	hook_initialize(t_cub *cub)
{
	mlx_mouse_hide(cub->win->mlx_ptr, cub->win->win_ptr);
	mlx_loop_hook(cub->win->mlx_ptr, process_game, cub);
	mlx_hook(cub->win->win_ptr, 4, 1L << 2, mouse_button_pess, cub);
	mlx_hook(cub->win->win_ptr, 5, 1L << 3, mouse_button_release, cub);
	mlx_hook(cub->win->win_ptr, 6, 1L << 6, mouse_move, cub);
	mlx_hook(cub->win->win_ptr, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->win->win_ptr, 3, 1L << 1, key_release, cub);
	mlx_hook(cub->win->win_ptr, 17, 1L << 17, esc_press, cub);
	mlx_loop(cub->win->mlx_ptr);
}
