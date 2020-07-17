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

void	debug_show_cub(t_cub *cub);

int main(int argc, char **argv)
{
	if (argc == 2)
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
	player_init(cub);
//	debug_show_cub(cub);
	window_setup(cub);
	hook_initialize(cub);
}

void	ft_exit(char *msg)
{
	ft_putendl_fd("Error.", 2);
	if (msg)
		ft_putendl_fd(msg, 2);
	exit(0);
}

void	save_frame()
{
	;
}

//

#include <stdio.h>

void	debug_show_cub(t_cub *cub)
{
	printf("Resolution:\tx: %i\ty: %i\n\n", cub->win->x, cub->win->y);
	printf("NO nptr: %p\t data: %p\n", cub->tex->no->ptr, cub->tex->no->data);
	printf("EA nptr: %p\t data: %p\n", cub->tex->ea->ptr, cub->tex->ea->data);
	printf("WE nptr: %p\t data: %p\n", cub->tex->we->ptr, cub->tex->we->data);
	printf("SO nptr: %p\t data: %p\n", cub->tex->so->ptr, cub->tex->so->data);
	printf("S  nptr: %p\t data: %p\n", cub->tex->s0->ptr, cub->tex->s0->data);
	printf("F  color: r: %hhu, g: %hhu, b: %hhu\n", cub->tex->flor >> 16, cub->tex->flor >> 8, cub->tex->flor >> 0);
	printf("C  color: r: %hhu, g: %hhu, b: %hhu\n\n", cub->tex->ceil >> 16, cub->tex->ceil >> 8, cub->tex->ceil >> 0);
	printf("MAP:\n");
	int i = 0;
	while (cub->map->field[i])
	{
		printf("%s\n", cub->map->field[i]);
		i++;
	}
}