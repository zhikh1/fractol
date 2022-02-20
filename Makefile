# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 20:29:07 by nomargen          #+#    #+#              #
#    Updated: 2022/02/20 18:08:17 by nomargen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		=	fractol

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	$(wildcard  src/*.c)

SRC_BONUS	=	$(wildcard  src/bonus/*.c)

OBJ			=	$(SRC:.c=.o)

OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

LIBFT		=	lib/libft

MLX			=	lib/mlx_linux

RM			=	rm -rf

LDLIBS		=	-lft -lmlx -lXext -lX11 -lm -lz

.PHONY:	$(NAME) all bonus clean fclean re

all:	$(NAME) 

$(NAME) : libft mlx $(OBJ)	
	$(CC) -o $(NAME)  $(OBJ) -Llib $(LDLIBS)

bonus: libft mlx $(OBJ_BONUS)	
	$(CC) -o $(NAME)  $(OBJ_BONUS) -Llib $(LDLIBS)

libft:
	make --directory=$(LIBFT)
	cp $(LIBFT)/libft.a lib/libft.a

mlx:
	make --directory=$(MLX)
	cp $(MLX)/libmlx.a lib/libmlx.a

lib_clean:
	make --directory=$(LIBFT) fclean
	$(RM) lib/libmlx.a
	make --directory=$(MLX) clean
	$(RM) lib/libft.a

clean: lib_clean
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all