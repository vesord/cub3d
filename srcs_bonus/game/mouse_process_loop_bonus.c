/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_process_loop_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 11:55:16 by matrus            #+#    #+#             */
/*   Updated: 2020/11/02 00:09:46 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "includes/cub_game_bonus.h"

int		mouse_button_pess(int button, int x, int y, t_cub *cub)
{
	if (x || y)
	{
		;
	}
	if (button == 1)
		cub->key->shoot = 1;
	return (0);
}

int		mouse_button_release(int button, int x, int y, t_cub *cub)
{
	if (x || y)
	{
		;
	}
	if (button == 1)
		cub->key->shoot = 0;
	return (0);
}

/*
int		mouse_move(int x, int y, t_cub *cub)
{
	static int	prev_x;

	if (y)
	{
		;
	}
	if (prev_x)
		cub->cam->cam_direction_yaw +=
			(float)(M_PI / TURN_SCALER) * (x - prev_x) / 4;
	prev_x = x;
	if (x < 20 || x > cub->win->x - 20)
	{
		prev_x = 0;
		mlx_mouse_move(cub->win->mlx_ptr, cub->win->win_ptr,
			cub->win->x / 2, cub->win->y / 2);
	}
	return (0);
}*/
