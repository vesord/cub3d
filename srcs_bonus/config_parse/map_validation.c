/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:46:13 by matrus            #+#    #+#             */
/*   Updated: 2020/07/24 10:01:06 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		is_map_chars_correct(const char *crct, t_cub *cub)
{
	int i;
	int j;
	int	max_j;

	i = 0;
	j = 0;
	max_j = 0;
	while (cub->map->field[i])
	{
		if (j > max_j)
			max_j = j;
		j = 0;
		while (cub->map->field[i][j])
		{
			if (!ft_strchr(crct, cub->map->field[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	cub->map->max_x = max_j;
	cub->map->max_y = i;
	return (1);
}

int		map_check_player_pos(t_cub *cub)
{
	int	pl_x;
	int	pl_y;
	int f;

	pl_y = 0;
	f = 0;
	while (cub->map->field[pl_y])
	{
		pl_x = 0;
		while (cub->map->field[pl_y][pl_x])
		{
			if (ft_strchr("NWES", cub->map->field[pl_y][pl_x]))
			{
				if (f)
					return (0);
				f = 1;
			}
			pl_x++;
		}
		pl_y++;
	}
	return (1);
}

int		is_map_portals_correct(t_cub *cub)
{
	const char	*portals = "ce";
	int			p;
	int			i;
	int 		j;
	int 		count;

	p = -1;
	while (portals[++p])
	{
		i = -1;
		count = 0;
		while (cub->map->field[++i])
		{
			j = -1;
			while (cub->map->field[i][++j])
				if (cub->map->field[i][++j] == portals[p])
					count++;
		}
		if (count != 2)
			return (0);
	}
	return (1);
}
