# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 18:44:15 by gschuste          #+#    #+#              #
#    Updated: 2019/02/13 19:58:32 by gdamion-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC_DIR = ./srcs
INC_DIR = ./include
LIB_DIR = ./lib

SRC_NAME =	read1.c\
			read2.c\
			process1.c\
			process2.c\
			process3.c
		
LIB_SRC_NAME	=	ft_bzero.c\
					ft_putendl.c\
					ft_putstr.c\
					ft_putchar.c

SRC = $(addprefix $(SRC_DIR)/,$(SRC_NAME))
LIB_SRC = $(addprefix $(LIB_DIR)/,$(LIB_SRC_NAME))
OBJ =	$(SRC_NAME:.c=.o) $(LIB_SRC_NAME:.c=.o)
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC) $(LIB_SRC)
	@gcc $(OBJ) -o $(NAME)

clean:
	@/bin/Rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
