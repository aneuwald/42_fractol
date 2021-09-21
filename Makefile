# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 19:18:55 by acanterg          #+#    #+#              #
#    Updated: 2021/09/21 01:44:12 by aneuwald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	src/*.c functions/*.c
GCC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
FSANIT  =	-fsanitize=address -g
INCLUD	=	-I includes
NAME	=	fractol
MLX		=	-L mlx -lmlx -framework OpenGL -framework AppKit -O3
MLX_LNX	=	-L minilibx-linux -lmlx -lm -lX11 -lXext -O3

	
all : 		$(NAME)

$(NAME) :
			@ $(GCC) $(CFLAGS) $(FSANIT) -o $(NAME) $(SRC) $(INCLUD) $(MLX_LNX)  

mandelbro	:	re
			./$(NAME) mandelbrot

julia	:	re
			./$(NAME) julia

burningship	:	re
			./$(NAME) burningship

clean :
			@ rm -f $(NAME)

bonus :		all

fclean :	clean

re :		fclean all

.PHONY: 	all clean fclean re test