# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 18:44:15 by gschuste          #+#    #+#              #
#    Updated: 2019/02/13 18:34:54 by gdamion-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	srcs/*.c\
		lib/ft_bzero.c\
		lib/ft_putendl.c\
		lib/ft_putstr.c\
		lib/ft_putchar.c\


FLAGS = -Wall -Wextra -Werror

OBJ =	*.o

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc -c -g $(FLAGS) $(SRC)
	@gcc $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
