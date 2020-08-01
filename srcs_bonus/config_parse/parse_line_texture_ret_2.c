/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_texture_ret.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:48:33 by matrus            #+#    #+#             */
/*   Updated: 2020/08/01 12:48:34 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "config_parse.h"

size_t	parse_line_texture_ret_6(t_cub *cub, void *data)
{
	if ((cub->tex->tx_anim->wand_1) == data)
		return (PARSE_OK_A1);
	else if ((cub->tex->tx_anim->wand_2) == data)
		return (PARSE_OK_A2);
	else if ((cub->tex->tx_anim->wand_3) == data)
		return (PARSE_OK_A3);
	else if ((cub->tex->tx_anim->wand_4) == data)
		return (PARSE_OK_A4);
	else if ((cub->tex->tx_anim->wand_5) == data)
		return (PARSE_OK_A5);
	else if ((cub->tex->tx_anim->wand_6) == data)
		return (PARSE_OK_A6);
	else if ((cub->tex->tx_anim->wand_7) == data)
		return (PARSE_OK_A7);
	else if ((cub->hud->tx_face) == data)
		return (PARSE_OK_FL);
	else if ((cub->hud->tx_wand) == data)
		return (PARSE_OK_WA);
	else if ((cub->hud->tx_hp) == data)
		return (PARSE_OK_HP);
	else
		return (0);
}
