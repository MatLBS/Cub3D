# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 21:07:58 by matle-br          #+#    #+#              #
#    Updated: 2024/10/22 14:33:13 by matle-br         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

CC = cc
FLAGS = -Wall -Wextra -Werror -O3 -mtune=native -flto
MLX_FLAGS = -L$(PATH_MINILIBX) -lmlx -lX11 -lXext -lm -lz
GREEN = \033[32m
YELLOW = \033[33m
ROUGE = \033[1;31m

SRC_DIR =	src/main.c \
			src/events/events.c \
			src/events/events2.c \
			src/init/init.c \
			src/init/init2.c \
			src/other/free.c \
			src/other/get_next_line.c \
			src/other/images.c \
			src/parsing/check_input.c \
			src/parsing/check_map.c \
			src/parsing/parsing_utils.c \
			src/parsing/parsing_utils2.c \
			src/raycasting/raycasting_utils.c \
			src/raycasting/raycasting_utils2.c \
			src/raycasting/raycasting.c \
			src/raycasting/minimap.c \

LIBFT_A = ./includes/libft/libft.a
PATH_MINILIBX = /home/matle-br/sgoinfre/minilibx-linux

RM = rm -f
# OBJ_DIR = obj_dir
# OBJ = $(SRC_DIR:src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME) : $(LIBFT_A) $(SRC_DIR)
		@$(CC) $(SRC_DIR) $(LIBFT_A) $(FLAGS) $(MLX_FLAGS) -o $(NAME)
		@echo "$(YELLOW)Creating the objects..."
		@echo "$(GREEN)$(NAME) has compiled !"

# $(OBJ_DIR)/%.o: src/%.c
# 	@mkdir -p $(OBJ_DIR)
# 	@$(CC) $(FLAGS) -I$(PATH_MINILIBX) -c $< -o $@

$(LIBFT_A) :
	@echo "$(YELLOW)Libft is compiling..."
	@make bonus --no-print-directory -C ./includes/libft

clean :
	@$(RM) -r $(OBJ_DIR)
	@make clean --no-print-directory -C ./includes/libft

fclean : clean
	@$(RM) $(NAME)
	@make fclean --no-print-directory -C ./includes/libft
	@echo "$(ROUGE)Fclean is running..."

re : fclean all

.PHONY: all clean fclean re
