/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 14:19:49 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:34 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_game_bonus.h"

void	player_init(t_cub *cub)
{
	map_set_scales(cub);
	cam_init(cub);
	cub->hud->need_update_face = 1;
	cub->hud->need_update_weap = 0;
	cub->hud->need_update_hp = 1;
	cub->hud->hp = 3;
	cub->hud->status = GAME_STATUS_PLAY;
	cub->hud->jumping = 0;
	cub->hud->teleported = 0;
	cub->hud->world = WORLD_MEWN;
	cub->hud->shooting = 0;
	cub->hud->has_wand = 0;
}

void	map_set_scales(t_cub *cub)
{
	cub->map->blk_z = 16;
	cub->map->blk_x = 16;
	cub->map->blk_y = 16;
}

void	cam_init(t_cub *cub)
{
	char	dir;
	int		pl_x;
	int		pl_y;

	pl_x = 0;
	pl_y = 0;
	map_find_player(&pl_x, &pl_y, cub);
	cub->cam->step = sqrtf(2 * (float)cub->map->blk_x / STEP_SCALER);
	cub->cam->dst_to_wall = (float)cub->map->blk_x / WALL_SCALER;
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
	cub->cam->cam_angle_yaw = M_PI / 3;
	cub->cam->cam_angle_pitch = M_PI / 3;
	cub->cam->z = cub->map->blk_z / 2;
	cub->cam->cam_direction_pitch = 0.f;
}

void	map_find_player(int *pl_x, int *pl_y, t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub->map->field[++i])
	{
		j = -1;
		while (cub->map->field[i][++j])
		{
			if (ft_strchr("NWES", cub->map->field[i][j]))
			{
				*pl_x = j;
				*pl_y = i;
				return ;
			}
		}
	}
}
