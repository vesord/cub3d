/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parse_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 10:16:03 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 10:31:47 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "config_parse.h"

size_t	parse_line_texture(char *line, t_cub *cub, t_img *img)
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

size_t	parse_line_color(char *line, t_cub *cub, int *color)
{
	int i;

	i = 2;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i] || !(str_to_color(&(line[i]), color)))
	{
		free(line);
		cub_destroy(cub, parse_line_err_msg(cub, color));
	}
	return (parse_line_texture_ret(cub, color));
}

size_t	parse_line_resolution(char *line, t_cub *cub)
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
