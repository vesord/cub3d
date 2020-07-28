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
	size_t	is_parse_ok;
	char	*line;
	size_t	is_line_ok;

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

void	gnl_func_parse(char *line, size_t *is_parse_ok, t_cub *cub)
{
	size_t	parse_res;

	if (*line && *line != '#')
	{
		parse_res = parse_line(line, cub);
		if (parse_res & *is_parse_ok)
		{
			free(line);
			cub_destroy(cub, ERR_PARSE_DUPLICATE);
		}
		else
			*is_parse_ok |= parse_res;
	}
	free(line);
}

size_t parse_line(char *line, t_cub *cub)
{
	size_t		ret;

	if (!cub->parse_is_map)
	{
		ret = parse_line_type(line, cub);
		if (ret != PARSE_FAIL)
			return (ret);
		cub->parse_is_map = 1;
	}
	add_line_to_map(line, cub);
	return (0);
}
