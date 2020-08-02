/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cells_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 11:05:06 by matrus            #+#    #+#             */
/*   Updated: 2020/08/02 10:28:34 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "includes/cub_game_bonus.h"

int		is_cell_enemy(char c)
{
	if (ft_strchr("LB", c))
		return (1);
	return (0);
}

int		is_cell_door_opened(char c)
{
	if (ft_strchr("yuq", c))
		return (1);
	return (0);
}

int		is_cell_door_closed(char c)
{
	if (ft_strchr("YUQ", c))
		return (1);
	return (0);
}

int		is_cell_walkable(char c)
{
	if (ft_strchr("NWES0*$?wcelbgjluyq", c))
		return (1);
	return (0);
}

int		is_cell_portal(char c)
{
	if (ft_strchr("ce", c))
		return (1);
	return (0);
}
