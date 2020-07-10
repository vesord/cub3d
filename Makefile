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

OBJ = .

LIB_DIR = libs

.PHONY: all
all: $(NAME)

$(NAME): minilibx libft $(OBJ)

.PHONY: minilibx
minilibx: $(LIB_DIR)/minilibx
	cd $< && make

.PHONY: libft
libft: $(LIB_DIR)/libft
	cd $< && make

.PHONY: clean
clean:
	cd $(LIB_DIR)/libft && make clean
	cd $(LIB_DIR)/minilibx && make clean

.PHONY: fclean
fclean:
	cd $(LIB_DIR)/libft && make fclean
	cd $(LIB_DIR)/minilibx && make fclean

