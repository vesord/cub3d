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
        libs/minilibx/mlx.h
        libs/minilibx/mlx_int.h
        libs/get_next_line/get_next_line.h
        srcs/errors.h
        srcs/cub3d.h
        )

set(SRC_FILES
        #srcs/main.c
        srcs/cub3d.c
        srcs/cub_init/cub_init.c
        srcs/cub_init/cub_init_struct.c
        srcs/cub_init/cub_destroy.c
        srcs/config_parse/config_parse.c
        srcs/config_parse/parse_map.c
        srcs/config_parse/parse_utils.c
        libs/get_next_line/get_next_line.c
        libs/get_next_line/get_next_line_utils.c
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