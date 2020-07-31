/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 22:44:09 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 10:01:33 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "config_parse.h"

int		check_path(char *path)
{
	int len;

	len = ft_strlen(path);
	if (len > 4)
		return (!ft_strncmp((path + len - 4), ".cub", 4));
	return (0);
}

void	is_line_ok_check(char *line, int is_line_ok, t_cub *cub)
{
	if (is_line_ok == -1)
	{
		free(line);
		cub_destroy(cub, ERR_READ_CONFIG);
	}
	if (is_line_ok == -2)
		cub_destroy(cub, ERR_NO_MEMORY);
}

int		str_to_color(char *line, int *color)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(line);
	if (!(ft_isdigit(*line)) || r < 0 || r > 255 || line[ft_ilen(r)] != ',')
		return (0);
	line += ft_ilen(r) + 1;
	g = ft_atoi(line);
	if (!(ft_isdigit(*line)) || g < 0 || g > 255 || line[ft_ilen(g)] != ',')
		return (0);
	line += ft_ilen(g) + 1;
	b = ft_atoi(line);
	if (!(ft_isdigit(*line)) || g < 0 || g > 255)
		return (0);
	*color = 0 | (r << 16) | (g << 8) | (b << 0);
	return (1);
}

char	*parse_line_err_msg(t_cub *cub, void *data)
{
	if (&(cub->tex->flor) == data)
		return (ERR_PARSE_F);
	else if (&(cub->tex->ceil) == data)
		return (ERR_PARSE_C);

	else if ((cub->tex->tx_floors->ludo) == data)
		return (ERR_PARSE_FC);
	else if ((cub->tex->tx_floors->rick) == data)
		return (ERR_PARSE_FE);
	else if ((cub->tex->tx_floors->mewni) == data)
		return (ERR_PARSE_FM);

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

	else if ((cub->tex->tx_screens->end) == data)
		return (ERR_PARSE_WI);
	else if ((cub->tex->tx_screens->die) == data)
		return (ERR_PARSE_DI);
	else if ((cub->tex->tx_screens->res) == data)
		return (ERR_PARSE_R0);

	else if ((cub->tex->tx_spr_go->trap) == data)
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

	else if ((cub->tex->tx_spr_ngo->but_mom) == data)
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

	else if ((cub->tex->tx_doors->mew_close) == data)
		return (ERR_PARSE_D1);
	else if ((cub->tex->tx_doors->mew_open) == data)
		return (ERR_PARSE_D2);
	else if ((cub->tex->tx_doors->lud_close) == data)
		return (ERR_PARSE_D3);
	else if ((cub->tex->tx_doors->lud_open) == data)
		return (ERR_PARSE_D4);
	else if ((cub->tex->tx_doors->secret_close) == data)
		return (ERR_PARSE_D5);
	else if ((cub->tex->tx_doors->secret_open) == data)
		return (ERR_PARSE_D6);

	else if ((cub->tex->tx_anim->wand_1) == data)
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

size_t		parse_line_texture_ret(t_cub *cub, void *data)
{
	if (&(cub->tex->flor) == data)
		return (PARSE_OK_F);
	else if (&(cub->tex->ceil) == data)
		return (PARSE_OK_C);

	else if ((cub->tex->tx_floors->ludo) == data)
		return (PARSE_OK_FC);
	else if ((cub->tex->tx_floors->rick) == data)
		return (PARSE_OK_FE);
	else if ((cub->tex->tx_floors->mewni) == data)
		return (PARSE_OK_FM);

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

	else if ((cub->tex->tx_screens->end) == data)
		return (PARSE_OK_WI);
	else if ((cub->tex->tx_screens->die) == data)
		return (PARSE_OK_DI);
	else if ((cub->tex->tx_screens->res) == data)
		return (PARSE_OK_R0);

	else if ((cub->tex->tx_spr_go->trap) == data)
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

	else if ((cub->tex->tx_spr_ngo->but_mom) == data)
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

	else if ((cub->tex->tx_doors->mew_close) == data)
		return (PARSE_OK_D1);
	else if ((cub->tex->tx_doors->mew_open) == data)
		return (PARSE_OK_D2);
	else if ((cub->tex->tx_doors->lud_close) == data)
		return (PARSE_OK_D3);
	else if ((cub->tex->tx_doors->lud_open) == data)
		return (PARSE_OK_D4);
	else if ((cub->tex->tx_doors->secret_close) == data)
		return (PARSE_OK_D5);
	else if ((cub->tex->tx_doors->secret_open) == data)
		return (PARSE_OK_D6);
	
	else if ((cub->tex->tx_anim->wand_1) == data)
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

	return (0);
}
