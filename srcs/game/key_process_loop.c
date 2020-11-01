/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 12:54:47 by matrus            #+#    #+#             */
/*   Updated: 2020/11/02 00:01:41 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

# define XK_q 12
# define XK_w 13
# define XK_e 14
# define XK_a 0
# define XK_s 1
# define XK_d 2
# define XK_e 14
# define XK_Left 123
# define XK_Right 124
# define XK_Escape 53
# define XK_SPACE 49
# define XK_C 8	

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
	return (0);
}

int		esc_press(t_cub *cub)
{
	cub_destroy(cub, ERR_NO_ERR);
	return (0);
}
