/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:16:18 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/24 16:17:12 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	if (ps_preparation(argc, argv, &stack_a, &stack_b) != 0)
		return (1);
	ps_push_swap(&stack_a, &stack_b);
	_clean_up(stack_a);

}

//ccw ./srcs/* ./preparation/* ./swap/*.c ./swap/operations/*.c -L./libft -lft -o push_swap
//cc ./01_srcs/* ./02_preparation/* ./04_swap/*.c ./03_set_cost/*.c ./BON_01_Checker/*.c  -L./libft -lft -o push_swap