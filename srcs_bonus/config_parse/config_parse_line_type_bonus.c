/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parse_line_type_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:14:18 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:29 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "config_parse_bonus.h"

size_t	parse_line_type(char *line, t_cub *cub)
{
	if (line[0] == 'W' && line[1] == '1' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_walls->mewni_1));
	else if (line[0] == 'W' && line[1] == '2' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_walls->mewni_2));
	else if (line[0] == 'W' && line[1] == '3' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_walls->mewni_3));
	else if (line[0] == 'W' && line[1] == '4' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_walls->ludo_1));
	else if (line[0] == 'W' && line[1] == '5' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_walls->ludo_2));
	else if (line[0] == 'W' && line[1] == '6' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_walls->ludo_3));
	else if (line[0] == 'W' && line[1] == '7' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_walls->rick_1));
	else if (line[0] == 'W' && line[1] == '8' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_walls->rick_2));
	else if (line[0] == 'W' && line[1] == 'I' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_screens->end));
	else if (line[0] == 'D' && line[1] == 'I' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_screens->die));
	else if (line[0] == 'R' && line[1] == '0' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_screens->res));
	return (parse_line_type_2(line, cub));
}

size_t	parse_line_type_2(char *line, t_cub *cub)
{
	if (line[0] == 'T' && line[1] == 'R' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_spr_go->trap));
	else if (line[0] == 'L' && line[1] == 'I' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_spr_go->life));
	else if (line[0] == 'T' && line[1] == 'U' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_spr_go->tutorial));
	else if (line[0] == 'D' && line[1] == 'W' && line[2] == ' ')
		return (parse_line_texture(line, cub,
							cub->tex->tx_spr_go->dropped_wand));
	else if (line[0] == 'P' && line[1] == 'L' && line[2] == ' ')
		return (parse_line_texture(line, cub,
							cub->tex->tx_spr_go->ludo_portal));
	else if (line[0] == 'P' && line[1] == 'R' && line[2] == ' ')
		return (parse_line_texture(line, cub,
							cub->tex->tx_spr_go->rick_portal));
	else if (line[0] == 'L' && line[1] == 'B' && line[2] == ' ')
		return (parse_line_texture(line, cub,
							cub->tex->tx_spr_go->ludo_beaten));
	else if (line[0] == 'B' && line[1] == 'B' && line[2] == ' ')
		return (parse_line_texture(line, cub,
							cub->tex->tx_spr_go->buffrog_beaten));
	else if (line[0] == 'M' && line[1] == '1' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_spr_go->mew_s_go));
	return (parse_line_type_3(line, cub));
}

size_t	parse_line_type_3(char *line, t_cub *cub)
{
	if (line[0] == 'M' && line[1] == '2' && line[2] == ' ')
		return (parse_line_texture(line, cub,
							cub->tex->tx_spr_ngo->mew_s_ngo_1));
	else if (line[0] == 'M' && line[1] == '3' && line[2] == ' ')
		return (parse_line_texture(line, cub,
							cub->tex->tx_spr_ngo->mew_s_ngo_2));
	else if (line[0] == 'L' && line[1] == '1' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_spr_go->lud_s_go));
	else if (line[0] == 'E' && line[1] == '1' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_spr_go->ric_s_go));
	else if (line[0] == 'M' && line[1] == 'O' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_spr_ngo->but_mom));
	else if (line[0] == 'D' && line[1] == 'A' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_spr_ngo->but_dad));
	else if (line[0] == 'R' && line[1] == 'S' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_spr_ngo->rick));
	else if (line[0] == 'M' && line[1] == 'S' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_spr_ngo->motry));
	else if (line[0] == 'P' && line[1] == 'H' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_spr_ngo->pony));
	else if (line[0] == 'L' && line[1] == 'U' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_spr_ngo->ludo));
	else if (line[0] == 'B' && line[1] == 'F' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_spr_ngo->buffrog));
	return (parse_line_type_4(line, cub));
}

size_t	parse_line_type_4(char *line, t_cub *cub)
{
	if (line[0] == 'L' && line[1] == '2' && line[2] == ' ')
		return (parse_line_texture(line, cub,
					cub->tex->tx_spr_ngo->lud_s_ngo_1));
	else if (line[0] == 'S' && line[1] == '0' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_sky_mew->no));
	else if (line[0] == 'S' && line[1] == '1' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_sky_mew->so));
	else if (line[0] == 'S' && line[1] == '2' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_sky_mew->we));
	else if (line[0] == 'S' && line[1] == '3' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_sky_mew->ea));
	else if (line[0] == 'S' && line[1] == '5' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_sky_rick->no));
	else if (line[0] == 'S' && line[1] == '6' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_sky_rick->so));
	else if (line[0] == 'S' && line[1] == '7' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_sky_rick->we));
	else if (line[0] == 'S' && line[1] == '8' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_sky_rick->ea));
	return (parse_line_type_5(line, cub));
}

size_t	parse_line_type_5(char *line, t_cub *cub)
{
	if (line[0] == 'F' && line[1] == 'M' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_floors->mewni));
	else if (line[0] == 'F' && line[1] == 'C' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_floors->ludo));
	else if (line[0] == 'F' && line[1] == 'E' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_floors->rick));
	else if (line[0] == 'W' && line[1] == 'A' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->hud->tx_wand));
	else if (line[0] == 'H' && line[1] == 'P' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->hud->tx_hp));
	else if (line[0] == 'F' && line[1] == 'L' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->hud->tx_face));
	else if (line[0] == 'D' && line[1] == '1' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_doors->mew_close));
	else if (line[0] == 'D' && line[1] == '2' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_doors->mew_open));
	else if (line[0] == 'D' && line[1] == '3' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_doors->lud_close));
	else if (line[0] == 'D' && line[1] == '4' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_doors->lud_open));
	else if (line[0] == 'D' && line[1] == '5' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_doors->secret_clos));
	else if (line[0] == 'D' && line[1] == '6' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_doors->secret_open));
	return (parse_line_type_6(line, cub));
}
