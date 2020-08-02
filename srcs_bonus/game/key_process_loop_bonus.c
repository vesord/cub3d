/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_process_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 12:54:47 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:34 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "includes/cub_init_bonus.h"
#include "includes/cub_game_bonus.h"

int		key_press(int keycode, t_cub *cub)
{
	if (keycode == XK_w)
		cub->key->w = 1;
	if (keycode == XK_a)
		cub->key->a = 1;
	if (keycode == XK_s)
		cub->key->s = 1;
	if (keycode == XK_d)
		cub->key->d = 1;
	if (keycode == XK_Left)
		cub->key->l_arrow = 1;
	if (keycode == XK_Right)
		cub->key->r_arrow = 1;
	if (keycode == XK_Shift_L)
		cub->key->shoot = 1;
	if (keycode == XK_Escape)
		esc_press(cub);
	if (keycode == XK_Control_L)
		cub->key->action = 1;
	if (keycode == XK_space)
		cub->key->jump = 1;
	if (cub->hud->status && keycode == 65293)
		restart_game(cub);
	return (0);
}

int		key_release(int keycode, t_cub *cub)
{
	if (keycode == XK_w)
		cub->key->w = 0;
	if (keycode == XK_a)
		cub->key->a = 0;
	if (keycode == XK_s)
		cub->key->s = 0;
	if (keycode == XK_d)
		cub->key->d = 0;
	if (keycode == XK_Left)
		cub->key->l_arrow = 0;
	if (keycode == XK_Right)
		cub->key->r_arrow = 0;
	if (keycode == XK_Shift_L)
		cub->key->shoot = 0;
	if (keycode == XK_Escape)
		cub->key->esc = 0;
	if (keycode == XK_Control_L)
		cub->key->action = 0;
	if (keycode == XK_space)
		cub->key->jump = 0;
	return (0);
}

int		esc_press(t_cub *cub)
{
	cub_destroy(cub, ERR_NO_ERR);
	return (0);
}

void	restart_game(t_cub *cub)
{
	cub_textures_destroy(cub->tex, cub->win->mlx_ptr);
	cub->tex = NULL;
	if (!(cub->tex = (t_textures*)malloc(sizeof(t_textures))))
		cub_destroy(cub, ERR_NO_MEMORY);
	cub_init_textures(cub);
	cub_map_destroy(cub->map);
	cub->map = NULL;
	if (!(cub->map = (t_map*)malloc(sizeof(t_map))))
		cub_destroy(cub, ERR_NO_MEMORY);
	cub_init_map(cub);
	cub->parse_is_map = 0;
	config_parse(cub->config_path, cub);
	player_init(cub);
}
