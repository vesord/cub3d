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

#include "cub3d.h"
//
#include <stdio.h>

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
//	//
//	int a = 0;
//	printf("field on %i iter is %p\n", i, (cub->map->field));
//	while ((cub->map->field)[a])
//	{
//		printf("map[%i]: p: %p\tc: %s\n", a, (cub->map->field)[a], (cub->map->field)[a]);
//		a++;
//	}
//	printf("map[%i]: p: %p\tc: %s\n", a, (cub->map->field)[a], (cub->map->field)[a]);
//	printf("void* %lu\tchar* %lu\tint* %lu\n\n", sizeof(void*), sizeof(char*), sizeof(int*));
//	//
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

void	**ft_realloc_tab(void **tab, int prev_size, int need_size)	// TODO: add this to libft
{
	void	**new_ptr;

	if (!(new_ptr = (void**)malloc(sizeof(void*) * need_size))) // TODO: check sizeof(void*/char*/int*)
		return (NULL);
	while (need_size > prev_size)
	{
		//
		//printf("%p setted to NULL\n", new_ptr[need_size - 1]);
		//
		new_ptr[need_size - 1] = NULL;
		need_size--;
	}
	while (prev_size > 0)
	{
		//
		//printf("%p setted to %p\n", new_ptr[need_size - 1], tab[prev_size - 1]);
		//
		new_ptr[prev_size - 1] = tab[prev_size - 1];
		prev_size--;
	}
	free(tab);
	//free_tab(tab);
	return (new_ptr);
}

void	free_tab(void **tab)	// TODO: test this function // TODO: add this to libft
{
	void	**ptr;

	ptr = tab;
	while (*ptr)
	{
		free(*ptr);
		//
		//printf("%p was freed\n", *ptr);
		//
		ptr ++;
	}
	free(tab);
	//
	//printf("tab %p was freed\n", tab);
	//
}