# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omeyer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/02 14:51:42 by omeyer            #+#    #+#              #
#    Updated: 2017/07/02 18:24:30 by omeyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractal

SRC = main.c mandelbrot.c julia.c tricorn.c

OBJ = main.o mandelbrot.o julia.o tricorn.o

FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

FETCHLIB = -L libft/ -lft -I libft/

all: $(NAME)

$(NAME):
	$(MAKE) -C libft/ all
	gcc -o $(NAME) $(SRC) $(FLAGS) $(FETCHLIB)

clean:
	$(MAKE) -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) -C libft/ fclean

re:	fclean all
