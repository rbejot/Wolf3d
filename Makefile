# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/07 08:49:43 by rbejot            #+#    #+#              #
#    Updated: 2016/06/09 18:34:44 by rbejot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

LIBPATH = ./libft/
LIBMXPATH = ./minilibx/

LIBS = -L$(LIBMXPATH) -lmlx -framework OpenGL -framework AppKit -L$(LIBPATH) -lft

SRC = color.c	init_env.c	hit.c	draw.c	main.c	calcul.c\
		stock_map.c	usage.c	move.c	read_map.c

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIBPATH)
	@make -C $(LIBMXPATH)
	@$(CC) -c $(SRC)
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)
	@echo compiling...

clean:
	@rm -rf $(OBJ)
	@echo deleting...

fclean:clean
	@rm -f $(NAME)
	@echo deleting...

re: fclean all
