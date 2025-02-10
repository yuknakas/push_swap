# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 10:56:54 by yuknakas          #+#    #+#              #
#    Updated: 2025/02/10 14:50:31 by yuknakas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#% cc ./01_srcs/* ./02_preparation/* ./04_swap/*.c ./03_set_cost/*.c ./BON_01_Checker/*.c ./errors/testers.c  -L./libft -lft -o push_swap#

CCW		=	cc -Wall -Wextra -Werror
RMFLAG	=	rm -rf
NAME	=	push_swap
BON_NAME=	checker

SRCS	=	01_srcs/01_main.c 01_srcs/02_push_swap.c 01_srcs/03_swap_3.c 01_srcs/04_swap_5.c \
			01_srcs/05_swap_100.c 01_srcs/06_swap_500.c 01_srcs/10_greatest_arr.c \
			01_srcs/11_find_node.c  01_srcs/12_find_max_min.c  01_srcs/13_cleaner.c \
			01_srcs/14_fix_top.c
PREP	=	02_preparation/01_ps_preparation.c 02_preparation/02_split_stack.c \
			02_preparation/03_make_stack.c 02_preparation/10_ps_lst_1.c \
			02_preparation/11_ps_lst_2.c 02_preparation/12_free_char_dp.c
COST	=	03_set_cost/01_self_cost.c 03_set_cost/02_target_cost.c \
			03_set_cost/04_add_cost.c 03_set_cost/05_cost_combinations.c
SWAP	=	04_swap/00_set_stack_b.c 04_swap/01_set_big_stack_b.c \
			04_swap/02_set_big_b_2.c 04_swap/03_cheapest_node.c 04_swap/04_execute_min.c \
			04_swap/05_checker.c 04_swap/10_operation_1.c 04_swap/11_operation_2.c \
			04_swap/12_operation_3.c
BON		=	10_bonus/01_main.c 10_bonus/02_exec_input.c
BON_UTIL=	01_srcs/13_cleaner.c $(PREP) 04_swap/05_checker.c 04_swap/10_operation_1.c \
			04_swap/11_operation_2.c 04_swap/12_operation_3.c

ALL_SRCS=	$(SRCS) $(PREP) $(COST) $(SWAP)
BON_SRCS=	$(BON) $(BON_UTIL)
OBJS	=	$(ALL_SRCS:.c=.o)
BON_OBJS=	$(BON_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) libft -C ./00_libft
	@$(CCW) $(OBJS) -L./00_libft -lft -o $(NAME)
	@echo "> make push_swap executed in current directory"

%.o: %.c
	@$(CCW) -c $< -o $@

bonus: $(BON_NAME)

$(BON_NAME): $(BON_OBJS)
	@$(MAKE) gnl -C ./00_libft
	@$(CCW) $(BON_OBJS) -L./00_libft -lgnl -lft -o $(BON_NAME)
	@echo "> make bonus_checker executed in current directory"

clean:
	@$(MAKE) clean -C ./00_libft
	@$(RMFLAG) $(OBJS) $(BON_OBJS)
	@echo "> make clean executed in current directory"

fclean: clean
	@$(MAKE) fclean -C ./00_libft
	@$(RMFLAG) $(NAME) $(BON_NAME)
	@echo "> make fclean executed in current directory"

re: fclean all

.PHONY: all bonus clean fclean re