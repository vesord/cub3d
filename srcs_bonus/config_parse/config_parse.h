/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parse.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 11:29:10 by matrus            #+#    #+#             */
/*   Updated: 2020/08/01 11:29:11 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_PARSE_H
# define CONFIG_PARSE_H

#include "cub3d_bonus.h"

# define PARSE_OK		0x7fffffffffffffff
# define PARSE_FAIL		0x8000000000000000

# define PARSE_OK_W1	0x0000000000000001
# define PARSE_OK_W2	0x0000000000000002
# define PARSE_OK_W3	0x0000000000000004
# define PARSE_OK_W4	0x0000000000000008
# define PARSE_OK_W5	0x0000000000000010
# define PARSE_OK_W6	0x0000000000000020
# define PARSE_OK_W7	0x0000000000000040
# define PARSE_OK_W8	0x0000000000000080

# define PARSE_OK_WI	0x0000000000000100
# define PARSE_OK_DI	0x0000000000000200
# define PARSE_OK_R0	0x0000000000000400

# define PARSE_OK_TR	0x0000000000000800
# define PARSE_OK_LI	0x0000000000001000
# define PARSE_OK_DW	0x0000000000002000
# define PARSE_OK_PL	0x0000000000004000
# define PARSE_OK_PR	0x0000000000008000
# define PARSE_OK_TU	0x0000000000010000
# define PARSE_OK_LB	0x0000000000020000
# define PARSE_OK_BB	0x0000000000040000
# define PARSE_OK_M1	0x0000000000080000
# define PARSE_OK_L1	0x0000000000100000
# define PARSE_OK_E1	0x0000000000200000

# define PARSE_OK_MO	0x0000000000400000
# define PARSE_OK_DA	0x0000000000800000
# define PARSE_OK_RS	0x0000000001000000
# define PARSE_OK_MS	0x0000000002000000
# define PARSE_OK_PH	0x0000000004000000
# define PARSE_OK_LU	0x0000000008000000
# define PARSE_OK_BF	0x0000000010000000
# define PARSE_OK_M2	0x0000000020000000
# define PARSE_OK_M3	0x0000000040000000
# define PARSE_OK_L2	0x0000000080000000

# define PARSE_OK_S0	0x0000000100000000
# define PARSE_OK_S1	0x0000000200000000
# define PARSE_OK_S2	0x0000000400000000
# define PARSE_OK_S3	0x0000000800000000

# define PARSE_OK_S5	0x0000001000000000
# define PARSE_OK_S6	0x0000002000000000
# define PARSE_OK_S7	0x0000004000000000
# define PARSE_OK_S8	0x0000008000000000

# define PARSE_OK_WA	0x0000010000000000
# define PARSE_OK_HP	0x0000020000000000
# define PARSE_OK_FL	0x0000040000000000

# define PARSE_OK_FM	0x0000080000000000
# define PARSE_OK_FE	0x0000100000000000
# define PARSE_OK_FC	0x0000200000000000

# define PARSE_OK_D1	0x0000400000000000
# define PARSE_OK_D2	0x0000800000000000
# define PARSE_OK_D3	0x0001000000000000
# define PARSE_OK_D4	0x0002000000000000
# define PARSE_OK_D5	0x0004000000000000
# define PARSE_OK_D6	0x0008000000000000

# define PARSE_OK_A1	0x0010000000000000
# define PARSE_OK_A2	0x0020000000000000
# define PARSE_OK_A3	0x0040000000000000
# define PARSE_OK_A4	0x0080000000000000
# define PARSE_OK_A5	0x0100000000000000
# define PARSE_OK_A6	0x0200000000000000
# define PARSE_OK_A7	0x0400000000000000

# define PARSE_OK_C		0x0800000000000000
# define PARSE_OK_F		0x1000000000000000
# define PARSE_OK_R		0x2000000000000000
# define PARSE_OK_MAP	0x4000000000000000

void			gnl_func_parse(char *line, size_t *is_parse_ok, t_cub *cub);
size_t 			parse_line(char *line, t_cub *cub);
size_t			parse_line_type(char *line, t_cub *cub);

size_t			parse_line_texture(char *line, t_cub *cub, t_img *img);
size_t			parse_line_color(char *line, t_cub *cub, int *color);
size_t			parse_line_resolution(char *line, t_cub *cub);

void			add_line_to_map(char *line, t_cub *cub);
size_t			check_map(t_cub *cub);

int				check_path(char *path);
void			is_line_ok_check(char *line, int is_line_ok, t_cub *cub);
size_t			parse_line_texture_ret(t_cub *cub, void *data);
char			*parse_line_err_msg(t_cub *cub, void *data);
int				str_to_color(char *line, int *color);

int				is_map_chars_correct(const char *crct, t_cub *cub);
int				map_check_player_pos(t_cub *cub);
void			map_set_player(int pl_x, int pl_y, t_cub *cub);
int				is_map_portals_correct(t_cub *cub);

int				is_map_surrounded(t_cub *cub);
void			is_map_surrounded_set(const char *starts, t_cub *cub);
int				is_map_surrounded_recursive(int x, int y, int strt, t_cub *cub);
void			is_map_surrounded_recover(t_cub *cub);

#endif
