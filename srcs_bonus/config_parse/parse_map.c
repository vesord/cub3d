/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 22:42:06 by matrus            #+#    #+#             */
/*   Updated: 2020/07/16 22:42:06 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	add_line_to_map(char *line, t_cub *cub)
{
	int i;

	i = 0;
	while ((cub->map->field)[i])
		i++;
	if (!(cub->map->field = (char**)ft_realloc_tab((void**)cub->map->field,
		i + 1, i + 2))
		|| !((cub->map->field)[i] = ft_strdup(line)))
	{
		free(line);
		cub_destroy(cub, ERR_NO_MEMORY);
	}
	(cub->map->field)[i + 1] = NULL;
}

int		check_map(t_cub *cub)
{
	if (!is_map_chars_correct(" 012NWES", cub))
		return (0);
	if (!map_find_player(cub))
		return (0);
	if (!is_map_surrounded(cub))
		return (0);
	return (PARSE_OK_MAP);
}
