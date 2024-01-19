# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 10:55:15 by iniska            #+#    #+#              #
#    Updated: 2024/01/09 11:31:09 by iniska           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRC	= \
		main.c \
		stack_it.c sorting.c sort_it.c \
		node_price_a.c node_price_b.c min_n_max.c \
		swappers.c pushers.c \
		rotaters.c rotaters_rev.c rotate_with_median.c \
		clean_n_errors.c

OBJ  = $(SRC:.c=.o)

CC	= cc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I/Users/iniska/my_libft

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(CC) $(CFLAGS) -o push_swap main.c $(NAME) -I/Users/iniska/my_libft -L/Users/iniska/my_libft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
