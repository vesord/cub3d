/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_err_msg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:36:36 by matrus            #+#    #+#             */
/*   Updated: 2020/08/01 12:36:37 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "config_parse.h"

char	*parse_line_err_msg(t_cub *cub, void *data)
{
	if (&(cub->tex->flor) == data)
		return (ERR_PARSE_F);
	else if (&(cub->tex->ceil) == data)
		return (ERR_PARSE_C);
	else if ((cub->tex->tx_walls->mewni_1) == data)
		return (ERR_PARSE_W1);
	else if ((cub->tex->tx_walls->mewni_2) == data)
		return (ERR_PARSE_W2);
	else if ((cub->tex->tx_walls->mewni_3) == data)
		return (ERR_PARSE_W3);
	else if ((cub->tex->tx_walls->ludo_1) == data)
		return (ERR_PARSE_W4);
	else if ((cub->tex->tx_walls->ludo_2) == data)
		return (ERR_PARSE_W5);
	else if ((cub->tex->tx_walls->ludo_3) == data)
		return (ERR_PARSE_W6);
	else if ((cub->tex->tx_walls->rick_1) == data)
		return (ERR_PARSE_W7);
	else if ((cub->tex->tx_walls->rick_2) == data)
		return (ERR_PARSE_W8);
	return (parse_line_err_msg_2(cub, data));
}

char	*parse_line_err_msg_2(t_cub *cub, void *data)
{
	if ((cub->tex->tx_floors->ludo) == data)
		return (ERR_PARSE_FC);
	else if ((cub->tex->tx_floors->rick) == data)
		return (ERR_PARSE_FE);
	else if ((cub->tex->tx_floors->mewni) == data)
		return (ERR_PARSE_FM);
	else if ((cub->tex->tx_doors->mew_close) == data)
		return (ERR_PARSE_D1);
	else if ((cub->tex->tx_doors->mew_open) == data)
		return (ERR_PARSE_D2);
	else if ((cub->tex->tx_doors->lud_close) == data)
		return (ERR_PARSE_D3);
	else if ((cub->tex->tx_doors->lud_open) == data)
		return (ERR_PARSE_D4);
	else if ((cub->tex->tx_doors->secret_clos) == data)
		return (ERR_PARSE_D5);
	else if ((cub->tex->tx_doors->secret_open) == data)
		return (ERR_PARSE_D6);
	return (parse_line_err_msg_3(cub, data));
}

char	*parse_line_err_msg_3(t_cub *cub, void *data)
{
	if ((cub->tex->tx_screens->end) == data)
		return (ERR_PARSE_WI);
	else if ((cub->tex->tx_screens->die) == data)
		return (ERR_PARSE_DI);
	else if ((cub->tex->tx_screens->res) == data)
		return (ERR_PARSE_R0);
	else if ((cub->tex->tx_sky_mew->no) == data)
		return (ERR_PARSE_S0);
	else if ((cub->tex->tx_sky_mew->so) == data)
		return (ERR_PARSE_S1);
	else if ((cub->tex->tx_sky_mew->we) == data)
		return (ERR_PARSE_S2);
	else if ((cub->tex->tx_sky_mew->ea) == data)
		return (ERR_PARSE_S3);
	else if ((cub->tex->tx_sky_rick->no) == data)
		return (ERR_PARSE_S5);
	else if ((cub->tex->tx_sky_rick->so) == data)
		return (ERR_PARSE_S6);
	else if ((cub->tex->tx_sky_rick->we) == data)
		return (ERR_PARSE_S7);
	else if ((cub->tex->tx_sky_rick->ea) == data)
		return (ERR_PARSE_S8);
	return (parse_line_err_msg_4(cub, data));
}

char	*parse_line_err_msg_4(t_cub *cub, void *data)
{
	if ((cub->tex->tx_spr_go->trap) == data)
		return (ERR_PARSE_TR);
	else if ((cub->tex->tx_spr_go->life) == data)
		return (ERR_PARSE_LI);
	else if ((cub->tex->tx_spr_go->tutorial) == data)
		return (ERR_PARSE_TU);
	else if ((cub->tex->tx_spr_go->dropped_wand) == data)
		return (ERR_PARSE_DW);
	else if ((cub->tex->tx_spr_go->ludo_portal) == data)
		return (ERR_PARSE_PL);
	else if ((cub->tex->tx_spr_go->rick_portal) == data)
		return (ERR_PARSE_PR);
	else if ((cub->tex->tx_spr_go->ludo_beaten) == data)
		return (ERR_PARSE_LB);
	else if ((cub->tex->tx_spr_go->buffrog_beaten) == data)
		return (ERR_PARSE_BB);
	else if ((cub->tex->tx_spr_go->mew_s_go) == data)
		return (ERR_PARSE_M1);
	else if ((cub->tex->tx_spr_go->lud_s_go) == data)
		return (ERR_PARSE_L1);
	else if ((cub->tex->tx_spr_go->ric_s_go) == data)
		return (ERR_PARSE_E1);
	return (parse_line_err_msg_5(cub, data));
}

char	*parse_line_err_msg_5(t_cub *cub, void *data)
{
	if ((cub->tex->tx_spr_ngo->but_mom) == data)
		return (ERR_PARSE_MO);
	else if ((cub->tex->tx_spr_ngo->but_dad) == data)
		return (ERR_PARSE_DA);
	else if ((cub->tex->tx_spr_ngo->rick) == data)
		return (ERR_PARSE_RS);
	else if ((cub->tex->tx_spr_ngo->motry) == data)
		return (ERR_PARSE_MS);
	else if ((cub->tex->tx_spr_ngo->pony) == data)
		return (ERR_PARSE_PH);
	else if ((cub->tex->tx_spr_ngo->ludo) == data)
		return (ERR_PARSE_LU);
	else if ((cub->tex->tx_spr_ngo->buffrog) == data)
		return (ERR_PARSE_BF);
	else if ((cub->tex->tx_spr_ngo->mew_s_ngo_1) == data)
		return (ERR_PARSE_M2);
	else if ((cub->tex->tx_spr_ngo->mew_s_ngo_2) == data)
		return (ERR_PARSE_M3);
	else if ((cub->tex->tx_spr_ngo->lud_s_ngo_1) == data)
		return (ERR_PARSE_L2);
	return (parse_line_err_msg_6(cub, data));
}
