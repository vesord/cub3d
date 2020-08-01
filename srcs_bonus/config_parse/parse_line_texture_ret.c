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

size_t	parse_line_texture_ret(t_cub *cub, void *data)
{
	if (&(cub->tex->flor) == data)
		return (PARSE_OK_F);
	else if (&(cub->tex->ceil) == data)
		return (PARSE_OK_C);
	else if ((cub->tex->tx_walls->mewni_1) == data)
		return (PARSE_OK_W1);
	else if ((cub->tex->tx_walls->mewni_2) == data)
		return (PARSE_OK_W2);
	else if ((cub->tex->tx_walls->mewni_3) == data)
		return (PARSE_OK_W3);
	else if ((cub->tex->tx_walls->ludo_1) == data)
		return (PARSE_OK_W4);
	else if ((cub->tex->tx_walls->ludo_2) == data)
		return (PARSE_OK_W5);
	else if ((cub->tex->tx_walls->ludo_3) == data)
		return (PARSE_OK_W6);
	else if ((cub->tex->tx_walls->rick_1) == data)
		return (PARSE_OK_W7);
	else if ((cub->tex->tx_walls->rick_2) == data)
		return (PARSE_OK_W8);
	return (parse_line_texture_ret_2(cub, data));
}

size_t	parse_line_texture_ret_2(t_cub *cub, void *data)
{
	if ((cub->tex->tx_floors->ludo) == data)
		return (PARSE_OK_FC);
	else if ((cub->tex->tx_floors->rick) == data)
		return (PARSE_OK_FE);
	else if ((cub->tex->tx_floors->mewni) == data)
		return (PARSE_OK_FM);
	else if ((cub->tex->tx_doors->mew_close) == data)
		return (PARSE_OK_D1);
	else if ((cub->tex->tx_doors->mew_open) == data)
		return (PARSE_OK_D2);
	else if ((cub->tex->tx_doors->lud_close) == data)
		return (PARSE_OK_D3);
	else if ((cub->tex->tx_doors->lud_open) == data)
		return (PARSE_OK_D4);
	else if ((cub->tex->tx_doors->secret_clos) == data)
		return (PARSE_OK_D5);
	else if ((cub->tex->tx_doors->secret_open) == data)
		return (PARSE_OK_D6);
	return (parse_line_texture_ret_3(cub, data));
}

size_t	parse_line_texture_ret_3(t_cub *cub, void *data)
{
	if ((cub->tex->tx_screens->end) == data)
		return (PARSE_OK_WI);
	else if ((cub->tex->tx_screens->die) == data)
		return (PARSE_OK_DI);
	else if ((cub->tex->tx_screens->res) == data)
		return (PARSE_OK_R0);
	else if ((cub->tex->tx_sky_mew->no) == data)
		return (PARSE_OK_S0);
	else if ((cub->tex->tx_sky_mew->so) == data)
		return (PARSE_OK_S1);
	else if ((cub->tex->tx_sky_mew->we) == data)
		return (PARSE_OK_S2);
	else if ((cub->tex->tx_sky_mew->ea) == data)
		return (PARSE_OK_S3);
	else if ((cub->tex->tx_sky_rick->no) == data)
		return (PARSE_OK_S5);
	else if ((cub->tex->tx_sky_rick->so) == data)
		return (PARSE_OK_S6);
	else if ((cub->tex->tx_sky_rick->we) == data)
		return (PARSE_OK_S7);
	else if ((cub->tex->tx_sky_rick->ea) == data)
		return (PARSE_OK_S8);
	return (parse_line_texture_ret_4(cub, data));
}

size_t	parse_line_texture_ret_4(t_cub *cub, void *data)
{
	if ((cub->tex->tx_spr_go->trap) == data)
		return (PARSE_OK_TR);
	else if ((cub->tex->tx_spr_go->life) == data)
		return (PARSE_OK_LI);
	else if ((cub->tex->tx_spr_go->tutorial) == data)
		return (PARSE_OK_TU);
	else if ((cub->tex->tx_spr_go->dropped_wand) == data)
		return (PARSE_OK_DW);
	else if ((cub->tex->tx_spr_go->ludo_portal) == data)
		return (PARSE_OK_PL);
	else if ((cub->tex->tx_spr_go->rick_portal) == data)
		return (PARSE_OK_PR);
	else if ((cub->tex->tx_spr_go->ludo_beaten) == data)
		return (PARSE_OK_LB);
	else if ((cub->tex->tx_spr_go->buffrog_beaten) == data)
		return (PARSE_OK_BB);
	else if ((cub->tex->tx_spr_go->mew_s_go) == data)
		return (PARSE_OK_M1);
	else if ((cub->tex->tx_spr_go->lud_s_go) == data)
		return (PARSE_OK_L1);
	else if ((cub->tex->tx_spr_go->ric_s_go) == data)
		return (PARSE_OK_E1);
	return (parse_line_texture_ret_5(cub, data));
}

size_t	parse_line_texture_ret_5(t_cub *cub, void *data)
{
	if ((cub->tex->tx_spr_ngo->but_mom) == data)
		return (PARSE_OK_MO);
	else if ((cub->tex->tx_spr_ngo->but_dad) == data)
		return (PARSE_OK_DA);
	else if ((cub->tex->tx_spr_ngo->rick) == data)
		return (PARSE_OK_RS);
	else if ((cub->tex->tx_spr_ngo->motry) == data)
		return (PARSE_OK_MS);
	else if ((cub->tex->tx_spr_ngo->pony) == data)
		return (PARSE_OK_PH);
	else if ((cub->tex->tx_spr_ngo->ludo) == data)
		return (PARSE_OK_LU);
	else if ((cub->tex->tx_spr_ngo->buffrog) == data)
		return (PARSE_OK_BF);
	else if ((cub->tex->tx_spr_ngo->mew_s_ngo_1) == data)
		return (PARSE_OK_M2);
	else if ((cub->tex->tx_spr_ngo->mew_s_ngo_2) == data)
		return (PARSE_OK_M3);
	else if ((cub->tex->tx_spr_ngo->lud_s_ngo_1) == data)
		return (PARSE_OK_L2);
	return (parse_line_texture_ret_6(cub, data));
}
