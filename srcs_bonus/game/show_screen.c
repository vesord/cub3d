/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:29:21 by matrus            #+#    #+#             */
/*   Updated: 2020/07/27 23:29:22 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void set_status_screen(t_cub *cub)
{
	if (cub->hud->status == -1)
		put_tex_to_img(cub->tex->tx_screens->die, cub->frm_0, 0);
	else if (cub->hud->status == 1)
		put_tex_to_img(cub->tex->tx_screens->end, cub->frm_0, 0);
}