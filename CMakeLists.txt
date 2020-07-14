cmake_minimum_required(VERSION 3.16)
project(cub3d C)

set(CMAKE_C_STANDARD 11)
#-Wall -Werror -Wextra
set(MYCOMPILE_FLAGS "")
add_definitions(${MYCOMPILE_FLAGS})

include_directories(libs/libft)
include_directories(libs/minilibx)
include_directories(classes/includes)
include_directories(includes)

set(HEADER_FILES
#        libs/get_next_line/get_next_line.h
        libs/libft/libft.h
        libs/minilibx/mlx.h
        libs/minilibx/mlx_int.h
        )

set(SRC_FILES
        #srcs/main.c
        srcs/cub3d.c
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