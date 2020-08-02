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

#include "cub3d.h"

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

int		map_find_player(t_cub *cub)
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
	return (f);
}

void	map_set_player(int pl_x, int pl_y, t_cub *cub)
{
	char dir;

	cub->cam->step = sqrt(2 * (double)cub->map->blk_x / STEP_SCALER);
	cub->cam->dst_to_wall = (double)cub->map->blk_x / WALL_SCALER;
	cub->cam->x = cub->map->blk_x * pl_x + cub->map->blk_x / 2;
	cub->cam->y = cub->map->blk_y * pl_y + cub->map->blk_y / 2;
	dir = cub->map->field[pl_y][pl_x];
	if (dir == 'N')
		cub->cam->cam_direction_yaw = -M_PI_2;
	else if (dir == 'W')
		cub->cam->cam_direction_yaw = M_PI;
	else if (dir == 'S')
		cub->cam->cam_direction_yaw = M_PI_2;
	else
		cub->cam->cam_direction_yaw = 0;
}
