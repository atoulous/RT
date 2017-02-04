# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubarbie <jubarbie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/30 16:51:35 by jubarbie          #+#    #+#              #
#    Updated: 2017/01/23 14:09:02 by atoulous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS =	-I ../libft -Wall -Wextra -Werror
SRC =	v3d.c 			\
		print_v3d.c 	\
		add_v3d.c 		\
		sub_v3d.c 		\
		smul_v3d.c 		\
		dot_v3d.c 		\
		cross_v3d.c 	\
		unit_v3d.c 		\
		length_v3d.c 	\
		cos_v3d.c		\
		rodrigues_rotation.c \
		v4d.c 			\
		translation_pos.c

NAME = libv3d.a
OBJ = $(SRC:.c=.o)

.PHONY: clean

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "\033[32m[OK]\033[0m libv3d.a created"

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@echo "\033[32m[OK]\033[0m libv3d: object files deleted"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[32m[OK]\033[0m libv3d: libft deleted"

re: fclean all
