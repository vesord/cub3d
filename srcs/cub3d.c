/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:45:23 by matrus            #+#    #+#             */
/*   Updated: 2020/07/14 14:45:26 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	if (argc == 1)
		cube_start(argv[1]);
	else if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
		save_frame(argv[1]);
	else
		ft_exit(ERR_WRONG_ARGUMENTS);
	return (0);
}

void	cube_start(char *path_to_conf)
{
	t_cub *cub;

	if(!(cub = (t_cub*)malloc(sizeof(t_cub))))
		ft_exit(ERR_NO_MEMORY);
	cub_init(cub);
	if (!(cub->win->mlx_ptr = mlx_init()))
		cub_destroy(cub, ERR_NO_MEMORY);
	config_parse(path_to_conf, cub);
	window_setup(cub);
	open_textures(cub);
	hook_initialize(cub);
}

void	ft_exit(char *msg)
{
	ft_putendl_fd("Error.", 2);
	ft_putendl_fd(msg, 2);
	exit(0);
}

void	save_frame()
{
	;
}