/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:46:13 by matrus            #+#    #+#             */
/*   Updated: 2020/07/22 09:46:14 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_map_chars_correct(const char *crct, t_cub *cub)
{
	int i;
	int j;
	int	max_j;

	i = 0;
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
		return (1);
}

//void	map_find_player_flag(int *pl_x, int *f, char *c_ptr, char *y_ptr)
//{
//	if (*f)
//	{
//		*f = -1;
//		return ;
//	}
//	*pl_x = c_ptr - y_ptr;
//	*f = 1;
//}

void	map_set_player(int pl_x, int pl_y, t_cub *cub)
{
	char dir;

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

int		is_map_surrounded(t_cub *cub)
{
	int x_start;
	int y_start;

	is_map_surrounded_set(&x_start, &y_start, cub);
	if (!is_map_surrounded_recursive(x_start, y_start, cub))
		return (0);
	is_map_surrounded_recover(cub);
	return (1);
}

void	is_map_surrounded_set(int *x_start, int *y_start, t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (cub->map->field[i])
	{
		j = 0;
		while (cub->map->field[i][j])
		{
			if (ft_strchr("WESN", cub->map->field[i][j]))
			{
				map_set_player(j, i, cub);
				//cub->map->field[i][j] = -cub->map->field[i][j];
				*x_start = j;
				*y_start = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int		is_map_surrounded_recursive(int x, int y, t_cub *cub)
{
	int f;

	if (cub->map->field[y][x] == '1' || cub->map->field[y][x] < 0)
		return (1);
	if (cub->map->field[y][x] == ' ')
		return (0);
	if (x < 1 || y < 1 || x + 1 >= cub->map->max_x || y + 1 >= cub->map->max_y)
		return (0);
	cub->map->field[y][x] = -cub->map->field[y][x];
	f = is_map_surrounded_recursive(x, y + 1, cub) &&
		is_map_surrounded_recursive(x + 1, y, cub) &&
		is_map_surrounded_recursive(x, y - 1, cub) &&
		is_map_surrounded_recursive(x - 1, y, cub);
	return (f);
}

void	is_map_surrounded_recover(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (cub->map->field[i])
	{
		j = 0;
		while (cub->map->field[i][j])
		{
			if (cub->map->field[i][j] < 0)
				cub->map->field[i][j] = -cub->map->field[i][j];
			j++;
		}
		i++;
	}
}
