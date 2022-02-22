# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 20:29:07 by nomargen          #+#    #+#              #
#    Updated: 2022/02/22 20:21:58 by nomargen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		=	fractol

CC			=	cc

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	$(wildcard  src/*.c)

SRC_BONUS	=	$(wildcard  src/bonus/*.c)

HEAD		=	$(wildcard  inc/*.h)

HEAD_BONUS	=	$(wildcard  inc/bonus/*.h)

OBJ			=	$(SRC:.c=.o)

OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

LIBFT_DIR	=	lib/libft

MLX_DIR		=	lib/libmlx

LIBFT		=	$(addsuffix .a, $(LIBFT_DIR))

MLX			=	$(addsuffix .a, $(MLX_DIR))

RM			=	rm -rf

LDLIBS		=	-lft -lmlx -lXext -lX11 -lm -lz


%.o: %.с  
	$(CC) $(CFLAGS) -c -o $@ $<

all:	$(NAME)

bonus: $(NAME)

$(NAME): $(if $(findstring bonus, $(MAKECMDGOALS)), tmp_b, tmp_m)
	cp $(if $(findstring bonus, $(MAKECMDGOALS)), tmp_b, tmp_m) $(NAME)

tmp_b:  $(HEAD_BONUS)  $(OBJ_BONUS) $(LIBFT) $(MLX)
	$(CC) -o tmp_b $(OBJ_BONUS) -Llib $(LDLIBS)
	$(RM) tmp_m

tmp_m: $(HEAD) $(OBJ) $(LIBFT) $(MLX)
	$(CC) -o tmp_m $(OBJ) -Llib $(LDLIBS)
	$(RM) tmp_b

$(LIBFT): $(LIBFT_DIR)/libft.a
	cp $(LIBFT_DIR)/libft.a $(LIBFT)

$(MLX): $(MLX_DIR)/libmlx.a
	cp $(MLX_DIR)/libmlx.a $(MLX)

$(LIBFT_DIR)/libft.a:
	make --directory=$(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	make --directory=$(MLX_DIR)

lib_clean:
	make --directory=$(LIBFT_DIR) fclean
	$(RM) lib/libmlx.a
	make --directory=$(MLX_DIR) clean
	$(RM) lib/libft.a

fclean: clean
	$(RM) $(NAME)
	$(RM) tmp_m
	$(RM) tmp_b

clean: lib_clean
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)

re: fclean all

.PHONY: all clean fclean lib_clean re