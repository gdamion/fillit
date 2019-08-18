# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 18:44:15 by gschuste          #+#    #+#              #
#    Updated: 2019/08/18 18:58:16 by gdamion-         ###   ########.fr        #
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

SRC =		read1.c \
			read2.c \
			process1.c \
			process2.c \
			process3.c

SRC_D = $(addprefix $(SRC_DIR)/,$(SRC))
OBJ =	$(SRC:.c=.o)
OBJ_D=	$(addprefix obj/,$(OBJ))
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC_D)
	@gcc $(FLAGS) -c $(SRC_D) $(INC)
	@mkdir -p obj/ && mv $(OBJ) obj/
	@echo "$(GREEN)Object files are created!$(RESET)"
	@gcc $(OBJ_D) -o $(NAME) libft/libft.a
	@echo "$(GREEN)./fillit file is created!$(RESET)"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
