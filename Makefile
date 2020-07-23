#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2020/07/10 18:05:37 by matrus            #+#    #+#             *#
#*   Updated: 2020/07/10 18:05:37 by matrus           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = cub3D

INCLUDES_DIR = ./srcs $(LIB_DIR)/libft $(LIB_DIR)/minilibx 
INCLUDES = $(wildcard $(INCLUDES_DIR)/*.h)

SRC_DIR = ./srcs

DIR_PARSE = config_parse
SRC_PARSE = $(wildcard $(SRC_DIR)/$(DIR_PARSE)/*)

DIR_INIT = cub_init
SRC_INIT = $(wildcard $(SRC_DIR)/$(DIR_INIT)/*)

DIR_GAME = game
SRC_GAME = $(wildcard $(SRC_DIR)/$(DIR_GAME)/*)

DIR_WINDOW = window_work
SRC_WINDOW = $(wildcard $(SRC_DIR)/$(DIR_WINDOW)/*)

SRC_ALL = $(SRC_DIR)/cub3d.c $(SRC_PARSE) $(SRC_INIT) $(SRC_GAME) $(SRC_WINDOW)

OBJ_DIR = ./obj
OBJ_ALL = $(SRC_ALL:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIB_DIR = ./libs

FLAGS = -Wall -Werror -Wextra -g
CC = gcc
LINKED_LIBS = -lft -lmlx -lm -lX11 -lXext
LINKED_LIBS_DIR = -L./$(LIB_DIR)/libft -L./$(LIB_DIR)/minilibx


.PHONY: all
all: $(OBJ_DIR) $(NAME)

$(NAME): libft $(OBJ_ALL)
	$(CC) $(FLAGS) $(addprefix -I, $(INCLUDES_DIR)) $(OBJ_ALL) $(LINKED_LIBS_DIR) $(LINKED_LIBS) -o $@ 

$(OBJ_ALL): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLLUDES)
	$(CC) $(FLAGS) -c $(addprefix -I, $(INCLUDES_DIR)) $< $(LINKED_LIBS_DIR) $(LINKED_LIBS) -o $@ 

$(OBJ_DIR):
		mkdir $@ $@/$(DIR_PARSE) $@/$(DIR_INIT) $@/$(DIR_GAME) $@/$(DIR_WINDOW)

.PHONY: libft
libft: $(LIB_DIR)/libft
	cd $< && make

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	rm -rf *.bmp
	cd $(LIB_DIR)/libft && make clean

.PHONY: fclean
fclean: clean
	rm $(NAME)
	cd $(LIB_DIR)/libft && make fclean

.PHONY: re
re: fclean all


.PHONY: test
test:
	echo "$(SRC_ALL)"

