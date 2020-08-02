cmake_minimum_required(VERSION 3.16)
project(cub3d C)

set(CMAKE_C_STANDARD 11)
#
set(MYCOMPILE_FLAGS "-Wall -Werror -Wextra")
add_definitions(${MYCOMPILE_FLAGS})

include_directories(libs/libft)
include_directories(libs/minilibx)
include_directories(libs/get_next_line)
include_directories(srcs)
include_directories(includes)

set(HEADER_FILES
        libs/libft/libft.h
        libs/libft/get_next_line.h
        libs/minilibx/mlx.h
        libs/minilibx/mlx_int.h
        srcs/errors.h
        srcs/cub3d.h
        )

set(SRC_FILES
        srcs/cub3d.c
        srcs/cub_init/cub_init.c
        srcs/cub_init/cub_init_struct.c
        srcs/cub_init/cub_init_struct_2.c
        srcs/cub_init/cub_destroy.c
        srcs/cub_init/cub_destroy_2.c
        srcs/cub_init/player_init.c
        srcs/config_parse/config_parse.c
        srcs/config_parse/config_parse_lines.c
        srcs/config_parse/parse_utils.c
        srcs/config_parse/parse_map.c
        srcs/config_parse/map_validation.c
        srcs/config_parse/map_validation_surround.c
        srcs/window_work/window_setup.c
        srcs/window_work/bmp.c
        srcs/game/image_form.c
        srcs/game/key_process_loop.c
        srcs/game/key_process_game.c
        srcs/game/textures.c
        srcs/game/textures_sprites.c
        srcs/game/cells.c
        srcs/game/ray_throw.c
        srcs/game/ray_throw_sprites.c
        )

set(MY_LIB_FILES
        ${CMAKE_SOURCE_DIR}/libs/libft/libft.a
        ${CMAKE_SOURCE_DIR}/libs/minilibx/libmlx.a)

add_executable(cub3D
        ${HEADER_FILES}
        ${LIBS_SRC}
        ${SRC_FILES}
        )

target_link_libraries(cub3D ${MY_LIB_FILES} m X11 Xext)

#   ---BONUS_PART---

include_directories(srcs_bonus)
include_directories(srcs_bonus/includes)

set(HEADER_FILES_BONUS
        libs/libft/libft.h
        libs/libft/get_next_line.h
        libs/minilibx/mlx.h
        libs/minilibx/mlx_int.h
        srcs_bonus/errors_bonus.h
        srcs_bonus/cub3d_bonus.h
        )

set(SRC_FILES_BONUS
        srcs_bonus/cub3d_bonus.c

        srcs_bonus/cub_init/cub_init_bonus.c
        srcs_bonus/cub_init/cub_init_struct_bonus.c
        srcs_bonus/cub_init/cub_init_struct_2_bonus.c
        srcs_bonus/cub_init/cub_init_struct_tx_walls_bonus.c
        srcs_bonus/cub_init/cub_init_struct_tx_floors_scrns_bonus.c
        srcs_bonus/cub_init/cub_init_struct_tx_skybox_bonus.c
        srcs_bonus/cub_init/cub_init_struct_tx_spr_go_bonus.c
        srcs_bonus/cub_init/cub_init_struct_tx_spr_ngo_bonus.c
        srcs_bonus/cub_init/cub_init_struct_tx_animation_bonus.c
        srcs_bonus/cub_init/cub_init_struct_tx_doors_bonus.c
        srcs_bonus/cub_init/cub_destroy_bonus.c
        srcs_bonus/cub_init/cub_destroy_tex_bonus.c
        srcs_bonus/cub_init/cub_destroy_tex_2_bonus.c
        srcs_bonus/cub_init/player_init_bonus.c

        srcs_bonus/config_parse/config_parse_bonus.c
        srcs_bonus/config_parse/config_parse_line_type_bonus.c
        srcs_bonus/config_parse/config_parse_line_type_2_bonus.c
        srcs_bonus/config_parse/config_parse_lines_bonus.c
        srcs_bonus/config_parse/parse_utils_bonus.c
        srcs_bonus/config_parse/parse_line_err_msg_bonus.c
        srcs_bonus/config_parse/parse_line_err_msg_2_bonus.c
        srcs_bonus/config_parse/parse_line_texture_ret_bonus.c
        srcs_bonus/config_parse/parse_line_texture_ret_2_bonus.c
        srcs_bonus/config_parse/parse_map_bonus.c
        srcs_bonus/config_parse/map_validation_bonus.c
        srcs_bonus/config_parse/map_validation_surround_bonus.c

        srcs_bonus/window_work/window_setup_bonus.c
        srcs_bonus/window_work/bmp_bonus.c

        srcs_bonus/game/image_form_bonus.c
        srcs_bonus/game/key_process_loop_bonus.c
        srcs_bonus/game/key_process_game_bonus.c
        srcs_bonus/game/mouse_process_loop_bonus.c
        srcs_bonus/game/cells_bonus.c
        srcs_bonus/game/cells_2_bonus.c
        srcs_bonus/game/ray_throw_bonus.c
        srcs_bonus/game/ray_throw_2_bonus.c
        srcs_bonus/game/ray_throw_sprites_bonus.c
        srcs_bonus/game/get_length_ceil_floor_bonus.c

        srcs_bonus/game_textures/select_textures_bonus.c
        srcs_bonus/game_textures/textures_sprites_bonus.c
        srcs_bonus/game_textures/get_frame_col_pixel_bonus.c
        srcs_bonus/game_textures/skybox_bonus.c
        srcs_bonus/game_textures/shadows_bonus.c
        srcs_bonus/game_textures/show_screen_bonus.c
        srcs_bonus/game_textures/get_textures_pixel_bonus.c
        srcs_bonus/game_textures/window_blocks_bonus.c

        srcs_bonus/game_interactions/hud_bonus.c
        srcs_bonus/game_interactions/interactions_bonus.c
        srcs_bonus/game_interactions/interactions_portals_bonus.c
        srcs_bonus/game_interactions/hud_hp_bonus.c
        srcs_bonus/game_interactions/hud_shooting_bonus.c
        )


add_executable(bonus
        ${HEADER_FILES_BONUS}
        ${SRC_FILES_BONUS}
        ${LIBS_SRC}
        )

target_link_libraries(bonus ${MY_LIB_FILES} m X11 Xext)

add_executable(test
        test/ft_cos.c
        test/double_vs_float.c
        test/arrays.c)

target_link_libraries(test m)

