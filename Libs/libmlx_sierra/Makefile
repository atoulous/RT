# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoulous <atoulous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/04 14:35:32 by atoulous          #+#    #+#              #
#    Updated: 2017/02/04 14:36:00 by atoulous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmlx.a

SRC = mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c \
		mlx_int_str_to_wordtab.c

OBJ1 = $(SRC:.c=.o)

OBJ = $(OBJ1:.m=.o)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32m[OK]\033[0m minilib compiled"

all: $(NAME)

%.o: %.c
	@cc -O2 -o $@ -c $?

%.o: %.m
	@cc -O2 -o $@ -c $?

clean:
	@rm -f $(OBJ) *~
	@rm -f mlx_app

fclean:
	@rm -f $(NAME) $(OBJ) *~
	@rm -f mlx_app

re: clean all
