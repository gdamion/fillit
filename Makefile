# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 18:44:15 by gschuste          #+#    #+#              #
#    Updated: 2019/08/18 18:25:29 by gdamion-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

SRC_DIR = ./src
INC_DIR = ./inc
LIB_DIR = ./libft

INC = -I ./libft/inc -I ./inc

SRC_NAME =	read1.c \
			read2.c \
			process1.c \
			process2.c \
			process3.c

SRC = $(addprefix $(SRC_DIR)/,$(SRC_NAME))
OBJ =	$(SRC_NAME:.c=.o)
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc libft/libft.a $(FLAGS) -c $(SRC) $(INC)
	@echo "$(GREEN)Object files are created!$(RESET)"
	@gcc $(OBJ) -o $(NAME)
	@echo "$(GREEN)./fillit file is created!$(RESET)"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
