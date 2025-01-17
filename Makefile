# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 10:56:54 by yuknakas          #+#    #+#              #
#    Updated: 2025/01/17 11:00:00 by yuknakas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RMFLAG	=	rm -rf
NAME	=	push_swap

SRCS	=	srcs/error_handling.c srcs/main.c srcs/operation_1.c srcs/operation_2.c srcs/operation_3.c  swap_3.c
OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(MAKE) fclean -C ./libft
	$(RMFLAG) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RMFLAG) $(NAME)

re: fclean all

.PHONY: all clean fclean re

ccw ./srcs/* ./make_stack/* -L./libft -lft -o outprogeam      