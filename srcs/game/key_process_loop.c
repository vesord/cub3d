/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 12:54:47 by matrus            #+#    #+#             */
/*   Updated: 2020/07/17 12:54:48 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//
#include <stdio.h>

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
	if (keycode == XK_Escape)
		cub->key->esc = 1;
	printf("%i key pressed\n", keycode);
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
	if (keycode == XK_Escape)
		cub->key->esc = 0;
	printf("%i key released\n", keycode);
	return (0);
}

int		esc_press(t_cub *cub)
{
	if (cub)
	{}
	ft_putendl_fd("Esc pressed!!!", 1);
	return (0);
}


