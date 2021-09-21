# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 19:18:55 by acanterg          #+#    #+#              #
#    Updated: 2021/09/21 07:49:16 by aneuwald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	src/color.c \
			src/draw.c \
			src/fractals.c \
			src/fractals2.c \
			src/init.c \
			src/keys.c \
			src/main.c \
			src/menu.c \
			src/mouse.c \
			src/print.c \
			src/utils.c \
			utils/ft_itoa.c \
			utils/ft_strcmp.c
GCC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
FSANIT  =	-fsanitize=address -g
INCLUD	=	-I includes
NAME	=	fractol
MLX		=	-L mlx -lmlx -lm -framework OpenGL -framework AppKit -O3
RM		=	rm -rf
MAKE	= 	make

all : 		$(NAME)

$(NAME) :	
			@$(MAKE) -C mlx
			@$(GCC) $(CFLAGS) $(FSANIT) $(MLX) -o $(NAME) $(INCLUD) $(SRC) 

norm	:	
			norminette src includes utils
clean:
			@$(MAKE) -C mlx clean

fclean:		clean
			@$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY: 	all clean fclean re norm