/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 16:23:09 by matrus            #+#    #+#             */
/*   Updated: 2020/07/27 16:23:11 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_img	*select_sprite(char type, t_cub *cub)
{
	if (type == '*')
		return (cub->tex->tx_spr_go->trap);
	else if (type == '$')
		return (cub->tex->tx_spr_go->life);
	else if (type == '?')
		return (cub->tex->tx_spr_go->tutorial);
	else if (type == 'w')
		return (cub->tex->tx_spr_go->dropped_wand);
	else if (type == 'c')
		return (cub->tex->tx_spr_go->ludo_portal);
	else if (type == 'e')
		return (cub->tex->tx_spr_go->rick_portal);
	else if (type == 'l')
		return (cub->tex->tx_spr_go->ludo_beaten);
	else if (type == 'b')
		return (cub->tex->tx_spr_go->buffrog_beaten);
	else if (type == 'g')
		return (cub->tex->tx_spr_go->mew_s_go);
	else if (type == 'j')
		return (cub->tex->tx_spr_go->lud_s_go);
	else if (type == 'p')
		return (cub->tex->tx_spr_go->ric_s_go);
	else if (type == 'M')
		return (cub->tex->tx_spr_ngo->but_mom);
	else if (type == 'D')
		return (cub->tex->tx_spr_ngo->but_dad);
	else if (type == 'R')
		return (cub->tex->tx_spr_ngo->rick);
	else if (type == 'O')
		return (cub->tex->tx_spr_ngo->motry);
	else if (type == 'P')
		return (cub->tex->tx_spr_ngo->pony);
	else if (type == 'L')
		return (cub->tex->tx_spr_ngo->ludo);
	else if (type == 'B')
		return (cub->tex->tx_spr_ngo->buffrog);
	else if (type == 'G')
		return (cub->tex->tx_spr_ngo->mew_s_ngo_1);
	else if (type == 'H')
		return (cub->tex->tx_spr_ngo->mew_s_ngo_2);
	else if (type == 'J')
		return (cub->tex->tx_spr_ngo->lud_s_ngo_1);
	else if (type == 'K')
		return (cub->tex->tx_spr_ngo->lud_s_ngo_2);
	else if (type == 'y')
		return (cub->tex->tx_doors->secret_open);
	else if (type == 'q')
		return (cub->tex->tx_doors->mew_open);
	else if (type == 'u')
		return (cub->tex->tx_doors->lud_open);
	return (cub->tex->tx_spr_go->life);
}

t_img	*select_door(char type, t_cub *cub)
{
	if (type == 'Y')
		return (cub->tex->tx_doors->secret_close);
	else if (type == 'Q')
		return (cub->tex->tx_doors->mew_close);
	else if (type == 'U')
		return (cub->tex->tx_doors->lud_close);
	return (cub->tex->tx_doors->secret_close);
}

t_img	*select_wall(char type, t_cub *cub)
{
	if (type == '1')
		return (cub->tex->tx_walls->mewni_1);
	else if (type == '2')
		return (cub->tex->tx_walls->mewni_2);
	else if (type == '3')
		return (cub->tex->tx_walls->mewni_3);
	else if (type == '4')
		return (cub->tex->tx_walls->ludo_1);
	else if (type == '5')
		return (cub->tex->tx_walls->ludo_2);
	else if (type == '6')
		return (cub->tex->tx_walls->ludo_3);
	else if (type == '7')
		return (cub->tex->tx_walls->rick_1);
	else if (type == '8')
		return (cub->tex->tx_walls->rick_2);
	return (cub->tex->tx_walls->wall_9);
}