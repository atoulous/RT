# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/16 12:39:53 by mmoullec          #+#    #+#              #
#    Updated: 2017/01/16 12:44:31 by mmoullec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmy_math.a
CC = clang -Wall -Werror -Wextra
SRC = cubic_eq.c\
quartic_solver.c\
my_math1.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "\033[32m[OK]\033[0m $(NAME) created"

%.o: %.c
	@$(CC) -o $@ -c $< -I.

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[32m[OK]\033[0m $(NAME): object files deleted"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[32m[OK]\033[0m $(NAME): libft deleted"

re: fclean all

.PHONY: all clean fclean re
