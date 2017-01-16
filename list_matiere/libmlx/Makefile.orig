# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 18:40:33 by mmoullec          #+#    #+#              #
#    Updated: 2016/12/15 18:12:28 by mmoullec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmy_mlx.a
CC = clang -Wall -Werror -Wextra
LMLX = -I../minilibx_macos
SRC = hsv_to_grb.c\
	put_color_to_pixel.c\
	glob_init_mlx.c\
	rgb_to_hsv.c\
	rgb_mult.c\
	rgb_add.c\
	rgb_create.c\
	rgb_print.c\
	rgb_0.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $? $(OBJ)
	@ranlib $(NAME)
	@echo "Created" $(NAME)

%.o: %.c
	@$(CC) $(LMLX) -o $@ -c $< -I.
	@echo $@ "Created"

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
