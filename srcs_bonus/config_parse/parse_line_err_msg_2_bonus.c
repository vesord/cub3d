/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_err_msg_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:36:36 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:29 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "config_parse_bonus.h"

char	*parse_line_err_msg_6(t_cub *cub, void *data)
{
	if ((cub->tex->tx_anim->wand_1) == data)
		return (ERR_PARSE_A1);
	else if ((cub->tex->tx_anim->wand_2) == data)
		return (ERR_PARSE_A2);
	else if ((cub->tex->tx_anim->wand_3) == data)
		return (ERR_PARSE_A3);
	else if ((cub->tex->tx_anim->wand_4) == data)
		return (ERR_PARSE_A4);
	else if ((cub->tex->tx_anim->wand_5) == data)
		return (ERR_PARSE_A5);
	else if ((cub->tex->tx_anim->wand_6) == data)
		return (ERR_PARSE_A6);
	else if ((cub->tex->tx_anim->wand_7) == data)
		return (ERR_PARSE_A7);
	else if ((cub->hud->tx_face) == data)
		return (ERR_PARSE_FL);
	else if ((cub->hud->tx_wand) == data)
		return (ERR_PARSE_WA);
	else if ((cub->hud->tx_hp) == data)
		return (ERR_PARSE_HP);
	else
		return (NULL);
}
