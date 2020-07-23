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

void	gnl_func_parse(char *line, int *is_parse_ok, t_cub *cub);

void	config_parse(char *path, t_cub *cub)
{
	int		is_parse_ok;
	char	*line;
	int		is_line_ok;

	if(!check_path(path) || (cub->confing_fd = open(path, O_RDONLY)) < 0)
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
	static int is_map;

	if (!is_map)
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
		is_map = 1;
	}
	add_line_to_map(line, cub);
	return (0);
}

int		parse_line_texture(char *line, t_cub *cub, t_img *img)
{
	int i;

	i = 2;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i] || ft_strlen(line) < 7 
	|| !(ft_strnstr(&(line[ft_strlen(line) - 4]), ".xpm", 4))
	|| !(img->ptr = mlx_xpm_file_to_image(cub->win->mlx_ptr,
		&(line[i]), &(img->width), &(img->height)))
	|| !(img->data = mlx_get_data_addr(img->ptr, &(img->btp), 
		&(img->sz_ln), &(img->endian))))
	{
		free(line);
		cub_destroy(cub, parse_line_err_msg(cub, img));
	}
	return (parse_line_texture_ret(cub, img));
}

int		parse_line_color(char *line, t_cub *cub, int *color)
{
	int i;

	i = 2;
	while (line[i] && line[i] == ' ')
		i++;
	if(!line[i] || !(str_to_color(&(line[i]), color)))
	{
		free(line);
		cub_destroy(cub, parse_line_err_msg(cub, color));
	}
	return (parse_line_texture_ret(cub, color));
}

int		parse_line_resolution(char *line, t_cub *cub)
{
	int i;

	i = 2;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i] && !ft_isdigit(line[i]))
	{
		free(line);
		cub_destroy(cub, ERR_PARSE_R);
	}
	cub->win->x = ft_atoi(&(line[i]));
	i += ft_ilen(cub->win->x);
	while (line[i] && line[i] == ' ')
		i++;
	if (cub->win->x < 1 || !ft_isdigit(line[i])
	|| (cub->win->y = ft_atoi(&(line[i]))) < 1)
	{
		free(line);
		cub_destroy(cub, ERR_PARSE_R);
	}
	return (PARSE_OK_R);
}
