# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 06:44:41 by matteofilib       #+#    #+#              #
#    Updated: 2022/06/28 11:40:13 by msciacca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS =	main.c \
		utility/console_output.c \
		utility/map_validation.c \
		utility/window.c \
		utility/get_next_line/get_next_line.c \
		utility/get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit
CC = cc

all: mlax $(NAME)
clean:
		rm -rf $(OBJS)
		make -C mlx clean
fclean: clean
		rm -rf $(NAME)
re: fclean all

mlax:
	make -C mlx
.o: .c
		${CC} ${FLAGS} -c $< -o $@
$(NAME): $(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS)

.PHONY = all clean fclean re mlax