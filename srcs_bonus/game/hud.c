/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:05:15 by matrus            #+#    #+#             */
/*   Updated: 2020/07/25 23:05:17 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "cub_game.h"

void	put_hp_to_img(int off_x, int off_y, int size, t_cub *cub);
void	add_hud_hp(t_cub *cub);
void	process_jumping(t_cub *cub);

void	add_hud_shooting(t_cub *cub);
void	draw_rainbow_blast(t_cub *cub);

void	update_hud(t_cub *cub)
{
	if (cub->hud->hp <= 0)
		cub->hud->status = GAME_STATUS_DIE;
	add_hud_face(cub);
	add_hud_wand(cub);
	add_hud_hp(cub);
	add_hud_shooting(cub);
	if (cub->hud->jumping)
		process_jumping(cub);
}

typedef struct	s_win_blk
{
	int	x_start;
	int	y_start;
	int	x_end;
	int	y_end;

}				t_win_blk;

void	add_hud_shooting(t_cub *cub)
{
	if (!cub->hud->shooting || !cub->hud->has_wand)
		return ;
	draw_rainbow_blast(cub);
}

void	win_blk_rb_init(t_win_blk *blk, t_cub *cub);
void	put_img_in_win_blk(t_win_blk *blk, t_img *tex, t_cub *cub);
void	erase_img_in_win_blk(t_win_blk *blk, t_img *tex, t_cub *cub);

void	check_enemies(t_cub *cub);

void	draw_rainbow_blast(t_cub *cub)
{
	static int			shout_status;
	static t_win_blk	rb_blk;

	if (!rb_blk.x_end && !rb_blk.y_end)
		win_blk_rb_init(&rb_blk, cub);
	if (cub->hud->shooting == 1)
		put_img_in_win_blk(&rb_blk, *(&(cub->tex->tx_anim->wand_1) + shout_status), cub);
	else
		erase_img_in_win_blk(&rb_blk, *(&(cub->tex->tx_anim->wand_1) + shout_status), cub);
	shout_status++;
	if (shout_status == 7)
	{
		cub->hud->shooting++;
		shout_status = 0;
	}
	if (cub->hud->shooting == 3)
	{
		check_enemies(cub);
		cub->hud->shooting = 0;
	}
}

#define ENEMY_KILL_DST 4.f

void	check_enemies(t_cub *cub)
{
	int x;
	int y;

	throw_ray(cub, cub->cam->cam_direction_yaw, cub->cam->cam_direction_yaw);
	x = cub->ray->enemy.x;
	y = cub->ray->enemy.y;
	if (cub->ray->enemy.type && cub->ray->enemy.dst < cub->map->blk_x * ENEMY_KILL_DST)
	{
		if (cub->ray->enemy.type == 'L')
			cub->hud->status = GAME_STATUS_WIN;
		(cub->map->field)[y][x] = ft_tolower((cub->map->field)[y][x]);
	}
}


void	erase_img_in_win_blk(t_win_blk *blk, t_img *tex, t_cub *cub)
{
	int				x;
	int				y;
	unsigned int	pixel;

	y = -1;
	while (++y < blk->y_end - blk->y_start)
	{
		x = -1;
		while (++x < blk->x_end - blk->x_start)
		{
			pixel = get_pixel_tex((float)(x) / (float)(blk->x_end - blk->x_start), (float)(y) / (float)(blk->y_end - blk->y_start), tex);
			if (pixel)
			{
				((unsigned int *) (cub->frm_0->data))[cub->win->x * (y + blk->y_start) + x + blk->x_start] = pixel;
				((unsigned int *) (cub->frm_1->data))[cub->win->x * (y + blk->y_start) + x + blk->x_start] = pixel;
			}
		}
	}
	cub->hud->need_update_weap = 1;
}

void	put_img_in_win_blk(t_win_blk *blk, t_img *tex, t_cub *cub)
{
	int				x;
	int				y;
	unsigned int	pixel;

	y = -1;
	while (++y < blk->y_end - blk->y_start)
	{
		x = -1;
		while (++x < blk->x_end - blk->x_start)
		{
			pixel = get_pixel_tex((float)(x) / (float)(blk->x_end - blk->x_start), (float)(y) / (float)(blk->y_end - blk->y_start), tex);
			if (pixel)
			{
				((unsigned int *) (cub->frm_0->data))[cub->win->x * (y + blk->y_start) + x + blk->x_start] = pixel | HUD_TRANSP_MASK;
				((unsigned int *) (cub->frm_1->data))[cub->win->x * (y + blk->y_start) + x + blk->x_start] = pixel | HUD_TRANSP_MASK;
			}
		}
	}
}

void	win_blk_rb_init(t_win_blk *blk, t_cub *cub)
{
	static float off_x = 0.5f;
	static float off_y = 0.45f;
	static float size_x = 0.205f;
	static float size_y = 0.4f;

	blk->x_start = (int)((float)cub->win->x * off_x);
	blk->y_start = (int)((float)cub->win->y * off_y);
	blk->x_end = (int)((float)cub->win->x * (off_x + size_x));
	blk->y_end = (int)((float)cub->win->y * (off_y + size_y));
}


void	add_hud_hp(t_cub *cub)
{
	int	i;

	if (!cub->hud->need_update_hp)
		return ;
	i = -1;
	while (++i < cub->hud->hp)
	{
		put_hp_to_img(cub->win->x / 20 + i * cub->win->x / 10, cub->win->y / 20, cub->win->x / 20, cub);
	}
	cub->hud->need_update_hp = 0;
}

void	add_hud_face(t_cub *cub)
{
	if (!cub->hud->need_update_face)
		return ;
	put_tex_to_img(cub->hud->tx_face, cub->frm_0, HUD_TRANSP_MASK);
	put_tex_to_img(cub->hud->tx_face, cub->frm_1, HUD_TRANSP_MASK);
	cub->hud->need_update_face = 0;
}

void	add_hud_wand(t_cub *cub)
{
	if (!cub->hud->need_update_weap)
		return ;
	put_tex_to_img(cub->hud->tx_wand, cub->frm_0, HUD_TRANSP_MASK);
	put_tex_to_img(cub->hud->tx_wand, cub->frm_1, HUD_TRANSP_MASK);
	cub->hud->need_update_weap = 0;
}

void	process_jumping(t_cub *cub)
{
	static int jump_status = -36;
	static int jump_max = 36;

	cub->cam->z = ((float)cub->map->blk_z / 2) + ((float)jump_max - (float)abs(jump_status)) / 2.f;
	jump_status += (int)sqrtf((float)abs(jump_status));
	if (jump_status == 0)
		jump_status = 1;
	if (jump_status > jump_max)
	{
		jump_status = -jump_max;
		cub->hud->jumping = 0;
	}
}

void put_tex_to_img(t_img *tex, t_img *img, unsigned int transp)
{
	int				x;
	int				y;
	unsigned int	pixel;

	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
		{
			pixel = get_pixel_tex((float)(x) / img->width, (float)(y) / img->height, tex);
			if (pixel)
				((unsigned int*)(img->data))[img->width * y + x] = pixel | transp;
		}
	}
}

void	put_hp_to_img(int off_x, int off_y, int size, t_cub *cub)
{
	int cur_x;
	int cur_y;
	unsigned int pixel;

	cur_y = -1;
	while (++cur_y < size)
	{
		cur_x = -1;
		while (++cur_x < size)
		{
			pixel = get_pixel_tex((float)cur_x / (float)size, (float)cur_y / (float)size, cub->hud->tx_hp);
			if (pixel)
			{
				((unsigned int *) (cub->frm_0->data))[cub->win->x * (cur_y + off_y) + cur_x + off_x] = pixel | HUD_TRANSP_MASK;
				((unsigned int *) (cub->frm_1->data))[cub->win->x * (cur_y + off_y) + cur_x + off_x] = pixel | HUD_TRANSP_MASK;
			}
		}
	}
}
