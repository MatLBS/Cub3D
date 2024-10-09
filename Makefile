# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 21:07:58 by matle-br          #+#    #+#              #
#    Updated: 2024/10/07 23:26:24 by matle-br         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

CC = cc
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lX11 -lXext -lm -lz
GREEN = \033[32m
YELLOW = \033[33m
ROUGE = \033[1;31m

SRC_DIR =

LIBFT_A = ./includes/libft/libft.a

MLX_DIR = -L/home/matle-br/sgoinfre/minilibx-linux

RM = rm -f

all: $(NAME)

$(NAME) : $(LIBFT_A) $(SRC_DIR)
		@$(CC) $(SRC_DIR) $(LIBFT_A) $(MLX_DIR) $(FLAGS) $(MLX_FLAGS) -o $(NAME)
		@echo "$(GREEN)$(NAME) has compiled !"

$(LIBFT_A) :
	@echo "$(YELLOW)Libft is compiling..."
	@make bonus --no-print-directory -C ./includes/libft

clean :
	@$(RM) $(OBJS)
	@make clean --no-print-directory -C ./includes/libft

fclean : clean
	@$(RM) $(NAME)
	@make fclean --no-print-directory -C ./includes/libft
	@echo "$(ROUGE)Fclean is running..."

re : fclean all

.PHONY: all clean fclean re
