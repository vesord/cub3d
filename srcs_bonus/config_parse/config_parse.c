/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:25:59 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 10:35:07 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	config_parse(char *path, t_cub *cub)
{
	int		is_parse_ok;
	char	*line;
	int		is_line_ok;

	if (!check_path(path) || (cub->confing_fd = open(path, O_RDONLY)) < 0)
		cub_destroy(cub, NULL);
	is_parse_ok = 0;
	while ((is_line_ok = get_next_line(cub->confing_fd, &line)) > 0)
		gnl_func_parse(line, &is_parse_ok, cub);
	is_line_ok_check(line, is_line_ok, cub);
	gnl_func_parse(line, &is_parse_ok, cub);
	is_parse_ok |= check_map(cub);
	if ((is_parse_ok & PARSE_OK) != PARSE_OK)
		cub_destroy(cub, ERR_PARSE);
}

void	gnl_func_parse(char *line, int *is_parse_ok, t_cub *cub)
{
	int parse_res;

	if (*line)
	{
		parse_res = parse_line(line, cub);
		if (parse_res & *is_parse_ok)
			cub_destroy(cub, ERR_PARSE_DUPLICATE);
		else
			*is_parse_ok |= parse_res;
	}
	free(line);
}

int		parse_line(char *line, t_cub *cub)
{
	static int	is_map;
	int			ret;

	if (!is_map)
	{
		ret = parse_line_conf(line, cub);
		if (ret >= 0)
			return (ret);
		is_map = 1;
	}
	add_line_to_map(line, cub);
	return (0);
}

int		parse_line_conf(char *line, t_cub *cub)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->no));
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->we));
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->ea));
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (parse_line_texture(line, cub, cub->tex->so));
	else if (line[0] == 'S' && line[1] == ' ')
		return (parse_line_texture(line, cub, cub->tex->s0));
	else if (line[0] == 'F' && line[1] == ' ')
		return (parse_line_color(line, cub, &(cub->tex->flor)));
	else if (line[0] == 'C' && line[1] == ' ')
		return (parse_line_color(line, cub, &(cub->tex->ceil)));
	else if (line[0] == 'R' && line[1] == ' ')
		return (parse_line_resolution(line, cub));
	else if (line[0] == 'H' && line[1] == 'F')
		return (parse_line_texture(line, cub, cub->hud->face));
	else if (line[0] == 'H' && line[1] == 'W')
		return (parse_line_texture(line, cub, cub->hud->wand));
	else
		return (-1);
}
