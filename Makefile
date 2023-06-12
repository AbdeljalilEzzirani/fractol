# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 18:18:07 by abez-zir          #+#    #+#              #
#    Updated: 2023/06/12 14:31:24 by abez-zir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

NAME = Mandelbrot
NAME_Julia = Julia

SRC = Julia.c Mandelbrot.c Utils.c main.c

OBJ = $(SRC:.c=.o)

all: $(NAME) $(NAME_Julia)

$(NAME_Julia): $(OBJ)
	$(CC)  $(CFLAGS) -I /usr/local/include -o $(NAME_Julia) $(OBJ) -L /usr/local/lib $(MLX)
$(NAME): $(OBJ)
	$(CC)  $(CFLAGS) -I /usr/local/include -o $(NAME) $(OBJ) -L /usr/local/lib $(MLX)
	
%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(NAME_Julia)

re: fclean all
