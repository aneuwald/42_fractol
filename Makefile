# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aneuwald <aneuwald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 19:18:55 by acanterg          #+#    #+#              #
#    Updated: 2021/09/14 05:07:06 by aneuwald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	src/*.c
GCC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
FSANIT  =	-fsanitize=address -g
INCLUD	=	-I includes
NAME	=	fract-ol
MLX		=	-L minilibx-linux -lmlx -lm -lX11 -lXext

	
all : 		$(NAME)

$(NAME) :
			$(GCC) $(CFLAGS) $(FSANIT) -o $(NAME) $(SRC) $(INCLUD) $(MLX)  

test	:	re
			./$(NAME)

clean :
			@ rm -f $(NAME)

bonus :		all

fclean :	clean

re :		fclean all

.PHONY: 	all clean fclean re test