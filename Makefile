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
NAME_B = cub3D_bonus
LIB_DIR = ./libs


#	-----MANDATORY PART SRCS-----

SRC_DIR = ./srcs

INCLUDES_DIR = $(SRC_DIR) $(LIB_DIR)/libft $(LIB_DIR)/minilibx 
INCLUDES = $(wildcard $(INCLUDES_DIR)/*.h)

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


#	-----BONUS PART SRCS-----

SRC_B_DIR = ./srcs_bonus

INCLUDES_B_DIR = $(SRC_B_DIR) $(SRC_B_DIR)/includes $(LIB_DIR)/libft $(LIB_DIR)/minilibx 
INCLUDES_B = $(wildcard $(INCLUDES_B_DIR)/*.h)

DIR_B_PARSE = config_parse
SRC_B_PARSE = $(wildcard $(SRC_B_DIR)/$(DIR_B_PARSE)/*)

DIR_B_INIT = cub_init
SRC_B_INIT = $(wildcard $(SRC_B_DIR)/$(DIR_B_INIT)/*)

DIR_B_GAME = game
SRC_B_GAME = $(wildcard $(SRC_B_DIR)/$(DIR_B_GAME)/*)

DIR_B_WINDOW = window_work
SRC_B_WINDOW = $(wildcard $(SRC_B_DIR)/$(DIR_B_WINDOW)/*)

DIR_B_INTERACTIONS = game_interactions
SRC_B_INTERACTIONS = $(wildcard $(SRC_B_DIR)/$(DIR_B_INTERACTIONS)/*)

DIR_B_TEXTURES = game_textures
SRC_B_TEXTURES = $(wildcard $(SRC_B_DIR)/$(DIR_B_TEXTURES)/*)

SRC_B_ALL = $(SRC_B_DIR)/cub3d_bonus.c $(SRC_B_PARSE) $(SRC_B_INIT)\
		   	$(SRC_B_GAME) $(SRC_B_WINDOW) $(SRC_B_INTERACTIONS)\
			$(SRC_B_TEXTURES)

OBJ_B_DIR = ./obj_bonus
OBJ_B_ALL = $(SRC_B_ALL:$(SRC_B_DIR)/%.c=$(OBJ_B_DIR)/%.o)


#	-----COMPILE FLAGS-----

FLAGS = -Wall -Werror -Wextra
CC = gcc


#	-----LINKING LIBS-----

LINKED_LIBS = -lft -lmlx -lm -lX11 -lXext
LINKED_LIBS_DIR = -L./$(LIB_DIR)/libft -L./$(LIB_DIR)/minilibx


#	-----MANDATORY PART BUILD-----

.PHONY: all
all: $(OBJ_DIR) libft minilibx $(NAME)
	@echo "\033[1;32m\t- cub3D build successfully\033[0m"

$(NAME): $(OBJ_ALL)
	@$(CC) $(FLAGS) $(addprefix -I, $(INCLUDES_DIR)) $(OBJ_ALL) $(LINKED_LIBS_DIR) $(LINKED_LIBS) -o $@ 

$(OBJ_ALL): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLLUDES)
	@$(CC) $(FLAGS) -c $(addprefix -I, $(INCLUDES_DIR)) $< $(LINKED_LIBS_DIR) $(LINKED_LIBS) -o $@

$(OBJ_DIR):
	@mkdir $@ $@/$(DIR_PARSE) $@/$(DIR_INIT) $@/$(DIR_GAME) $@/$(DIR_WINDOW)


#	-----BONUS PART BUILD-----

.PHONY: bonus
bonus: $(OBJ_B_DIR) libft minilibx $(NAME_B)
	@echo "\033[1;32m\t- cub3D bonus build successfully\033[0m"

$(NAME_B): $(OBJ_B_ALL)
	@$(CC) $(FLAGS) $(addprefix -I, $(INCLUDES_B_DIR)) $(OBJ_B_ALL) $(LINKED_LIBS_DIR) $(LINKED_LIBS) -o $(NAME)

$(OBJ_B_ALL): $(OBJ_B_DIR)/%.o: $(SRC_B_DIR)/%.c $(INCLUDES_B)
	@$(CC) $(FLAGS) -c $(addprefix -I, $(INCLUDES_B_DIR)) $< $(LINKED_LIBS_DIR) $(LINKED_LIBS) -o $@

$(OBJ_B_DIR):
	@mkdir $@ $@/$(DIR_B_PARSE) $@/$(DIR_B_INIT) $@/$(DIR_B_GAME) $@/$(DIR_B_WINDOW)\
			$@/$(DIR_B_TEXTURES) $@/$(DIR_B_INTERACTIONS)


#	-----LIBS AND OTHER RULES-----

.PHONY: minilibx
minilibx: $(LIB_DIR)/minilibx
	@$(MAKE) -C $< --no-print-directory --silent
	@echo "\033[1;32m\t- minilibx build successfully\033[0m\n"

.PHONY: libft
libft: $(LIB_DIR)/libft
	@$(MAKE) -C $< --no-print-directory --silent
	@echo "\033[1;32m\t- libft build successfully\033[0m\n"

.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR) $(OBJ_B_DIR)
	@$(MAKE) -C $(LIB_DIR)/libft --no-print-directory --silent clean
	@echo "\033[1;32m\t- libft cleaned\033[0m\n"
	@$(MAKE) -C $(LIB_DIR)/minilibx --no-print-directory --silent clean
	@echo "\033[1;32m\t- minilibx cleaned\033[0m\n"

.PHONY: fclean
fclean: clean
	@rm -rf $(NAME) $(NAME_B)
	@rm -rf *.bmp
	@$(MAKE) -C $(LIB_DIR)/libft --no-print-directory --silent fclean
	@echo "\033[1;32m\t- libft fcleaned\033[0m\n"

.PHONY: re
re: fclean all

.PHONY: test
test:
	@echo "$(SRC_B_ALL)"

