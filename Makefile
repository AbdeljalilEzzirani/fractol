# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abez-zir <abez-zir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 18:18:07 by abez-zir          #+#    #+#              #
#    Updated: 2023/06/07 02:36:14 by abez-zir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror 

MLX = -lmlx -framework OpenGL -framework AppKit

NAME = Mandelbrot

SRC = Mandelbrot.c Utils.c main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  $(CFLAGS) -I /usr/local/include -o $(NAME) $(OBJ) -L /usr/local/lib $(MLX)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(OBJ)

re: fclean all



# CC = cc

# CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

# # ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***
# NAME = Mandelbrot

# # ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***
# SRC= Mandelbrot.c Utils.c main.c

# # ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***
# OBJ = $(SRC:.c=.o)

# # ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***
# all: $(NAME)

# $(NAME): $(OBJ)
#     $(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# # ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***
# %.o: %.c fractol.h
#     $(CC) $(CFLAGS) -c $< -o $@

# # ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***
# clean:
#     rm -rf $(OBJ) 

# fclean: clean
#     rm -rf $(NAME) $(OBJ)

# re: fclean all
