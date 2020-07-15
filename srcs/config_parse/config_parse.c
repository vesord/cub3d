/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:25:59 by matrus            #+#    #+#             */
/*   Updated: 2020/07/15 16:26:00 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	RESOLUTION
** 	R		1920 1080
** 	TEXTURES
** 	NO		./path_to_the_north_texture
** 	EA		./path_to_the_east_texture
** 	WE		./path_to_the_west_texture
** 	SO		./path_to_the_south_texture
** 	S		./path_to_the_sprite_texture
** 	F		0,255,130
** 	C		122,83,2
** 	MAP
*/

//	CONFIG PARSE FUNCTIONS	//

void	config_parse(char *path, t_cub *cub)
{
	int		is_parse_ok;
	char	*line;
	int		is_line_ok;

	if((cub->confing_fd = open(path, O_RDONLY)) < 0)
		cub_destroy(cub, NULL);
	is_parse_ok = 0;
	while ((is_line_ok = get_next_line(cub->confing_fd, &line)) > 0)
	{
		if (*line)
			is_parse_ok |= parse_line(line, cub);
		free(line);
	}

	is_line_ok_check(line, is_line_ok, cub);

	if (*line)
		is_parse_ok |= parse_line(line, cub);
	free(line);

	is_parse_ok |= check_map(cub);
	if (is_line_ok & CUB_PARSE_OK != CUB_PARSE_OK)
		cub_destroy(cub, ERR_PARSE);
}

void	is_line_ok_check(char *line, int is_line_ok, t_cub *cub)
{
	if (is_line_ok == -1)
	{
		free(line);
		cub_destroy(cub, ERR_READ_CONFIG);
	}
	if (is_line_ok == -2)					//	Edit your GNL
		cub_destroy(cub, ERR_NO_MEMORY);
}

int		parse_line(char *line, t_cub *cub)
{
	static int is_map;

	if (!is_map)
	{
		while (*line == ' ')
			line++;
		if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
			return (parse_line_no(line, cub));
		else if (ft_strnstr(line, "WE", ft_strlen(line)))
			return (parse_line_we(line, cub));
		else if (ft_strnstr(line, "EA", ft_strlen(line)))
			return (parse_line_ea(line, cub));
		else if (ft_strnstr(line, "SO", ft_strlen(line)))
			return (parse_line_so(line, cub));
		else if (ft_strnstr(line, "S", ft_strlen(line)))
			return (parse_line_sprite(line, cub));
		else if (ft_strnstr(line, "F", ft_strlen(line)))
			return (parse_line_floor(line, cub));
		else if (ft_strnstr(line, "C", ft_strlen(line)))
			return (parse_line_ceilling(line, cub));
		return (0);
	}
	is_map = 1;
	add_line_to_map(line, cub);
	return (0);
}

int		parse_line_no(char *line, t_cub *cub)
{
	while (*line == ' ')
		line++;

}

int		parse_line_ea(char *line, t_cub *cub)
{
	;
}

int		parse_line_we(char *line, t_cub *cub)
{
	;
}

int		parse_line_so(char *line, t_cub *cub)
{
	;
}

int		parse_line_sprite(char *line, t_cub *cub)
{
	;
}

int		parse_line_floor(char *line, t_cub *cub)
{
	;
}

int		parse_line_ceilling(char *line, t_cub *cub)
{
	;
}