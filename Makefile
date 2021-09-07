# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 15:32:54 by hyejung           #+#    #+#              #
#    Updated: 2021/09/07 14:28:15 by hyejung          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

SRCS	=	main.c\

OBJS	=	$(SRCS:.c=.o)
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -Imlx

.c.o	:
	gcc $(CFLAGS) -I $(INCS) -c $< -o $(<:.c=.o)

$(NAME)	: $(MLX) $(OBJS)

$(MLX)	:
	make -c mlx/
all		:

	gcc -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRCS)
	./a.out

clean	:	

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
