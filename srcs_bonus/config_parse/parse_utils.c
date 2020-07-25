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

#include "cub3d.h"

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
	if (cub->tex->so == data)
		return (ERR_PARSE_SO);
	if (cub->tex->no == data)
		return (ERR_PARSE_NO);
	if (cub->tex->we == data)
		return (ERR_PARSE_WE);
	if (cub->tex->ea == data)
		return (ERR_PARSE_EA);
	if (cub->tex->s0 == data)
		return (ERR_PARSE_S);
	if (&(cub->tex->flor) == data)
		return (ERR_PARSE_F);
	if (&(cub->tex->ceil) == data)
		return (ERR_PARSE_C);
	return (0);
}

int		parse_line_texture_ret(t_cub *cub, void *data)
{
	if (cub->tex->so == data)
		return (PARSE_OK_SO);
	if (cub->tex->no == data)
		return (PARSE_OK_NO);
	if (cub->tex->we == data)
		return (PARSE_OK_WE);
	if (cub->tex->ea == data)
		return (PARSE_OK_EA);
	if (cub->tex->s0 == data)
		return (PARSE_OK_S);
	if (&(cub->tex->flor) == data)
		return (PARSE_OK_F);
	if (&(cub->tex->ceil) == data)
		return (PARSE_OK_C);
	return (0);
}
