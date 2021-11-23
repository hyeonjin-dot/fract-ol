# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 15:32:54 by hyejung           #+#    #+#              #
#    Updated: 2021/10/07 15:09:39 by hyejung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

SRCS	=	main.c\
			color.c\
			tool.c\
			draw.c

RM		= rm -f
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

MLX     = ./mlx/
MLX_LNK = -L $(MLX) -l mlx -framework OpenGL -framework AppKit

MLX_INC = -I $(MLX)
MLX_LIB = $(addprefix $(MLX),mlx.a)

all: $(MLX_LIB) $(NAME)

OBJS     = $(SRCS:.c=.o)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME) :	$(OBJS)
	$(CC) $(OBJS) $(MLX_LNK) -lm -o $(NAME)

clean	:
	$(RM) $(OBJS)
	make -C $(MLX) clean	

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
