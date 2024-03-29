# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 06:44:41 by matteofilib       #+#    #+#              #
#    Updated: 2022/10/08 18:02:20 by msciacca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS =	main.c \
		utility/utilities.c \
		utility/console_output.c \
		utility/map_validation.c \
		utility/get_next_line/get_next_line.c \
		utility/get_next_line/get_next_line_utils.c \
		utility/memory_management.c \
		utility/screen_rendering.c \
		utility/screen_render_utility.c \
		utility/hook.c \
		utility/location_finder.c \
		utility/movement_management.c \
		utility/ft_printf/ft_printf.c \
		utility/ft_printf/ft_printf_utils.c \
		utility/ft_printf/libft/ft_putchar_fd.c \
		utility/ft_printf/libft/ft_putstr_fd.c \
		utility/ft_printf/libft/ft_itoa.c
OBJS = $(SRCS:.c=.o)
FLAGS = -g -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit
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