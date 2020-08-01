/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parse_line_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:14:18 by matrus            #+#    #+#             */
/*   Updated: 2020/07/27 13:14:21 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "config_parse.h"

size_t	parse_line_type_6(char *line, t_cub *cub)
{
	if (line[0] == 'A' && line[1] == '1' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_anim->wand_1));
	else if (line[0] == 'A' && line[1] == '2' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_anim->wand_2));
	else if (line[0] == 'A' && line[1] == '3' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_anim->wand_3));
	else if (line[0] == 'A' && line[1] == '4' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_anim->wand_4));
	else if (line[0] == 'A' && line[1] == '5' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_anim->wand_5));
	else if (line[0] == 'A' && line[1] == '6' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_anim->wand_6));
	else if (line[0] == 'A' && line[1] == '7' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->tx_anim->wand_7));
	else if (line[0] == 'F' && line[1] == ' ')
		return (parse_line_color(line, cub, &(cub->tex->flor)));
	else if (line[0] == 'C' && line[1] == ' ')
		return (parse_line_color(line, cub, &(cub->tex->ceil)));
	else if (line[0] == 'R' && line[1] == ' ')
		return (parse_line_resolution(line, cub));
	else
		return (PARSE_FAIL);
}
