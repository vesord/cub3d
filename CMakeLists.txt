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
        srcs_bonus/cub_init/cub_init.c
        srcs_bonus/cub_init/cub_init_struct.c
        srcs_bonus/cub_init/cub_init_struct_2.c
        srcs_bonus/cub_init/cub_destroy.c
        srcs_bonus/cub_init/cub_destroy_2.c
        srcs_bonus/cub_init/player_init.c
        srcs_bonus/config_parse/config_parse.c
        srcs_bonus/config_parse/config_parse_lines.c
        srcs_bonus/config_parse/parse_utils.c
        srcs_bonus/config_parse/parse_map.c
        srcs_bonus/config_parse/map_validation.c
        srcs_bonus/config_parse/map_validation_surround.c
        srcs_bonus/window_work/window_setup.c
        srcs_bonus/window_work/bmp.c
        srcs_bonus/game/image_form.c
        srcs_bonus/game/key_process_loop.c
        srcs_bonus/game/key_process_game.c
        srcs_bonus/game/walls.c
        srcs_bonus/game/textures_sprites.c
        srcs_bonus/game/cells.c
        srcs_bonus/game/ray_throw.c
        srcs_bonus/game/ray_throw_sprites.c

        srcs_bonus/game/hud.c
        srcs_bonus/game/shadows.c
        srcs_bonus/game/get_length_ceil_floor.c
        )


add_executable(bonus
        ${HEADER_FILES_BONUS}
        ${SRC_FILES_BONUS}
        ${LIBS_SRC}
        )

target_link_libraries(bonus ${MY_LIB_FILES} m X11 Xext)

add_executable(test
        test/ft_cos.c
        test/double_vs_float.c)

target_link_libraries(test m)

