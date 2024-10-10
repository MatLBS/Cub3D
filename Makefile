# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 21:07:58 by matle-br          #+#    #+#              #
#    Updated: 2024/10/10 13:09:23 by matle-br         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

CC = cc
FLAGS = -Wall -Wextra -Werror -g3
MLX_FLAGS = -lmlx -lX11 -lXext -lm -lz
GREEN = \033[32m
YELLOW = \033[33m
ROUGE = \033[1;31m

SRC_DIR = src/main.c src/check_input.c src/parsing_utils.c src/get_next_line.c src/free.c \
			src/parsing_utils2.c src/check_map.c

LIBFT_A = ./includes/libft/libft.a

RM = rm -f
OBJ_DIR = obj_dir
OBJ = $(SRC_DIR:src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME) : $(LIBFT_A) $(SRC_DIR) $(OBJ)
		@$(CC) $(SRC_DIR) $(LIBFT_A) $(FLAGS) -o $(NAME)
		@echo "$(YELLOW)Creating the objects..."
		@echo "$(GREEN)$(NAME) has compiled !"

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

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
