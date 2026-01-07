# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aielo <aielo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 17:03:34 by aielo             #+#    #+#              #
#    Updated: 2026/01/07 16:49:34 by aielo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIB_DIR = Libft
LIB_NAME = ft
LIB_LIB = $(LIB_DIR)/lib$(LIB_NAME).a
LIB_INC = $(LIB_DIR)

MLX_DIR = mlx_linux

SRC_DIR = src
UTIL_DIR = utils

CC = cc
CFLAGS = -Wall -Wextra -Werror
CEXTRA_INC = -I. -I$(LIB_INC)
CEXTRA_LIB = -L$(LIB_DIR) -l$(LIB_NAME)

SOURCES = cub3d.c

OBJECTS = $(SOURCES:.c=.o)

all: libft mlx_linux $(NAME)

$(NAME): $(LIB_LIB) $(OBJECTS)
	$(CC) -g $(OBJECTS) $(CEXTRA_INC) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(CEXTRA_LIB)

libft:
	$(MAKE) -C $(LIB_DIR)

mlx_linux:
	cd $(MLX_DIR) && chmod 777 configure && cd ..
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(CEXTRA_INC) -I/usr/include -I. -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft mlx_linux
