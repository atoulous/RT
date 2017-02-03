# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 18:40:33 by mmoullec          #+#    #+#              #
#    Updated: 2017/02/02 10:27:59 by mmoullec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmy_mlx.a
CC = clang -Wall -Werror -Wextra
LMLX = -I../libmlx
SRC = hsv_to_grb.c			\
	put_color_to_pixel.c	\
	unsigned_to_rgb.c		\
	glob_init_mlx.c			\
	rgb_to_hsv.c			\
	rgb_mult.c				\
	rgb_add.c				\
	rgb_create.c			\
	rgb_s_mult.c			\
	rgb_reg.c				\
	rgb_percent.c			\
	rgb_0.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $? $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32m[OK]\033[0m libmy_mlx.a created"

%.o: %.c
	@$(CC) $(LMLX) -o $@ -c $< -I.

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[32m[OK]\033[0m libmy_mlx.a: object files deleted"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[32m[OK]\033[0m libmy_mlx.a: library deleted"

re: fclean all

.PHONY: all clean fclean re
